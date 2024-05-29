#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

//�Ķ����
#define LEN_MIN 15  //���� ����
#define LEN_MAX 50
#define STM_MIN 0  //������ ü��
#define STM_MAX 5 
#define PROB_MIN 10 //Ȯ��
#define PROB_MAX 90
#define AGGRO_MIN 0 //��׷� ����
#define AGGRO_MAX 5

//������ ���� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0

// ������ ���ݴ��
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

//������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

int get_train_length() {//���� ���� ���
	int len;
	printf("train length(%d~%d)>>", LEN_MIN, LEN_MAX);
	scanf_s("%d", &len);
	if (len > LEN_MIN || len < LEN_MAX) {

	}
	return len;
}
int get_madongseokstamina() {//������ ü�� ����
	int stm;
	printf("madongseokstamina(%d~%d)>>", STM_MIN, STM_MAX);
	scanf_s("%d", &stm);
	if (stm > STM_MIN || stm < STM_MAX) {

	}
	return stm;
}
int get_percentile_probability() {//Ȯ�� ����
	int p;
	printf("percentile probability ��p��(%d~%d)>>", PROB_MIN, PROB_MAX);
	scanf_s("%d", &p);
	return p;
}

void print_train(int n, int C, int M, int Z) {
	// ��� ��� ���
	for (int i = 0; i < n; i++) {
		printf("#");
	}
	printf("\n#");

	// ���� ���� ���
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

	// �ϴ� ��� ���
	for (int i = 0; i < n; i++) {
		printf("#");
	}
	printf("\n");
}

void move_citizen(int* C, int p, int *aggro) {//�ù� �̵�
	int r = rand() % 100 + 1;
	if (*aggro > AGGRO_MIN || *aggro < AGGRO_MAX) {
		if (r >= p) {
			if (*C > 1) {
				*C -= 1;
				*aggro += 1;
			}
			printf("citizen %d->%d(aggro:%d -> %d)\n", *C + 1, *C, *aggro,*aggro+1); //�ù��� �̵��Ҷ�
		}
		else {
			printf("citizen stay %d (aggro:%d->aggro:%d)\n", *C,*aggro,*aggro-1);//�ù��� �̵� ���Ҷ�
		}
	}
}
void move_zomble(int*Z,int p,int *turn) {
	int k = rand() % 100+1;
	if (k >= p) {
		if (*turn % 2 == 0) {//2�� ���� ���� �̵�

			*Z -= 1;

			printf("zomble %d->%d\n", *Z + 1, *Z);//���� �����϶�
		}
			else {
				printf("zomble stay %d\n", *Z);//���� �ȿ����϶�
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
