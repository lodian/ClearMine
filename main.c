#include "ClearMine.h"

static void menu()
{
	printf("##########################\n");
	printf("### 欢迎来到扫雷游戏！ ###\n");
	printf("###     1.进入游戏     ###\n");
	printf("###     2.退出游戏     ###\n");
	printf("##########################\n");
	printf("Please Select:");
}

int main()
{
	int select = 0;
	menu();
	scanf("%d", &select);
	switch (select){
	case 1:
		game();
		break;
	case 2:
		exit(0);
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}