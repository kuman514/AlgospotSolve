#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

int main(void)
{
	int n, input;
	std::stack<int> sa, ia, ra;
	do{scanf("%d", &n);} while(n < 1 || n > 100000);

	int i = 1;
	while(i <= n)
	{
		scanf("%d", &input);
		
		if(input > n)
		{
			printf("No\n");
			return 0;
		}

		while(i <= input)
		{
			printf("+\n");
			sa.push(i);
			++i;
		}

		while(sa.top() >= input)
		{
			printf("-\n");
			ra.push(sa.top());
			sa.pop();
		}
	}

	while(!(sa.empty()))
	{
		ra.push(sa.top());
		sa.pop();
		printf("-\n");
	}

	return 0;
}
