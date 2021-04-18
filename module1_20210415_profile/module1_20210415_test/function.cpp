#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include "struct.h"
#define total_student 27
void print_profile(student s[total_student], int i);
void SEARCH(student s[total_student])
{
	char name[50];
	char gender[50];
	int birthday;
	char num[50];
	char inc[50];
	int i;

	while (1)
	{
		int search_num;
		printf("========================\n");
		printf("1 : 이름\n");
		printf("2 : 성별\n");
		printf("3 : 생일\n");
		printf("4 : 휴대폰번호\n");
		printf("5 : 매칭기업\n");
		printf("========================\n");
		printf("1~5 선택하세요 : \n");
		scanf("%d", &search_num);
		switch (search_num)
		{
		case 1:	
			printf("검색할 이름 : ");
			scanf("%s", name);
			for (i = 0; i <= total_student; i++)
			{
				if (strcmp(s[i].name, name) == 0)
					print_profile(s, i);
			}
			break;
		case 2:
			printf("검색할 성별 : ");
			scanf("%s", gender);
			for (int i = 0; i <= total_student; i++)
			{
				if (strcmp(s[i].gender, gender) == 0)
					print_profile(s, i);
			}
			break;
		case 3:
			printf("검색할 생일 : ");
			scanf("%d", &birthday);
			for (int i = 0; i <= total_student; i++)
			{
				if (s[i].birthday == birthday)
					print_profile(s, i);
			}
			break;
		case 4:
			printf("검색할 휴대폰 번호 : ");
			scanf("%s", num);
			for (int i = 0; i <= total_student; i++)
			{
				if (strcmp(s[i].num, num) ==0)
					print_profile(s, i);
			}
			break;
		case 5:
			printf("검색할 매칭기업 : ");
			scanf("%s", inc);
			for (int i = 0; i <= total_student; i++)
			{
				if (strcmp(s[i].inc, inc) ==0)
					print_profile(s, i);
			}
			break;
		}
	}
}

void print_profile(student s[total_student],int i)
{
	printf("========================\n이름 : %s\n성별 : %s\n생일 : %d\n휴대폰번호 : %s\n매칭기업 : %s\n========================\n", s[i].name, s[i].gender, s[i].birthday, s[i].num, s[i].inc);
}