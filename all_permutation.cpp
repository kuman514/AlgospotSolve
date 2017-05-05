#include <iostream>
#include <cstdio>

int a[8] = {0,};
int N = 0;
void search(int);
bool promising(int);

int main(void)
{
	while(!(1 <= N && N <= 8)) scanf("%d", &N);

	search(0);
	return 0;
}

void search(int index)
{
	for(int i = 1; i <= N; i++)
	{
		a[index] = i;
		if(promising(index))
		{
			if(index == N-1)
			{
				for(int j = 0; j < N; j++)
					printf("%d ", a[j]);
				printf("\n");
			}
			else
				search(index+1);
		}
	}
}

bool promising(int index)
{
	bool sw = true;
	for(int i = 0; i <= index; i++)
	{
		for(int j = i+1; j <= index; j++)
			if(a[i] == a[j])
				sw = false;
	}

	return sw;
}
