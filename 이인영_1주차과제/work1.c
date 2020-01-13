
#include <stdio.h> 
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <time.h>
#define MAXBUF 256
#define ATTACK 1
#define DEFENCE 2
#define HEALING 3

struct Unit {
	int hp;
	int dmg;
	int action;
} player, monster;

void monsterAI() {
	srand(time(NULL));
	monster.action = (rand() % 3) + 1;
	switch (player.action) {
	case 1:
		if (monster.action == DEFENCE) {
			monster.hp += player.dmg;
		}
	case 3:
		if (monster.action == ATTACK) {
			player.hp -= monster.dmg;
			printf("monster ATTACK !\n");
		}
		else if (monster.action == DEFENCE) {
			player.hp -= monster.dmg / 2;
			printf("monster DEFENCE !\n");
		}
	}
	if (monster.action == HEALING) {
		monster.hp += 1;
		printf("monster HEALING !\n");
	}
}

void attack();
void defence();
void healing();

// 1. �Էµ� int count�� ����, 17�̸��� ��� ��hit��, 21�ʰ��� ��� ��bust��, 20�� ��� ��split�� �� 0������ ��� ��error���� �� �ܿ��� ��stay���� ����ϴ� �ڵ带 �ۼ��Ͻÿ�.//���ǹ��� ���� ���� ���� �������� 
int main()
{
	int count;
	scanf("%d", &count);
	if ((count < 17) && (count >= 0))
	{
		printf("hit\n");
	}
	else if (count > 21)
	{
		printf("bust\n");
	}
	else if (count == 20)
	{
		printf("split\n");
	}
	else if (count <= 0)
	{
		printf("error\n");
	}
	else
		printf("stay\n");
	return 0;
}
// 7. �Էµ� count�� �ּҸ� ptr�� �����Ͽ� ptr�� ���� ����ϴ� �ڵ带 �ۼ��Ͻÿ�. (���� �� ���� �ۼ�)//????
int* ptr;

ptr = &count;
printf("%d", *ptr);

// 8. buf�� �Է¹��� ���ڿ��� ���̸�ŭ myStrPtr�� �޸𸮸� �Ҵ�ް�, �� ���� �����ϰ�, myStrPtr�� ����ϴ� �ڵ带 �ۼ��Ͻÿ�.
   // malloc, strlen, strcpy�� Ȱ���ϸ� �� �� �ִ�.
char buf[MAXBUF];
char* myStrPtr;
scanf("%s", buf);
myStrPtr = (char*)malloc(strlen(buf) + 1);
strcpy(myStrPtr, buf);
printf("%s", myStrPtr);
// 10. �Էµ� int number�� ����, �Ҽ���� "is Prime" �Ҽ��� �ƴ϶�� "is not Prime"�� ����ϴ� �ڵ带 �ۼ��Ͻÿ�.

int main() {
	int number;
	int isPrime = 1;
	int count = 0;
	scanf("%d", &number);

	for (int n = 1; n <= sqrt(number); n++)
	{
		if (number % n == 0)
			count++;
	}
	if (count == 1)
		printf("is Prime\n");
	else
		printf("is not Prime\n");

	return 0;
}
// 11. string.h�� �Լ��� ������� �ʰ�, buf�� �Է¹��� ���ڿ��� �����ϰ� ����� copyed�� ����ϴ� �ڵ带 �ۼ��Ͻÿ�.



int main()
{
	char buf[MAXBUF];
	char copyed[MAXBUF];
	int i;

	printf("���ڿ� �Է��Ͻÿ�.\n");
	scanf("%s", buf);

	for (i = 0; i < MAXBUF; i++)
	{
		copyed[i] = buf[i];

	}
	printf("����� copyed: %s \n", copyed);
	system("pause");
	return 0;
}

// 12. N���� ���л��� M���� ���л��� �־��� ��, 2���� ���л��� 3���� ���л����� ���� ���� �� �ִ� �ִ� ���� ������ ����ϴ� �ڵ带 �ۼ��Ͻÿ�. (baekjoon#2875 �����Ͽ� �ۼ���)

int main()
{
	int N, M, K;
	int team = 0;
	printf("N���� ���л�,M���� ���л�, K���� ���ӽ������� �Է�:\n");
	printf(" ���� : (0 �� N �� 100), (0 �� M �� 100), (0 �� K �� M + N)");
	scanf("%d%d%d", &N, &M, &K);
	while (1)
	{
		N -= 2;
		M--;
		if (N < 0 || M < 0 || M + N < K)
			break;
		team++;
	}
	printf("�ִ� %d ��", team);
	system("pause");
	return 0;
}




// 13. ���͸� ����� ������ �ؽ�Ʈ ������ �ִ�. �Ʒ��� �Լ� attack, defence, healing �� �����Ͻÿ�.(���� �� �Ʒ� �ۼ�)


int main()
{
	player.hp = 22;
	player.dmg = 2;
	monster.hp = 15;
	monster.dmg = 3;
	while (player.hp > 0 && monster.hp > 0) {
		printf("Player [HP: %d / DMG: %d] Monster [HP: %d / DMG: %d]\n", player.hp, player.dmg, monster.hp, monster.dmg);
		printf("choose action[  attack(1)  defence(2)  healing(3)  ]:");
		scanf("%d", &player.action);
		if (player.action == ATTACK) {
			attack();
		}
		else if (player.action == DEFENCE) {
			defence();
		}
		else if (player.action == HEALING) {
			healing();
		}
		else {
			printf("wrong input number...\n");
		}
		monsterAI();
	}
	printf("Game exit\n");



	system("pause");
	return 0;
}
void attack() {
	// attack   : ���Ϳ��� player�� dmg ��ŭ �������� �ش�.
	monster.hp -= player.dmg;
	printf("player attack\n");
}
void defence() {
	// defence  : ���Ϳ��� player�� dmg/2 ��ŭ �������� �ش�.
	monster.hp -= player.dmg / 2;
	printf("player defence\n");
}
void healing() {
	// healing  : player�� hp�� 2 ȸ����Ų��.
	player.hp += 2;
	printf("player healing\n");
}