#include <stdio.h>
int main(void){
	int quest, ent_num1, ent_num2;
	int	rev_two_num=0, res_num1=0, res_num2=0, res_num=0, res_sum=0, count=1;
	int	two_num, check_res_sum, save_res_sum;
	printf ("1. Binary Converter     2. Binary Adder     3. Binary Subtractor\n\n");
	printf("Choose a number: ");
	scanf("%d", &quest);
	switch (quest){
		case 1:    //이진수 변환기
			printf("Enter an 8-bit binary number: ");
			scanf("%d", &ent_num1);
			for (int i=0; i <= 7; i++){
				res_num += (ent_num1 % 10) * count;
				count *= 2;
				ent_num1 /= 10;
			}
			if (res_num > 127)
				res_num -= 256;
    		printf("It is %d in decimal.\n", res_num);
			break;
		case 2:    //이진수 덧셈기
			printf("Enter the first 8-bit binary number: ");
			scanf("%d", &ent_num1);
			printf("Enter the second 8-bit binary number: ");
			scanf("%d", &ent_num2);
			for (int i=0; i<=7; i++){
				res_num1 += ent_num1%10 * count;
				res_num2 += ent_num2%10 * count;
				count *= 2;
				ent_num1 = ent_num1 / 10;
				ent_num2 = ent_num2 / 10;
			}
			res_sum = res_num1 + res_num2;
			count = 1;
			for (int i = 0; i < 8; i++){
				two_num = res_sum %2;
				rev_two_num += two_num * count;
				count *= 10;
				res_sum = res_sum / 2;

			}
			if (res_num1 > 127) res_num1 -= 256;
			if (res_num2 > 127) res_num2 -= 256;
			check_res_sum = res_num1 + res_num2;
			if (check_res_sum > 127) check_res_sum -= 256;
			else if (check_res_sum < -128) check_res_sum += 256;
			printf("The result is %08d in binary and ", rev_two_num);
			printf("%d in decimal.\n", check_res_sum);
			break;
		case 3:    //이진수 뺄셈
			printf("Enter the first 8-bit binary number: ");
            scanf("%d", &ent_num1);
            printf("Enter the second 8-bit binary number: ");
            scanf("%d", &ent_num2);
            for (int i=0; i<=7; i++){
				res_num1 += ent_num1%10 * count;
                res_num2 += ent_num2%10 * count;
                count *= 2;
                ent_num1 = ent_num1 / 10;
                ent_num2 = ent_num2 / 10;
            }
			if (res_num1 > 127) res_num1 -= 256;
			if (res_num2 > 127) res_num2 -= 256;
            res_sum = res_num1 - res_num2;
			if (res_sum > 127) res_sum -= 256;
			else if (res_sum < -128) res_sum += 256;
			save_res_sum = res_sum;
			if (res_sum < 0) res_sum += 256;
            count = 1;
            for (int i = 0; i < 8; i++){
                two_num = res_sum % 2;
                rev_two_num += two_num * count;
                count *= 10;
                res_sum = res_sum / 2;
 
            }
            printf("The result is %08d in binary and ", rev_two_num);
			printf("%d in decimal.\n", save_res_sum);
			break;
		default:
			printf("You entered a wrong number. Only 1, 2, or 3 are allowed.");
	}	
	return 0;
}
