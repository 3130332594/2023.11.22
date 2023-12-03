#include"game.h"
//实现给数组赋值空格
void InitBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			Board[i][j] = ' ';
		}
	}
}
/* 打印棋盘
   ___|___|___
   ___|___|___
   ___|___|___
      |   |    
*/
void Dispaly(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//打印一行的数据
			printf(" %c ", Board[i][j]);
			//打印分割竖线
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		int k = 0;
		if (i < row - 1)
		{
			for (k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)
					printf("|");
			}
			printf("\n");

		}
	}
}
void PlayerMove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家落子:>\n");
	while (1)
	{
		printf("请输入您要下的位置的坐标(x,y):>");
		scanf("%d,%d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';

				break;
			}
			else
			{
				printf("坐标非法，请重新输入!\n");
			}
		}
	}
}
void ComputerMove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	printf("电脑下棋>\n");
	while (1)
	{
		x = rand() % 3+1;
	    y = rand() % 3+1;
		if (Board[x - 1][y - 1] == ' ')
		{
				Board[x - 1][y - 1] = '#';
				break;
		}
	}
}
//判断棋盘满没满：1满了 0没满
int IsFull(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (Board[i][j]== ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (Board[i][0] == Board[i][1]&& Board[i][1] == Board[i][2] && Board[i][1]!=' ')
		{
			return Board[i][1];
		}
	}
	//竖三列
	int k = 0;
	for (k = 0; k < col; k++)
	{
		if (Board[0][k] == Board[1][k] && Board[1][k]==Board[2][k] && Board[1][k] != ' ')
		{
			return Board[0][k];
		}
	}
	//两个对角线
	if (Board[0][0] == Board[1][1] && Board[1][1]== Board[2][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}
	if (Board[2][0] == Board[1][1] && Board[1][1]== Board[0][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}
	//平局和继续
	if (IsFull(Board, row, col) == 1)
	{
		return 'Q';
	}
	return 'C';
}