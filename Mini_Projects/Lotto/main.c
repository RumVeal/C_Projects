#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#define N 5
#define M 6
#define L 7
int getch(void) {
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch=getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}
void lotto_game(int num[L], int ticket[N][M], int column, int str){
	int count = 0, count_bon = 0, correct = 0, count_out = 0, flag;
	printf("로또 당첨 결과는 다음과 같습니다.\n\n\n");
	for (int i = 0; i < N; i++){
		flag = 0;
		count_out = 0;
		count = 0;
		count_bon = 0;
		printf("%d 세트 번호 (", i+1);
		for (int j = 0; j < M; j++){
			printf("%d", ticket[i][j]);
			if (j < M-1)
				printf(" ");
			else printf(") -> ");
			for (int k = 0; k < L-1; k++){
				if (ticket[i][j] == num[k])
					count_out++;
			}
		}
		for (int j = 0; j < M; j++){
			correct = 0;
			for (int k = 0; k < L-1; k++){
				if (ticket[i][j] == num[k])
					correct++;
				if ((ticket[i][j] == num[L-1]) && (count_out == 5)){
					correct++;
					count_bon++;
				}
			}
			if (correct > 0){
				printf("%d ", ticket[i][j]);
			}
			else if (correct == 0)
				printf("X ");
		}
		if (count_bon > 0)
			printf(" (2등 당점)\n");
		else if (count_out < 3)
			printf(" (낙첨)\n");
		else if (count_out == 3)
			printf(" (5등 당첨)\n");
		else if (count_out == 4)
			printf(" (4등 당첨)\n");
		else if ((count_out == 5) && (count_bon == 0))
			printf(" (3등 당첨)\n");
		else if (count_out == 6)
			printf (" (1등 당첨)\n");
	}
}
int main(void){
	system("clear");
	char c;
	int num[L];
	int ticket[N][M] = {
		{1, 2, 3, 4, 5, 6},
		{10, 15, 25, 35, 40, 42},
		{1, 9, 11, 22, 23, 25},
		{9, 28, 31, 34, 35, 36},
		{1, 9, 23, 28, 33, 35}
	};
	printf("화면 클리어");
	sleep(1);
	system("clear");
	printf("로또 당첨을 기원합니다.\n프로그램을 로딩 중입니다.\n");
	printf("\n");
	sleep(2);
	system("clear");
	printf("일반 번호를 입력하세요: ");
	for (int i = 0; i < L-1; i++){
		scanf("%d", &num[i]);
	}
	printf("보너스 번호를 입력하세요: ");
	scanf("%d", &num[L-1]);
	sleep(2);
	system("clear");
	lotto_game(num, ticket, N, L);
	printf("\n\n");
	printf("프로그램을 종료하시려면 esc 키를 누르세요.\n");
	getchar();
	c = getch();
	while (c != 27){
		c = getch();
	}
	system("clear");
	return 0;
}
