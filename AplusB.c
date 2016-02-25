#include <stdio.h>
int main()
{
	unsigned int A=0,B=0;
	while((A<1||A>9)||(B<1||B>9)) scanf("%d%d",&A,&B);
	printf("%d",A+B);
	return 0;
}
