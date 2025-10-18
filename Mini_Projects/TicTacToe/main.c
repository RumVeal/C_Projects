#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termio.h>
#define N 5
#define CHECK_HOR(x) (x[0] != ' ' && x[0] == x[2] && x[2] == x[4])  
#define CHECK_VER(x) (a[x] != ' ' && a[x] == c[x] && c[x] == e[x])
#define CHECK_DIAG_MAIN (a[0] != ' ' && a[0] == c[2] && c[2] == e[4])
#define CHECK_DIAG_SEC  (a[4] != ' ' && a[4] == c[2] && c[2] == e[0])
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

void arr_pr(char *a, char *b, char *c, char *d, char *e, int size){
	for (int i = 0; i < size; i++) printf("%c", a[i]); printf("\n");
	for (int i = 0; i < size; i++) printf("%c", b[i]); printf("\n");
	for (int i = 0; i < size; i++) printf("%c", c[i]); printf("\n");
	for (int i = 0; i < size; i++) printf("%c", d[i]); printf("\n");
	for (int i = 0; i < size; i++) printf("%c", e[i]); printf("\n");
}

int check_res(char *a, char *b, char *c, char *d, char *e, int size){
	if (CHECK_HOR(a) || CHECK_HOR(c) || CHECK_HOR(e) || CHECK_VER(0) || CHECK_VER(2) || CHECK_VER(4) || CHECK_DIAG_MAIN || CHECK_DIAG_SEC)
		return 0;
	else 
		return 1;
}

int main(void){
	system("clear");
	char check_num[9];
	char a[N] = {' ','|',' ','|',' '};
	char b[N] = {'-','.','-','.','-'};
	char c[N] = {' ','|',' ','|',' '};
	char d[N] = {'-','.','-','.','-'};
	char e[N] = {' ','|',' ','|',' '};
	char pos_ch;
	int pos_int, count, game = 1, player = 1, len = 0;;


	while(game){
		count = 0;
		printf("Player %d:\n", player);
		arr_pr(a, b, c, d, e, N);
		pos_ch = getch();

		for (int i = 0; i < len; i++){
			if (check_num[i] == pos_ch)
				count++;
		}
		if (count > 0){
			system("clear");
			continue;
		}
		else
			check_num[len++] = pos_ch;

		pos_int = pos_ch - '0';

		if (player == 1){
			player++;
			switch (pos_int){
				case 1: a[0] = 'x'; break;
				case 2: a[2] = 'x'; break;
				case 3: a[4] = 'x'; break;
				case 4: c[0] = 'x'; break;
				case 5: c[2] = 'x'; break;
				case 6: c[4] = 'x'; break;
				case 7: e[0] = 'x'; break;
				case 8: e[2] = 'x'; break;
				case 9: e[4] = 'x'; break;
				default: game = 0;
			}
		} else {
			player--;
			switch (pos_int){
				case 1: a[0] = 'o'; break;
				case 2: a[2] = 'o'; break;
				case 3: a[4] = 'o'; break;
				case 4: c[0] = 'o'; break;
				case 5: c[2] = 'o'; break;
				case 6: c[4] = 'o'; break;
				case 7: e[0] = 'o'; break;
				case 8: e[2] = 'o'; break;
				case 9: e[4] = 'o'; break;
				default: game = 0;
			
			}
		}
		game = check_res(a, b, c, d, e, N);
		if (game == 0){
			system("clear");
			arr_pr(a, b, c, d, e, N);
			if (player == 1)
				player = 2;
			else player = 1;
			printf("Player %d won. Game end.\n", player);
		}
		else if (len == 9){
			game = 0;
			system("clear");
			arr_pr(a, b, c, d, e, N);
			printf("Draw. Game end.\n");
		}
		else
			system("clear");
	}
	return 0;
}
