#include <stdio.h>
int n;
int col[255] = {0,};
int count = 0;

int abs(int x) {if(x < 0) return -x; else return x;}

_Bool promising(int i)
{
	int k;
	_Bool sw;

	k = 1;
	sw = 1;
	while(k<i && sw)
	{
		if(col[i] == col[k] || abs(col[i] - col[k]) == abs(i-k))
			sw = 0;
		k++;
	}

	return sw;
}

void queens(int i)
{
	int j;
	for(j = 1; j <= n; j++)
	{
		col[i+1] = j;
		if(promising(i+1))
		{
			if(i+1 == n)
			{
				/*
				for(j = 1; j <= n; j++)
					printf("%d ", col[j]);
				putchar('\n');
				*/
				count++;
			}
			else
				queens(i+1);
		}
	}

	/*
	if(promising(i))
	{
		if(i == n)
		{
			for(j = 1; j <= n; j++)
				printf("%d ", col[j]);
			putchar('\n');
			count++;
		}
		else
			for(j = 1; j <= n; j++)
			{
				col[i+1] = j;
				queens(i+1);
			}
	}
	*/
}

int main(void)
{
	scanf("%d", &n);
	queens(0);
	printf("%d\n", count);
	return 0;
}
