void myprint(char*buf);
int strlen(char*buf);
void strcpy(char *abc, char *def);
void strcat(char *abc, char *def);
int strcmp(char *abc, char *def);
/*
void myprint(char *)      getchar를 사용하여 주어진 char *를 출력하면 됩니다.
예시) myprint("hello");
출력) hello
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
int strlen(char *)      주어진 char *의 길이를 반환하면 됩니다.
예시) strlen("hello")
반환값) 5
*/

int main()
{
	int value;

	value = strlen("hello\n");
	printf("문자열길이:%d\n", value);
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
void strcpy(char *, char *)   앞 문자열에 뒷 문자열의 내용을 복사하면 됩니다.
조건) 위에서 만든 strlen 함수를 사용할 것
예시) char str[100];
		strcpy(str, " hello");
str 값) hello
*/
int main()
{
	char str[100];

	strcpy(str, "hello");

	printf("복사된 문자열: %s \n ", str);
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
void strcat(char *, char *)   두 문자열을 이어서 하나의 문자열을 반환하면 됩니다. (hint. 앞쪽 배열의 크기를 두 문자열이 합해진 길이보다 크게 주세요!)
조건) 위에서 만든 strlen, strcpy 함수를 사용할 것
예시) char str[100] = "hello";
		strcat(str, " world");
str 값)  hello world
*/

int main()
{
	char str[100] = "hello";

	strcat(str, "world");


	//strcpy(str, "hello");

	printf("총 문자열: %s \n ", str);
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
int strcmp(char *, char *)   두 문자열을 내림차순으로 정렬하면 됩니다.
조건) 위에서 만든 strlen 함수를 사용할 것
예시) char str[100];
		strcmp("hello", " hello");
반환값) 0

예시) char str[100];
		strcmp("a", " hello");
반환값) 1
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
			printf("앞선다:"); return -1;
		}
		else if (def[i] == '\0')
		{
			printf("뒤진다:"); return 1;
		}
		else if (str1 == str2 && abc[i] != def[i])
		{
			if (abc[i] > def[i])
			{
				printf("앞선다:"); return -1;
			}
			else if (abc[i] < def[i])
			{
				printf("뒤진다:"); return 1;
			}
		}
		else {
			printf("같다:"); return 0;
		}
	}

}
