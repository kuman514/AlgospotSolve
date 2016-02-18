#include <stdio.h>
#include <string.h>

void sort(char a[])
{
	// This is Bubble Sort.
	// Actually, I used qsort() before, but it caused compile error when I submit my answer to Algospot.
	// Therefore, I can't help using bubble sort, which is what I know very much.

	int count = strlen(a), i, j;
	char tmp;
	
	for(i = 0; i < count; i++)
		for(j = count - 1; j > i; j--)
			if(a[j - 1] > a[j])
			{
				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
}

int stonum(char str[])
{
	// The question requires that despite the wrong order a word to a number should be checked correctly.
	// What I thought was to sort all the letters in a word and compare the sorted number words.

	if(strcmp(str, "eorz") == 0)		// zero
		return 0;
	else if(strcmp(str, "eno") == 0)	// one
		return 1;
	else if(strcmp(str, "otw") == 0)	// two
		return 2;
	else if(strcmp(str, "eehrt") == 0)	// three
		return 3;
	else if(strcmp(str, "foru") == 0)	// four
		return 4;
	else if(strcmp(str, "efiv") == 0)	// five
		return 5;
	else if(strcmp(str, "isx") == 0)	// six
		return 6;
	else if(strcmp(str, "eensv") == 0)	// seven
		return 7;
	else if(strcmp(str, "eghit") == 0)	// eight
		return 8;
	else if(strcmp(str, "einn") == 0)	// nine
		return 9;
	else if(strcmp(str, "ent") == 0)	// ten
		return 10;
	else								// and others...
		return -100;
}

int OP(int p1, char oper, int p2)
{
	if(oper == '+')
		return p1 + p2;
	else if(oper == '-')
		return p1 - p2;
	else if(oper == '*')
		return p1 * p2;
	else if(oper == '/')
		return p1 / p2;
	else
		return -100;
}
int main(void)
{
	int T = 0, i = 0;

	while(T < 1)
		scanf("%d",&T);
	
	char A[T][10],B[T][10],C[T][10];
	char operator[T];
	int result[T][3], f;
	
	for(i=0;i<T;i++)
	{
		scanf("%s %c %s = %s", A[i], &operator[i], B[i], C[i]);
		sort(A[i]);
		sort(B[i]);
		sort(C[i]);
		result[i][0] = stonum(A[i]);
		result[i][1] = stonum(B[i]);
		result[i][2] = stonum(C[i]);
	}
	
	for(i = 0; i < T; i++)
	{
		f = OP(result[i][0], operator[i], result[i][1]);
		// f checks the answer more shortly

		if(f < 0 || f > 10)
			printf("NO\n");
		else if(f == result[i][2])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
