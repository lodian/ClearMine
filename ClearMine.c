#include "ClearMine.h"

static int GetRandomIndex(int start, int end)//[1,10]
{
	return rand() % (end - start + 1) + start;
}

void SetMines(char mine[][COLS], int _rows, int _cols)
{
	int count = DEFAULT_MINES;
	srand((unsigned long)time(NULL));
	while (count)
	{
		int x = GetRandomIndex(1,_rows-2);
		int y = GetRandomIndex(1,_cols-2);
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void ShowBoard(char show[][COLS], int _rows, int _cols)
{
	printf("   ");
	int i = 1;
	int j = 1;
	for (; i <= _rows-2; i++)
	{
		printf("  %d ", i);
	}
	printf("\n");
	for (j=0; j <= _cols - 2; j++)
	{
		printf("---|");
	}
	printf("\n");
	for (i = 1; i <= _rows - 2; i++)
	{
		printf(" %d |", i);
		for (j = 1; j <= _cols - 2; j++)
		{
			printf(" %c |", show[i][j]);
		}
		printf("\n");
		printf("   |", i);
		for (j = 1; j <= _cols-2; j++)
		{
			printf("---|");
		}
		printf("\n");
	}
}

int GetIndexMines(char mine[][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] +
		   mine[x - 1][y + 1] + mine[x][y - 1] +
		   mine[x][y + 1] + mine[x + 1][y - 1] +
		   mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';//数组里面放的是字符，这里结果至少是八个字符0
}

void PlayGame(char mine[][COLS], char show[][COLS], int _rows, int _cols)
{
	int x, y;
	int is_win = 0;
	ShowBoard(show, ROWS, COLS);
	//ShowBoard(mine, ROWS, COLS);
	while (1)
	{
		printf("Please Enter<rows, cols>:");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= _rows - 2) && (y >= 1 && y <= _cols - 2))
		{
			if (mine[x][y] == '0')
			{
				int num = GetIndexMines(mine, x, y);
				show[x][y] = num+'0';
				is_win++;
				ShowBoard(show, ROWS, COLS);
				if ((_rows - 2)*(_cols - 2) - is_win == DEFAULT_MINES)//总的个数减已经排除掉的位置等于雷数
				{
					printf("You Win :) \n");
					break;
				}
			}
			else
			{
				printf("Boom!Game Over!\n");
				break;
			}
		}
		else
		{
			printf("Invalid Index, Try Again!\n");
		}
	}
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	memset(mine, '0', sizeof(mine));
	memset(show, '*', sizeof(show));
	SetMines(mine, ROWS, COLS);
	PlayGame(mine, show, ROWS, COLS);
}