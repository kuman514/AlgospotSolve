#include <stdio.h>
int main(){
	int T=0,i,j;
	while(T<1) scanf("%d",&T);
	char code[T][8],syndrome[T][3];
	//char error[T],errpos[T];
	for(i=0;i<T;++i){
		//error[i]=0;
		//errpos[i]=0;
		scanf("%s",code[i]);
		for(j=0;j<7;++j)
			code[i][j]-='0';
	}
	for(i=0;i<T;++i){
		syndrome[i][2]=code[i][0]^code[i][2]^code[i][4]^code[i][6];
		syndrome[i][1]=code[i][1]^code[i][2]^code[i][5]^code[i][6];
		syndrome[i][0]=code[i][3]^code[i][4]^code[i][5]^code[i][6];
		code[i][0]|=syndrome[i][0];
		code[i][1]|=syndrome[i][1];
		code[i][2]|=syndrome[i][2];
	}
	for(i=0;i<T;++i){
		printf("%d%d%d%d\n",code[i][2],code[i][4],code[i][5],code[i][6]);
		//printf("%d%d%d%d\n",code[i][2],code[i][4],code[i][5],code[i][6]);
		//else printf("ERROR\n");
	}
	return 0;
}
