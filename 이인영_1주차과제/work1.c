
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

// 1. 입력된 int count에 대해, 17미만일 경우 “hit”, 21초과인 경우 “bust”, 20일 경우 “split” 을 0이하인 경우 “error”를 그 외에는 “stay”를 출력하는 코드를 작성하시오.//조건문을 사용시 값이 적은 범위부터 
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
// 7. 입력된 count의 주소를 ptr에 복사하여 ptr의 값을 출력하는 코드를 작성하시오. (메인 문 위에 작성)//????
int* ptr;

ptr = &count;
printf("%d", *ptr);

// 8. buf에 입력받은 문자열의 길이만큼 myStrPtr에 메모리를 할당받고, 그 값을 저장하고, myStrPtr을 출력하는 코드를 작성하시오.
   // malloc, strlen, strcpy를 활용하면 할 수 있다.
char buf[MAXBUF];
char* myStrPtr;
scanf("%s", buf);
myStrPtr = (char*)malloc(strlen(buf) + 1);
strcpy(myStrPtr, buf);
printf("%s", myStrPtr);
// 10. 입력된 int number에 대해, 소수라면 "is Prime" 소수가 아니라면 "is not Prime"을 출력하는 코드를 작성하시오.

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
// 11. string.h의 함수를 사용하지 않고, buf에 입력받은 문자열을 복사하고 복사된 copyed를 출력하는 코드를 작성하시오.



int main()
{
	char buf[MAXBUF];
	char copyed[MAXBUF];
	int i;

	printf("문자열 입력하시오.\n");
	scanf("%s", buf);

	for (i = 0; i < MAXBUF; i++)
	{
		copyed[i] = buf[i];

	}
	printf("복사된 copyed: %s \n", copyed);
	system("pause");
	return 0;
}

// 12. N명의 여학생과 M명의 남학생이 주어질 때, 2명의 여학생과 3명의 남학생으로 묶어 만들 수 있는 최대 팀의 갯수를 출력하는 코드를 작성하시오. (baekjoon#2875 참고하여 작성됨)

int main()
{
	int N, M, K;
	int team = 0;
	printf("N명의 여학생,M명의 남학생, K명의 인텁쉽참가생 입력:\n");
	printf(" 조건 : (0 ≤ N ≤ 100), (0 ≤ M ≤ 100), (0 ≤ K ≤ M + N)");
	scanf("%d%d%d", &N, &M, &K);
	while (1)
	{
		N -= 2;
		M--;
		if (N < 0 || M < 0 || M + N < K)
			break;
		team++;
	}
	printf("최대 %d 팀", team);
	system("pause");
	return 0;
}




// 13. 몬스터를 무찌르는 간단한 텍스트 게임이 있다. 아래의 함수 attack, defence, healing 을 구현하시오.(메인 문 아래 작성)


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
	// attack   : 몬스터에게 player의 dmg 만큼 데미지를 준다.
	monster.hp -= player.dmg;
	printf("player attack\n");
}
void defence() {
	// defence  : 몬스터에게 player의 dmg/2 만큼 데미지를 준다.
	monster.hp -= player.dmg / 2;
	printf("player defence\n");
}
void healing() {
	// healing  : player의 hp를 2 회복시킨다.
	player.hp += 2;
	printf("player healing\n");
}