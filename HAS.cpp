#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
	bool check[100001]={0,};
	int N,K;
	do{scanf("%d%d",&N,&K);
	}while(N<0||N>100000||K<0||K>100000);
	if(N>=K)cout<<N-K<<::endl;
	else{
		queue<pair<int,int>> flag;
		int result;
		pair<int,int> tmp(N,0);
		flag.push(tmp);
		while(1){
			auto i=flag.front();
			flag.pop();
			if(i.first<0||i.first>100000)continue;
			if(check[i.first])continue;
			if(i.first==K){result=i.second;break;}
			check[i.first]=1;
			++(i.second);
			i.first -= 1;flag.push(i);	
			i.first += 2;flag.push(i);
			i.first -= 1;i.first *= 2;flag.push(i);}
		cout<<result<<endl;}
	return 0;}
