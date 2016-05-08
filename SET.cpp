#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

int main(void)
{
	std::set<int> IntSet;
	char sinput[50];
	int iinput, M;

	do{scanf("%d", &M);} while(M<1||M>10000);

	std::set<int>::iterator j;
	for(int i = 0; i < M; i++)
	{
		scanf("%s", sinput);
		
		if(strcmp(sinput, "add") == 0)
		{
			do{scanf("%d", &iinput);} while(iinput<1||iinput>20);
			j = IntSet.find(iinput);
			if(j == IntSet.end()) IntSet.insert(iinput);
		}
		
		if(strcmp(sinput, "remove") == 0)
		{
			do{scanf("%d", &iinput);} while(iinput<1||iinput>20);
			j = IntSet.find(iinput);
			if(j != IntSet.end()) IntSet.erase(j);
		}
		
		if(strcmp(sinput, "check") == 0)
		{
			do{scanf("%d", &iinput);} while(iinput<1||iinput>20);
			j = IntSet.find(iinput);
			printf("%d\n", (j != IntSet.end()) ? 1 : 0);
		}
		
		if(strcmp(sinput, "toggle") == 0)
		{
			do{scanf("%d", &iinput);} while(iinput<1||iinput>20);
			j = IntSet.find(iinput);
			if(j != IntSet.end()) IntSet.erase(j); else IntSet.insert(iinput);
		}
		
		if(strcmp(sinput, "all") == 0) IntSet = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		if(strcmp(sinput, "empty") == 0) IntSet.clear();
	}

	return 0;
}
