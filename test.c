
#include"game.h"
//��Ϸ�����ʵ��
void game()
{
	char ret=0;
	//�������̳��Σ�����һ����ά���飩
	char Board[ROW][COL] = { 0 };
    //�����鸳ֵ�ո�
	InitBoard(Board, ROW, COL);
    //��ϸ�����̣�����ӡ
	Dispaly(Board, ROW, COL);
    //����
	while (1)
	{
		srand((unsigned int)time(NULL));
		//�������
		PlayerMove(Board, ROW, COL);
	    Dispaly(Board, ROW, COL);
		//�ж���Ӯ
		ret=IsWin(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(Board, ROW, COL);
		Dispaly(Board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(Board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ!\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ!\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��!\n");
	}
	else
		printf("hh\n");
}
//��ӡҳ��˵�
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
	printf("��ѡ��:>");
	do
	{
	   scanf("%d", &input);
	   switch (input)
	   {
	        case 1:
				system("cls");
			    //���滺���Ż�
				for (int i = 0; i < 2; i++)
				{
					printf("���Ե�");
					
					for (int j = 0; j < 3; j++)
					{
						printf(".");
						Sleep(500);
					}
					system("cls");
				}
				printf("��Ϸ��ʼ\n");
				Sleep(1000);
				system("cls");
				game();
				
		        break;
	        case 0:
				printf("�˳���Ϸ\n");
		        break;
	        default:
				printf("ѡ�����������ѡ��\n");
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