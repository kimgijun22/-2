#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

//파라미터
#define LEN_MIN 15  //기차 길이
#define LEN_MAX 50
#define STM_MIN 0  //마동석 체력
#define STM_MAX 5 
#define PROB_MIN 10 //확률
#define PROB_MAX 90
#define AGGRO_MIN 0 //어그로 범위
#define AGGRO_MAX 5

//마동석 집의 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

// 좀비의 공격대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

//마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

int get_train_length() {//열차 길이 출력
	int len;
	printf("train length(%d~%d)>>", LEN_MIN, LEN_MAX);
	scanf_s("%d", &len);
	if (len > LEN_MIN || len < LEN_MAX) {

	}
	return len;
}
int get_madongseokstamina() {//마동석 체력 설정
	int stm;
	printf("madongseokstamina(%d~%d)>>", STM_MIN, STM_MAX);
	scanf_s("%d", &stm);
	if (stm > STM_MIN || stm < STM_MAX) {

	}
	return stm;
}
int get_percentile_probability() {//확률 설정
	int p;
	printf("percentile probability ‘p’(%d~%d)>>", PROB_MIN, PROB_MAX);
	scanf_s("%d", &p);
	return p;
}

void print_train(int n, int C, int M, int Z) {
	// 상단 경계 출력
	for (int i = 0; i < n; i++) {
		printf("#");
	}
	printf("\n#");

	// 내부 내용 출력
	for (int i = 1; i < n; i++) {
		if (i == C) {
			printf("C");
		}
		else if (i == Z) {
			printf("Z");
		}
		else if (i == M) {
			printf("M");
		}
		else if (i == n - 1) {
			printf("#");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");

	// 하단 경계 출력
	for (int i = 0; i < n; i++) {
		printf("#");
	}
	printf("\n");
}

void move_citizen(int* C, int p, int *aggro) {//시민 이동
	int r = rand() % 100 + 1;
	if (*aggro > AGGRO_MIN || *aggro < AGGRO_MAX) {
		if (r >= p) {
			if (*C > 1) {
				*C -= 1;
				*aggro += 1;
			}
			printf("citizen %d->%d(aggro:%d -> %d)\n", *C + 1, *C, *aggro,*aggro+1); //시민이 이동할때
		}
		else {
			printf("citizen stay %d (aggro:%d->aggro:%d)\n", *C,*aggro,*aggro-1);//시민이 이동 안할때
		}
	}
}
void move_zomble(int*Z,int p,int *turn) {
	int k = rand() % 100+1;
	if (k >= p) {
		if (*turn % 2 == 0) {//2턴 마다 좀비 이동

			*Z -= 1;

			printf("zomble %d->%d\n", *Z + 1, *Z);//좀비가 움직일때
		}
			else {
				printf("zomble stay %d\n", *Z);//좀비가 안움직일때
			}
	}(*turn)++;
	}

int get_madongseoks() {
	int a;
	printf("madongseokmove(%d:stay, %d:left)>>", MOVE_STAY, MOVE_LEFT);
	scanf_s("%d", &a);
}

int main(void) {
	srand((unsigned int)time(NULL));
	int stm,p, n, C, M, Z,aggro=0,a,turn=0;
	n = get_train_length();
	stm = get_madongseokstamina();
	p = get_percentile_probability();
	C = n - 6; M = n - 2; Z = n - 3;
	while (1) {
		print_train(n, C, M, Z);
		move_citizen(&C, p, &aggro);
		move_zomble(&Z, p, turn);
		a = get_madongseoks();
	}
		return 0;
	}
