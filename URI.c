#include <stdio.h>

int main(void)
{
	int count = 0, i, j;
	char stack[4];

	while(1 <= count && count <= 100)
		scanf("%d", &count);
	
	char input[count][80];
	for(i = 0; i < count; i++)
		scanf("%s", input[i]);

	for(i = 0; i < count; i++)
	{
		j = 0;
		while(input[i][j] != '\0')
		{
			if(input[i][j] == '%')
			{
			}
			else
			{
				putchar(input[i][j]);
				j++;
			}
		}
	}
	
	return 0;
}
