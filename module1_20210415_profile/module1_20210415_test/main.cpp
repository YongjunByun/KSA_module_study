#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#define total_student 25
#include "struct.h"
#include <string.h>
void SEARCH(student s[total_student]);

int main(void)
{
	FILE *ifp;
	FILE *ofp;

	char name[50];
	char gender[50];
	int birthday;
	char num[50];
	char inc[50];
	int res;


	ifp = fopen("profile.txt", "r");
	if (ifp == NULL)
	{
		printf("입력 파일을 열지 못헸습니다.\n");
		return 1;
	}
	
	struct student s[total_student];
	for (int i = 0; i <= total_student; i++)
	{
		res = fscanf(ifp, "%s%s%d%s%s", name, gender, &birthday, num, inc);
		if (res == EOF)
		{
			break;
		}

		strcpy(s[i].name, name);
		strcpy(s[i].gender, gender);
		s[i].birthday = birthday;
		strcpy(s[i].num, num);
		strcpy(s[i].inc, inc);
	}
	SEARCH(s);

	fclose(ifp);

	return 0;
}


