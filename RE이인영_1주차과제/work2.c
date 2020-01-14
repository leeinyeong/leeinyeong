void myprint(char*buf);
int strlen(char*buf);
void strcpy(char *abc, char *def);
void strcat(char *abc, char *def);
int strcmp(char *abc, char *def);
/*
void myprint(char *)      getchar�� ����Ͽ� �־��� char *�� ����ϸ� �˴ϴ�.
����) myprint("hello");
���) hello
*/

int main()
{
	myprint("hello");
	system("pause");
	return 0;
}
void myprint(char*buf) {
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		putchar(buf[i]);
	}
}
/*
int strlen(char *)      �־��� char *�� ���̸� ��ȯ�ϸ� �˴ϴ�.
����) strlen("hello")
��ȯ��) 5
*/

int main()
{
	int value;

	value = strlen("hello\n");
	printf("���ڿ�����:%d\n", value);
	system("pause");
	return 0;
}
int strlen(char*buf) {
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		putchar(buf[i]);
	}
	return i;
}

/*
void strcpy(char *, char *)   �� ���ڿ��� �� ���ڿ��� ������ �����ϸ� �˴ϴ�.
����) ������ ���� strlen �Լ��� ����� ��
����) char str[100];
		strcpy(str, " hello");
str ��) hello
*/
int main()
{
	char str[100];

	strcpy(str, "hello");

	printf("����� ���ڿ�: %s \n ", str);
	system("pause");
	return 0;
}
int strlen(char*buf) {
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		//putchar(buf[i]);
	}
	return i;
}
void strcpy(char *abc, char *def) {
	int j;

	for (j = 0; j < strlen(def); j++)
	{
		abc[j] = def[j];
	}
	abc[j] = '\0';

}
/*
void strcat(char *, char *)   �� ���ڿ��� �̾ �ϳ��� ���ڿ��� ��ȯ�ϸ� �˴ϴ�. (hint. ���� �迭�� ũ�⸦ �� ���ڿ��� ������ ���̺��� ũ�� �ּ���!)
����) ������ ���� strlen, strcpy �Լ��� ����� ��
����) char str[100] = "hello";
		strcat(str, " world");
str ��)  hello world
*/

int main()
{
	char str[100] = "hello";

	strcat(str, "world");


	//strcpy(str, "hello");

	printf("�� ���ڿ�: %s \n ", str);
	system("pause");
	return 0;
}
int strlen(char*buf) {
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		//putchar(buf[i]);
	}
	return i;
}
void strcpy(char *abc, char *def) {
	int j;

	for (j = 0; j < strlen(def); j++)
	{
		abc[j] = def[j];
	}
	abc[j] = '\0';
}
void strcat(char *abc, char *def) {
	int k;
	int j = 0;

	for (k = strlen(abc); k < strlen(abc) + strlen(def) + 10; k++)
	{
		abc[k] = def[j];
		j++;
	}
	abc[k] = '\0';
}
/*
int strcmp(char *, char *)   �� ���ڿ��� ������������ �����ϸ� �˴ϴ�.
����) ������ ���� strlen �Լ��� ����� ��
����) char str[100];
		strcmp("hello", " hello");
��ȯ��) 0

����) char str[100];
		strcmp("a", " hello");
��ȯ��) 1
*/

int main()
{

	printf("%d", strcmp("hello", "hello"));
	system("pause");
	return 0;
}
int strlen(char*buf) {
	int i;
	for (i = 0; buf[i] != '\0'; i++) {
		//putchar(buf[i]);
	}
	return i;
}
int strcmp(char *abc, char *def) {
	int str1 = strlen(abc);
	int str2 = strlen(def);
	int i;
	for (i = 0; (abc[i] != '\0') || (def[i] != '\0'); i++)
	{
		if (abc[i] == '\0')
		{
			printf("�ռ���:"); return -1;
		}
		else if (def[i] == '\0')
		{
			printf("������:"); return 1;
		}
		else if (str1 == str2 && abc[i] != def[i])
		{
			if (abc[i] > def[i])
			{
				printf("�ռ���:"); return -1;
			}
			else if (abc[i] < def[i])
			{
				printf("������:"); return 1;
			}
		}
		else {
			printf("����:"); return 0;
		}
	}

}
