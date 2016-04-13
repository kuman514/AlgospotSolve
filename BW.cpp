#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

struct tri
{
	int first;
	int second;
	int third;
	tri(int a, int b, int c) : first(a), second(b), third(c) {}
};

const int dr[] = {1,-1,0,0}, dc[] = {0,0,1,-1};

int main(void)
{
	int N,M;
	do{scanf("%d%d",&N,&M);}while(N<0||N>1000||M<0||M>1000);

	bool map[N][M];
	bool check[N][M];

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
		{
			char c;
			while((c = getchar())!='0'&&c!='1');
			map[i][j] = static_cast<bool>(c-'0');
			check[i][j] = 0;
		}

	if(map[0][0] || map[N-1][M-1])
		std::cout << "-1" << std::endl;
	else
	{
		tri tmp(0,0,0);
		std::queue<tri> flag;
		flag.push(tmp);
		int result = -1;
		while(!flag.empty())
		{
			tri i = flag.front();
			flag.pop();

			if(i.first < 0 || i.first >= N) continue;
			if(i.second < 0 || i.second >= M) continue;
			if(check[i.first][i.second]) continue;

			if(i.first==N-1 && i.second==M-1) {result = i.third; break;}

			check[i.first][i.second] = 1;
			if(map[i.first][i.second]) ++(i.third);

			for(int k = 0; k < 4; ++k)
			{
				tri tmp(i.first+dr[k],i.second+dc[k],i.third);
				flag.push(tmp);
			}
		}
		std::cout << result << std::endl;
	}

	return 0;
}
