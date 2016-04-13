#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

int main(void)
{
	int N;
	do{scanf("%d",&N);}while(N < 1 || N > 1000000);

	std::pair<int,int> tmp(N,0);
	std::queue<std::pair<int,int>> npq;
	npq.push(tmp);
	while(!npq.empty())
	{
		auto i = npq.front();
		npq.pop();
		if(i.first<1) continue;
		if(i.first==1){std::cout<<i.second<<std::endl;break;}

		if((i.first)%3==0)
		{
			tmp.first=i.first/3;
			tmp.second=i.second+1;
			npq.push(tmp);
		}
		
		if((i.first)%2==0)
		{
			tmp.first=i.first/2;
			tmp.second=i.second+1;
			npq.push(tmp);
		}
		
		tmp.first=i.first-1;
		tmp.second=i.second+1;
		npq.push(tmp);
	}

	return 0;
}
