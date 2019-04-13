#include <iostream>
#include <stdio.h>
#include <list>
#include <string>
#include <inttypes.h>


struct TimeSegment{
	uint64_t btime;
	uint64_t etime;
	TimeSegment() : btime(0), etime(0){
	}
	TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_){
	}
};


inline void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment>& lstTimeSegment){
	// TODO
	for (auto it = lstTimeSegment.begin(); it != lstTimeSegment.end();) {
		if (it->btime < nBeginTime && it->etime < nBeginTime)
		{
			it++;
		}
		else
		{
			if (it->btime >= nBeginTime)
			{
				it->btime = nBeginTime;
			}
			if (it->etime <= nEndTime)
			{
				it->etime = nEndTime;
			}
			break;
		}
	}
	for (auto it = lstTimeSegment.begin(); it != lstTimeSegment.end();) {
		auto itt = it;
		it++;
		if (it != lstTimeSegment.end())
		{
			if (itt->etime >= it->btime)
			{
				if (itt->etime <= it->etime)
				{
					itt->etime = it->etime;
				}
				it = itt;
				itt++;
				lstTimeSegment.erase(itt);
			}
		}
	}
}

TimeSegment ParseTimeSegmentString(const std::string& input){
	TimeSegment timestamp;
	size_t nPos = input.find("-");
	size_t nLength = input.length();
	if (nPos > 0 && nPos < nLength){
		try{
			timestamp.btime = std::stoull(input.substr(0, nPos));
			timestamp.etime = std::stoull(input.substr(nPos + 1, nLength));
		}
		catch (...){
			std::cout << "请输入有效数据.\n";
		}
	}
	else{
		std::cout << "请输入有效数据.\n";
	}

	return timestamp;
}

std::list<TimeSegment> ParseTimeSegmentList(const std::string& input){
	TimeSegment timestamp;
	std::list<TimeSegment> lstTimestamp;
	std::string temp;
	size_t nStartPos = 0;
	size_t nEndPos = input.find(",");
	size_t nLength = input.length();
	while (nEndPos > nStartPos && nEndPos <= nLength){
		temp = input.substr(nStartPos, nEndPos);
		if (temp.size() > 0){
			timestamp = ParseTimeSegmentString(temp);
			lstTimestamp.push_back(timestamp);
		}
		nStartPos = nEndPos + 1;
		nEndPos = input.find(",", nStartPos);
		if (-1 == nEndPos){
			nEndPos = nLength;
		}
	}

	return lstTimestamp;
}

int main(int argc, char *argv[]) {
	std::string input;
	std::cin >> input;
	int nPos = input.find(";");
	std::list<TimeSegment> lstTimestamp = ParseTimeSegmentList(input.substr(0, nPos));
	TimeSegment timestamp = ParseTimeSegmentString(input.substr(nPos + 1, input.size()));

	MergeTimeSegment(timestamp.btime, timestamp.etime, lstTimestamp);

	for (auto it = lstTimestamp.begin(); it != lstTimestamp.end();) {
		std::cout << it->btime << "-" << it->etime;
		if (++it != lstTimestamp.end()){
			std::cout << ",";
		}
	}
	system("pause");
	return 0;
}