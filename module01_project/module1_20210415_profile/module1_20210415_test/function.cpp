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
		printf("1 : �̸�\n");
		printf("2 : ����\n");
		printf("3 : ����\n");
		printf("4 : �޴�����ȣ\n");
		printf("5 : ��Ī���\n");
		printf("========================\n");
		printf("1~5 �����ϼ��� : \n");
		scanf("%d", &search_num);
		switch (search_num)
		{
		case 1:	
			printf("�˻��� �̸� : ");
			scanf("%s", name);
			for (i = 0; i <= total_student; i++)
			{
				if (strcmp(s[i].name, name) == 0)
					print_profile(s, i);
			}
			break;
		case 2:
			printf("�˻��� ���� : ");
			scanf("%s", gender);
			for (int i = 0; i <= total_student; i++)
			{
				if (strcmp(s[i].gender, gender) == 0)
					print_profile(s, i);
			}
			break;
		case 3:
			printf("�˻��� ���� : ");
			scanf("%d", &birthday);
			for (int i = 0; i <= total_student; i++)
			{
				if (s[i].birthday == birthday)
					print_profile(s, i);
			}
			break;
		case 4:
			printf("�˻��� �޴��� ��ȣ : ");
			scanf("%s", num);
			for (int i = 0; i <= total_student; i++)
			{
				if (strcmp(s[i].num, num) ==0)
					print_profile(s, i);
			}
			break;
		case 5:
			printf("�˻��� ��Ī��� : ");
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
	printf("========================\n�̸� : %s\n���� : %s\n���� : %d\n�޴�����ȣ : %s\n��Ī��� : %s\n========================\n", s[i].name, s[i].gender, s[i].birthday, s[i].num, s[i].inc);
}