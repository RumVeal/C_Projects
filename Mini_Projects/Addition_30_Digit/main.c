#include <stdio.h>

int trans_num(int c){
    int count = 0;
    for (int i = 48; i < 58; i++){
        if (c == i)
            return count;
        else count++;
    }
}


void print_res(unsigned long long int sum1, unsigned long long int sum2, unsigned long long int sum3) {
    int count = 0;
    unsigned long long int div = 1000000000ULL;

    for (int i = 0; i < 10; i++) {
        unsigned long long int d = sum1 / div;
        printf("%llu", d);
        sum1 %= div;
        div /= 10;
        count++;
        if (count % 3 == 0 && count < 30) printf(",");
    }

    div = 1000000000ULL;
    for (int i = 0; i < 10; i++) {
        unsigned long long int d = sum2 / div;
        printf("%llu", d);
        sum2 %= div;
        div /= 10;
        count++;
        if (count % 3 == 0 && count < 30) printf(",");
    }

    div = 1000000000ULL;
    for (int i = 0; i < 10; i++) {
        unsigned long long int d = sum3 / div;
        printf("%llu", d);
        sum3 %= div;
        div /= 10;
        count++;
        if (count % 3 == 0 && count < 30) printf(",");
    }
    printf("\n");
}

int main(void){
    int c, count = 0, tr_c;
    unsigned long long int a1=0, a2=0, a3=0;
    unsigned long long int b1=0, b2=0, b3=0;
    unsigned long long int sum1=0, sum2=0, sum3=0;
    _Bool game = 1, check; 
	char again;
    count = 0;
	while (game){
		check = 0;
		printf("수식 :");
		c = getchar();
		while (c < '0' || c > '9')
			c = getchar();
		a1 = a2 = a3 = 0;
		b1 = b2 = b3 = 0;
		sum1 = sum2 = sum3 = 0;
		count = 0;
    	while ((c >= '0' && c <= '9') && count < 30){
        	tr_c = trans_num(c);
        	if (count < 10) {
            	a3 = a3 * 10 + tr_c;
        	} else if (count < 20) {
            	a2 = a2 * 10 + tr_c;
        	} else {
            	a1 = a1 * 10 + tr_c;
        	}
        	count++;
        	c = getchar();
    	}

    	while (c < 48 || c > 57){
			if ((c != ' ') && (c != '+'))
				check = 1;
        	c = getchar();
    	}

    	count = 0;
    	while ((c >= '0' && c <= '9') && count < 30){
        	tr_c = trans_num(c);
        	if (count < 10) {
            	b3 = b3 * 10 + tr_c;
        	} else if (count < 20) {
            	b2 = b2 * 10 + tr_c;
        	} else {
            	b1 = b1 * 10 + tr_c;
        	}
        	count++;
        	c = getchar();
    	}

    	sum3 = a3 + b3;
    	sum2 = a2 + b2;
    	sum1 = a1 + b1;
	
		if (sum3 >= 10000000000ULL) {
    		sum2 += sum3 / 10000000000ULL;
    		sum3 = sum3 % 10000000000ULL;
		}

		if (sum2 >= 10000000000ULL) {
    		sum1 += sum2 / 10000000000ULL;
    		sum2 = sum2 % 10000000000ULL;
		}
		if (check == 1)
			printf("결과 : 잘못된 연산자입니다.\n");
		else{
			if (sum1 >= 10000000000ULL) {
    			printf("오버플로우가 발생했습니다.\n");
			} else {
				printf("결과:");
    			print_res(sum1, sum2, sum3);
			}
		}
		printf("계속 하시겠습니까? ");
		again = getchar();
		while (getchar() != '\n');

		while ((again != 'y') && (again != 'n')){
			printf("계속 하시겠습니까? ");
			again = getchar();
			while(getchar() != '\n');
		}
		if (again == 'n')
			game = 0;
		printf("\n\n\n\n");
	}
	return 0;
}

