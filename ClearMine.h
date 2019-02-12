#ifndef _CLEARMINE_H_
#define _CLEARMINE_H_

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

#define ROWS 11
#define COLS 11
#define DEFAULT_MINES 10

void SetMines(char mine[][COLS], int _rows, int _cols);
void ShowBoard(char show[][COLS], int _rows, int _cols);
void PlayGame(char mine[][COLS], char show[][COLS], int _rows, int _cols);
int GetIndexMines(char mine[][COLS], int _x, int _y);
void game();


#endif