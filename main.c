#include "ClearMine.h"

static void menu()
{
	printf("##########################\n");
	printf("### ��ӭ����ɨ����Ϸ�� ###\n");
	printf("###     1.������Ϸ     ###\n");
	printf("###     2.�˳���Ϸ     ###\n");
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