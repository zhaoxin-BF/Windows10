#include"Maze.h"
int main()
{
	Pos entry;
	Pos exit;
	entry._col = 5;
	entry._row = 2;

	entry._col = 4;
	entry._row = 5;

	printf("%d \n", GetMazePath(entry, exit));

	PrintMaze();
	system("pause");
	return 0;
}