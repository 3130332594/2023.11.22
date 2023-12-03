#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//∂®“Â
void InitBoard(char Board[ROW][COL], int row, int col);
void Dispaly(char Board[ROW][COL], int row, int col);
void PlayerMove(char Board[ROW][COL], int row, int col);
void ComputerMove(char Board[ROW][COL], int row, int col);
int IsFull(char Board[ROW][COL], int row, int col);
char IsWin(char Board[ROW][COL], int row, int col);
