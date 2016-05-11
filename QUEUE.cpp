#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

int main(void)
{
	std::queue<int> IntQueue;
	char sinput[50];
	int iinput, N;

	do{scanf("%d", &N);} while(N<1||N>10000);

	for(int i = 0, j; i < N; i++)
	{
		scanf("%s", sinput);
		
		if(strcmp(sinput, "push") == 0)
		{
			scanf("%d", &iinput);
			IntQueue.push(iinput);
		}

		if(strcmp(sinput, "pop") == 0)
		{
			if(IntQueue.empty()) j = -1;
			else
			{
				j = IntQueue.front();
				IntQueue.pop();
			}
			std::cout << j << std::endl;
		}

		if(strcmp(sinput, "size") == 0) std::cout << IntQueue.size() << std::endl;
		
		if(strcmp(sinput, "empty") == 0) std::cout << (IntQueue.empty() ? 1 : 0) << std::endl;
		
		if(strcmp(sinput, "front") == 0)
		{
			if(IntQueue.empty()) j = -1;
			else j = IntQueue.front();
			std::cout << j << std::endl;
		}

		if(strcmp(sinput, "back") == 0)
		{
			if(IntQueue.empty()) j = -1;
			else j = IntQueue.back();
			std::cout << j << std::endl;
		}
	}

	return 0;
}
