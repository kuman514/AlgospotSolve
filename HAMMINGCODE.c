#include <stdio.h>
int main(){
	int T=0,i,j;
	// insert T lines
	while(T<1) scanf("%d",&T);
	char code[T][8];
	char error[T],errpos[T];
	for(i=0;i<T;++i){
		error[i]=0;
		errpos[i]=0;
		scanf("%s",code[i]);
		for(j=0;j<7;++j)
			code[i][j]-='0';
	}
	// check errors
	for(i=0;i<T;++i){
		if(code[i][0]!=code[i][2]^code[i][4]^code[i][6]){
			++error[i];errpos[i]=2;
		}
		if(code[i][1]!=code[i][2]^code[i][5]^code[i][6]){
			++error[i];errpos[i]=1;
		}
		if(code[i][2]!=code[i][4]^code[i][5]^code[i][6]){
			++error[i];errpos[i]=0;
		}
	}
	// decode message
	for(i=0;i<T;++i){
		if(error[i]<1)
			printf("%d%d%d%d\n",code[i][2],code[i][4],code[i][5],code[i][6]);
		else if(error[i]==1){
			printf("%d%d%d%d\n",code[i][2],code[i][4],code[i][5],code[i][6]);
		}
		else printf("ERROR\n");
	}
	return 0;
}
