#include <iostream>
#include <cstdio>

int main(void)
{
	int N = 0;
	while(!(1 <= N && N <= 100)) scanf("%d\n", &N);

	char num[N];
	scanf("%[0-9]", num);

	int sum = 0;
	for(int i = 0; i < N; i++)
		sum += num[i] - '0';

	printf("%d\n", sum);
	return 0;
}
