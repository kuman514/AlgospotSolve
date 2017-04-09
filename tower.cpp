#include <iostream>
#include <cstdio>
#include <algorithm>

int main(void)
{
	int N;
	while(!(1 <= N && N <= 500000))
		scanf("%d", &N);
	
	int h[N], r[N] = {0,};
	for(int i = 0; i < N; i++)
		while(!(1 <= h[i] && h[i] <= 100000000))
			scanf("%d", &h[i]);

	for(int i = N-1; i >= 0; i--)
	{
		for(int j = i-1; j >= 0; j--)
		{
			if(h[j] > h[i]) {r[i] = j+1; break;}
		}
	}

	for(int i = 0; i < N; i++) printf("%d ", r[i]);
	printf("\n");
	
	return 0;
}
