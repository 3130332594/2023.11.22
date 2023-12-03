#include"game.h"
//ʵ�ָ����鸳ֵ�ո�
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
/* ��ӡ����
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
			//��ӡһ�е�����
			printf(" %c ", Board[i][j]);
			//��ӡ�ָ�����
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
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
	printf("�������:>\n");
	while (1)
	{
		printf("��������Ҫ�µ�λ�õ�����(x,y):>");
		scanf("%d,%d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';

				break;
			}
			else
			{
				printf("����Ƿ�������������!\n");
			}
		}
	}
}
void ComputerMove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	printf("��������>\n");
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
//�ж�������û����1���� 0û��
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
	//������
	for (i = 0; i < row; i++)
	{
		if (Board[i][0] == Board[i][1]&& Board[i][1] == Board[i][2] && Board[i][1]!=' ')
		{
			return Board[i][1];
		}
	}
	//������
	int k = 0;
	for (k = 0; k < col; k++)
	{
		if (Board[0][k] == Board[1][k] && Board[1][k]==Board[2][k] && Board[1][k] != ' ')
		{
			return Board[0][k];
		}
	}
	//�����Խ���
	if (Board[0][0] == Board[1][1] && Board[1][1]== Board[2][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}
	if (Board[2][0] == Board[1][1] && Board[1][1]== Board[0][2] && Board[1][1] != ' ')
	{
		return Board[1][1];
	}
	//ƽ�ֺͼ���
	if (IsFull(Board, row, col) == 1)
	{
		return 'Q';
	}
	return 'C';
}