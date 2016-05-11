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
	do
	{
		scanf("%d", &input);
		
		if(input > n)
		{
			printf("No\n");
			break;
		}

		while(i <= input)
		{
			printf("+\n");
			sa.push(i);
			++i;
		}

		int satop = sa.top();
		if(satop >= input)
		{
			printf("-\n");
			ra.push(satop);
			sa.pop();
		}
		else if(satop < input)
		{
			printf("No\n");
			break;
		}
	}
	while(!sa.empty());

	return 0;
}
