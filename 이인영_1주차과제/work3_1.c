#include<stdlib.h>
#include<stdio.h>
int main() {
	int result = 0, price = 0;
	int changevalue, change, value = 0;
	int num[5] = { 500,100,50,10,1 };

	printf("���� ������ �Է��ϼ���:");
	scanf("%d", &price);
	change = 1000 - price;

	for (int i = 0; i < 5; i++)
	{
		if ((change / num[i]) >= 1)
		{
			
			value = change / num[i];
			changevalue = change - (num[i] * value);
			change = changevalue;
			result += value;
			value = 0;
		}
	}
	printf("�ּ� �ܵ� ����:%d", result);
	system("pause");
	return 0;
}