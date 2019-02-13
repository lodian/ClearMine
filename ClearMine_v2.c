#include "ClearMine.h"

static int GetRandomIndex(int start, int end)//[1,9]
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

static int GetIndexMines(char mine[][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] +
		   mine[x - 1][y + 1] + mine[x][y - 1] +
		   mine[x][y + 1] + mine[x + 1][y - 1] +
		   mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';//数组里面放的是字符，这里结果至少是八个字符0
}

//递归排除周围没有雷的区域
static void NoMine(char mine[][COLS], char show[][COLS], int x, int y)
{
	int ret = GetIndexMines(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if ((x - 1) > 0 && (y - 1) > 0 && (show[x - 1][y - 1] == '*'))
			NoMine(mine, show, x - 1, y - 1);

		if ((x - 1) > 0 && y > 0 && (show[x - 1][y] == '*'))
			NoMine(mine, show, x - 1, y);

		if ((x - 1) > 0 && (y + 1) > 0 && (show[x - 1][y + 1] == '*'))
			NoMine(mine, show, x - 1, y + 1);

		if (x > 0 && (y - 1) > 0 && (show[x][y - 1] == '*'))
			NoMine(mine, show, x, y - 1);

		if (x > 0 && (y + 1) > 0 && (show[x][y + 1] == '*'))
			NoMine(mine, show, x, y + 1);

		if ((x + 1) > 0 && (y - 1) > 0 && (show[x + 1][y - 1] == '*'))
			NoMine(mine, show, x + 1, y - 1);

		if ((x + 1) > 0 && y > 0 && (show[x + 1][y] == '*'))
			NoMine(mine, show, x + 1, y);

		if ((x + 1) > 0 && (y + 1) > 0 && (show[x + 1][y + 1] == '*'))
			NoMine(mine, show, x + 1, y + 1);
	}
	else
		show[x][y] = ret + '0';
}

int IsWin(char show[][COLS], int _rows, int _cols)
{
	int i, j, num = 0;
	for (i = 1; i <= _rows-2; i++)
	{
		for (j = 1; j <= _cols - 2; j++)
		{
			if (show[i][j] == '*')
			{
				num++;
			}
		}
	}
	if (DEFAULT_MINES == num)
		return 1;

	return -1;
}

void PlayGame(char mine[][COLS], char show[][COLS], int _rows, int _cols)
{
	int x, y;
	int is_win = 0;
	while (1)
	{
		system("CLS");//清屏，优化界面显示
		ShowBoard(show, ROWS, COLS);
		printf("Please Enter<rows, cols>:");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= _rows - 2) && (y >= 1 && y <= _cols - 2))
		{
			if (mine[x][y] == '0'&&show[x][y]=='*')
			{
				NoMine(mine, show, x, y);
				ShowBoard(show, ROWS, COLS);
				if (IsWin(show,ROWS,COLS)>0)
				{
					printf("排雷成功！真棒！ \n");
					break;
				}
			}
			else if (mine[x][y] == '1'&&show[x][y] == '*')
			{
				printf("Boom!Game Over!\n");
				break;
			}
			else
			{
				printf("坐标已排除，请重试！\n");
			}
		}
		else
		{
			printf("坐标非法！请重试!\n");
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