#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20
#define K 15


typedef struct students{
	char name[K];
	int  id;
	float  height;
}students;


int compare_name(const void *p, const void *q){
	return strcmp(((students *)p)->name, ((students *)q)->name);
}

int compare_id(const void *p, const void *q){
	if (((students *)p)->id > ((students *)q)->id)
		return 1;
	else if (((students *)p)->id < ((students *)q)->id)
		return -1;
	return 0;
}

int compare_height(const void *p, const void *q){
	if (((students *)p)->height < ((students *)q)->height)
		return 1;
	else if (((students *)p)->height > ((students *)q)->height)
		return -1;
	return 0;
}


void pr_by_name(students *ex_st){
	qsort(ex_st, N, sizeof(students), compare_name);
	printf ("\n\n이름       아이디      키\n");
	for (int i = 0; i < N; i++){
		printf("%-10s %-12d %-12.1f\n", ex_st[i].name, ex_st[i].id, ex_st[i].height);
	}
	printf("\n\n");
}

void pr_by_id(students *ex_st){
	qsort(ex_st, N, sizeof(students), compare_id);
	printf ("\n\n이름       아이디      키\n");
	for (int i = 0; i < N; i++){
		printf("%-10s %-12d %-12.1f\n", ex_st[i].name, ex_st[i].id, ex_st[i].height);
	}
	printf("\n\n");
}

void pr_by_height(students *ex_st){
	qsort(ex_st, N, sizeof(students), compare_height);
	printf ("\n\n이름       아이디      키\n");
	for (int i = 0; i < N; i++){
		printf("%-10s %-12d %-12.1f\n", ex_st[i].name, ex_st[i].id, ex_st[i].height);
	}
	printf("\n\n");
}

void find_by_name(students ex_st[]){
	char name[K];
	int save_i;
	int count = 0, r = 1;
	while(r){
		printf("이름을 입력하세요: ");
		scanf("%s", name);
		for (int i =0; i < N; i++){
			if (strcmp(name, ex_st[i].name) == 0){
				count = 1;
				save_i = i;
		 	}
		}	
		if (count == 1){
			printf ("\n\n이름       아이디      키\n");
			printf("%-10s %-12d %-12.1f\n\n\n", ex_st[save_i].name, ex_st[save_i].id, ex_st[save_i].height);
			r = 0;
			return;
		}
		else if (count == 0)
			printf("목록에 그런 이름이 없습니다. 다시 입력하세요.\n\n");
		
	}
}


int main(void){
	int r = 1;
	char ch_number[10];
	int number;
	students ex_st[N] = { {"Sophia", 20220001, 153.1}, {"Olivia", 20220010, 158.5},
						  {"Riley", 20220002, 163.0}, {"Emma", 20220015, 160.3},
						  {"Ava", 20220009, 155.6}, {"Isabella", 20220014, 168.8},
						  {"Aria", 20220020, 150.2}, {"Amelia", 20220005, 162.5},
						  {"Mia", 20220016, 170.2}, {"Liam", 20220008, 180.9},
						  {"Noah", 20220012, 174.9}, {"Jackson", 20220004, 191.1},
						  {"Aiden", 20220018, 188.8}, {"Elijah", 20220017, 169.7},
						  {"Grayson", 20220003, 174.2}, {"Lucas", 20220013, 188.7},
						  {"Oliver", 20220007, 170.5}, {"Caden", 20220019, 173.3},
						  {"Mateo", 20220011, 169.9}, {"David", 20220006, 188.8} };


	while(r){
		printf("1.이름 오름차순 출력     2.아이디 오름차순 출력\n");	
		printf("3.키 내림차순 출력       4.이름 검색\n");
		printf("5.종료\n\n\n");
		printf("번호를 선택하세요: ");
		scanf("%s", ch_number);
		number = atoi(ch_number);

	
		switch (number){
			case 1:
				pr_by_name(ex_st);
				break;
			case 2:
			   	pr_by_id(ex_st);
				break;
			case 3:
				pr_by_height(ex_st);
				break;
			case 4:
				find_by_name(ex_st);
				break;
			case 5:
				printf("\n\n프로그램을 종료합니다.\n");
				r = 0;
				break;
			default:
				printf("잘못된 번호입니다. 다시 입력하세요.\n\n");
		}
	}

	return 0;
}
