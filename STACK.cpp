#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

int main(void)
{
	std::stack<int> IntStack;
	char sinput[50];
	int iinput, N;

	do{scanf("%d", &N);} while(N<1||N>10000);

	for(int i = 0, j; i < N; i++)
	{
		scanf("%s", sinput);
		
		if(strcmp(sinput, "push") == 0)
		{
			scanf("%d", &iinput);
			IntStack.push(iinput);
		}

		if(strcmp(sinput, "pop") == 0)
		{
			if(IntStack.empty()) j = -1;
			else
			{
				j = IntStack.top();
				IntStack.pop();
			}
			std::cout << j << std::endl;
		}

		if(strcmp(sinput, "size") == 0) std::cout << IntStack.size() << std::endl;
		
		if(strcmp(sinput, "empty") == 0) std::cout << (IntStack.empty() ? 1 : 0) << std::endl;
		
		if(strcmp(sinput, "top") == 0)
		{
			if(IntStack.empty()) j = -1;
			else j = IntStack.top();
			std::cout << j << std::endl;
		}
	}

	return 0;
}
