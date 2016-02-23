#include <stdio.h>

typedef union _CODE
{
	char message;
	char space:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} code;

char stom(const char *input)
{
	char result = 0;
	int i;
	for(i = 0; i < 7; ++i)
	{
		result <<= 1;
		result |= input[i] - '0';
	}
	return result;
}

void printbit(code input)
{
	printf("%d%d%d%d%d%d%d\n", input.b1, input.b2, input.b3, input.b4, input.b5, input.b6, input.b7);
}

int main(void)
{
	int T = 0;
	int i, j;
	while(T < 1) scanf("%d", &T);

	code line[T];
	char input[8];

	for(i = 0; i < T; ++i)
	{
		scanf("%s", input);
		line[i].message = stom(input);
	}

	return 0;
}
