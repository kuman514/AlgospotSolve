#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

int main(void)
{
	int N;
	scanf("%d", &N);
	int h[N], r[N] = {0,};
	for(int i = 0; i < N; i++) scanf("%d", &h[i]);

	for(int i = N-1; i >= 0; i--)
	{
		for(int j = i-1; j >= 0; j--)
		{
			if(h[j] >= h[i]) {r[i] = j+1; break;}
		}
	}

	for(int i = 0; i < N; i++) printf("%d ", r[i]);
	printf("\n");
	
	return 0;
}
