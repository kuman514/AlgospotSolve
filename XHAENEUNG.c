#include <stdio.h>
#include <string.h>

int compare(void *a, void *b) { return *(char*)a - *(char*)b; }
int stonum(char str[])
{
	if(strcmp(str, "eorz") == 0)
		return 0;
	else if(strcmp(str, "eno") == 0)
		return 1;
	else if(strcmp(str, "otw") == 0)
		return 2;
	else if(strcmp(str, "eehrt") == 0)
		return 3;
	else if(strcmp(str, "foru") == 0)
		return 4;
	else if(strcmp(str, "efiv") == 0)
		return 5;
	else if(strcmp(str, "isx") == 0)
		return 6;
	else if(strcmp(str, "eensv") == 0)
		return 7;
	else if(strcmp(str, "eghit") == 0)
		return 8;
	else if(strcmp(str, "einn") == 0)
		return 9;
	else if(strcmp(str, "ent") == 0)
		return 10;
	else
		return -1;
}

int main(void)
{
	int T = 0, i = 0;
	while(T < 1)
		scanf("%d", &T);
	
	char A[T][10], B[T][10], C[T][10];
	char operator[T];
	int result[T][3];

	for(i = 0; i < T; i++)
	{
		scanf("%s %c %s = %s", A[i], &operator[i], B[i], C[i]);
		qsort(A[i], strlen(A[i]), sizeof(char), compare);
		qsort(B[i], strlen(A[i]), sizeof(char), compare);
		qsort(C[i], strlen(A[i]), sizeof(char), compare);
		result[i][0] = stonum(A[i]);
		result[i][1] = stonum(B[i]);
		result[i][2] = stonum(C[i]);

		printf("%d %c %d = %d\n", result[i][0], operator[i], result[i][1], result[i][2]);
	}
	
	return 0;
}
