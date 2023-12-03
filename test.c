
#include"game.h"
//游戏主题的实现
void game()
{
	char ret=0;
	//创建棋盘雏形（创建一个二维数组）
	char Board[ROW][COL] = { 0 };
    //给数组赋值空格
	InitBoard(Board, ROW, COL);
    //精细化棋盘，并打印
	Dispaly(Board, ROW, COL);
    //下棋
	while (1)
	{
		srand((unsigned int)time(NULL));
		//玩家下棋
		PlayerMove(Board, ROW, COL);
	    Dispaly(Board, ROW, COL);
		//判断输赢
		ret=IsWin(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(Board, ROW, COL);
		Dispaly(Board, ROW, COL);
		//判断输赢
		ret = IsWin(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢!\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢!\n");
	}
	else if (ret == 'Q')
	{
		printf("平局!\n");
	}
	else
		printf("hh\n");
}
//打印页面菜单
void menu()  
{	
	printf("*************************\n");
	printf("****paly(1)   exit(0)****\n");
	printf("*************************\n");
}
void test()
{
	menu();
	int input = 0;
	printf("请选择:>");
	do
	{
	   scanf("%d", &input);
	   switch (input)
	   {
	        case 1:
				system("cls");
			    //界面缓冲优化
				for (int i = 0; i < 2; i++)
				{
					printf("请稍等");
					
					for (int j = 0; j < 3; j++)
					{
						printf(".");
						Sleep(500);
					}
					system("cls");
				}
				printf("游戏开始\n");
				Sleep(1000);
				system("cls");
				game();
				
		        break;
	        case 0:
				printf("退出游戏\n");
		        break;
	        default:
				printf("选择错误，请重新选择！\n");
		        break;
	    }
	 
	}
    while (input);	

}
int main()
{
	
	test();
	return 0;
}