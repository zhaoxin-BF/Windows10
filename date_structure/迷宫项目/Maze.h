#ifndef __Maze_h_
#define __Maze_h_

#include"Stack.h"

#define N 6
static int maze[N][N] = {
	{0,0,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,1,0,0,0},
	{0,0,1,1,1,0},
	{0,0,1,0,1,1},
	{0,0,1,0,0,0},
};



int GetMazePath(Pos entry, Pos exit);
void PrintMaze();

#endif

int GetMazePath(Pos entry, Pos exit)
{
	Stack st;
	InitStack(&st);

	maze[entry._col][entry._row] = 2;
	PushbackStack(&st, entry);

	while ((maze[entry._col][entry._row] == 1 || maze[entry._col][entry._row] ==2)
		   && (0 < entry._col && entry._col < N && 0 < entry._row && entry._row < N))
	{
		//вС
		if (maze[entry._col][entry._row - 1] == 1)
		{
			entry._row -= 1;
			maze[entry._col][entry._row] = 2;
			PushbackStack(&st,entry);
			continue;
		}
		//ио
		if (maze[entry._col - 1][entry._row] == 1)
		{
			entry._col -= 1;
			maze[entry._col][entry._row] = 2;
			PushbackStack(&st,entry);
			continue;
		}
		//ср
		if (maze[entry._col][entry._row + 1] == 1)
		{
			entry._row += 1;
			maze[entry._col][entry._row] = 2;
			PushbackStack(&st, entry);
			continue;
		}
		//об
		if (maze[entry._col + 1][entry._row] == 1)
		{
			entry._col += 1;
			maze[entry._col][entry._row] = 2;
			PushbackStack(&st, entry);
			continue;
		}

		if (entry._col == exit._col &&entry._row == exit._row )
		{
			return 1;
		}
		entry = StackTop(&st);
		PopbackStack(&st);
	}
	return 0;
}


void PrintMaze()
{
	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d  ",maze[i][j]);
		}
		printf("\n");
	}
}