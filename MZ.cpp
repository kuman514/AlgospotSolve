#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

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
	int result;
	tri tmp(0,0,0);
	flag.push(tmp);

	while(!flag.empty())
	{
		auto i=flag.front();
		flag.pop();
		if(i.first<0||i.first>=N)continue;
		if(i.second<0||i.second>=K)continue;
		if(!check[i.first][i.second])continue;
		if(i.first==K-1&&i.second==N-1){result=i.third;break;}
		check[i.first][i.second]=0;
		++(i.third);

		//i.first -= 1;flag.push(i);	
		//i.first += 2;flag.push(i);
		//i.first -= 1;i.first *= 2;flag.push(i);
	}
	cout<<result<<endl;
	return 0;
}
