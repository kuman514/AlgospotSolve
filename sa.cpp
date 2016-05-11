#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

int main(void)
{
	int n, input;
	std::stack<int> sa, ia, ra;
	do{scanf("%d", &n);} while(n < 1 || n > 100000);

	int a[n];
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &input);
		ia.push(input);
		a[i] = input;
	}

	for(int i = 1, j = 0; i <= n; ++i)
	{
		if(i < a[j])
		{
			sa.push(i);
			printf("+\n");
		}
		else if(i == a[j])
		{
			sa.push(i);
			printf("+\n");
			ra.push(sa.top());
			sa.pop();
			printf("-\n");
			++j;
		}
		else if(i > a[j])
		{
			ra.push(sa.top());
			sa.pop();
			printf("-\n");
			--i;
			++j;
		}
	}

	while(!(sa.empty()))
	{
		ra.push(sa.top());
		sa.pop();
		printf("-\n");
	}

	if(ra == ia) printf("Yes\n"); else printf("No\n");

	return 0;
}
