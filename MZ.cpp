#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int drr[4] = {1,-1,0,0};
const int drc[4] = {0,0,1,-1};

struct tri
{
	int first;
	int second;
	int third;
	tri(int a, int b, int c) : first(a),second(b),third(c) {}
};

int main()
{
	int N,K;
	do{scanf("%d%d",&N,&K);
	}while(N<2||N>100||K<2||K>100);
	bool check[N][K];
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < K; ++j)
		{
			char c;
			while((c = getchar())!='0'&&c!='1');
			check[i][j] = static_cast<bool>(c - '0');
		}

	queue<tri> flag;
	int result = -1;
	tri tmp(0,0,0);
	flag.push(tmp);

	while(!flag.empty())
	{
		tri i=flag.front();
		flag.pop();

		if(i.first<0||i.first>=N)continue;
		if(i.second<0||i.second>=K)continue;
		if(!check[i.first][i.second])continue;
		if((i.first==N-1)&&(i.second==K-1)){result=i.third+1;break;}
		if((i.first!=N-1)||(i.second!=K-1))check[i.first][i.second]=0;
		++(i.third);

		for(int j = 0; j < 4; ++j)
		{
			tri tmp(i.first + drr[j], i.second + drc[j], i.third);
			flag.push(tmp);
		}
	}
	cout<<result<<endl;
	return 0;
}
