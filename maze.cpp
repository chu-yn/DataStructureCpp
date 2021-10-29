#include <iostream>
using namespace std;
#define mazesize 10

class Mouse
{
public:
	int starti, startj;
	int endi, endj;
	void setstart(int i, int j)
	{
		starti = i;
		startj = j;
	}
	void setend(int i, int j)
	{
		endi = i;
		endj = j;
	}

	void go(int maze[mazesize][mazesize])
	{
		visit(maze, starti, startj);
	}

	void visit(int maze[mazesize][mazesize], int i, int j)
	{
		maze[i][j] = 2;
		if (i == endi && j == endj)
		{
			cout << "找到出口\n";
			for (int m = 0; m < mazesize; m++)
			{
				cout << "\t";
				for (int n = 0; n < mazesize; n++)
				{
					if (maze[m][n] == 1)
						cout << "█";
					else if (maze[m][n] == 2)
						cout << "@";
					else
						cout << " ";
				}
				cout << "\n";
			}
		}
		if (maze[i][j + 1] == 0)
			visit(maze, i, j + 1);
		if (maze[i + 1][j] == 0)
			visit(maze, i + 1, j);
		if (maze[i][j - 1] == 0)
			visit(maze, i, j - 1);
		if (maze[i - 1][j] == 0)
			visit(maze, i - 1, j);

		maze[i][j] = 0;
	}
};
int main()
{
	int maze[mazesize][mazesize] =
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
			{1, 1, 0, 1, 0, 1, 0, 0, 1, 1},
			{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
			{1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
			{1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
			{1, 0, 0, 1, 1, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	cout << "\n 顯示迷宮：\n";
	for (int i = 0; i < mazesize; i++)
	{
		cout << "\t";
		for (int j = 0; j < mazesize; j++)
		{
			if (maze[i][j] == 1)
				cout << "█";
			else
				cout << " ";
		}
		cout << endl;
	}

	Mouse m;
	m.setstart(1, 1);
	m.setend(mazesize - 2, mazesize - 2);
	m.go(maze);
	return 0;
}
