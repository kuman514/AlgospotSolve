#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <utility>

int main(void)
{
	int N;
	while(!(1 <= N && N <= 500000))
		scanf("%d", &N);
	
	std::pair<int,int> pair;
	std::stack<std::pair<int,int> > th;
	int h[N] = {0,}, r[N] = {0,};

	for(int i = 0; i < N; i++)
		while(!(1 <= h[i] && h[i] <= 100000000))
			scanf("%d", &h[i]);

	for(int i = 0; i < N; i++)
	{
		pair.first = i + 1;
		pair.second = h[i];

		if(th.empty())
		{
			r[i] = 0;
			th.push(pair);
		}
		else if(th.top().second < pair.second)
		{
			th.pop();
			i--;
			continue;
		}
		else
		{
			r[i] = th.top().first;
			th.push(pair);
		}
	}

	for(int i = 0; i < N; i++) printf("%d ", r[i]);
	return 0;
}
