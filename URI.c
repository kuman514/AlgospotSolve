#include <stdio.h>

int stohex(char s[])
{
	int i, result = 0;
	for(i = 0; i < 2; i++)
	{
		if('0' <= s[i] && s[i] <= '9')
			result = (result * 16) + (s[i] - '0');
		else if('a' <= s[i] && s[i] <= 'f')
			result = (result * 16) + (s[i] - 'a' + 10);
		else if('A' <= s[i] && s[i] <= 'F')
			result = (result * 16) + (s[i] - 'A' + 10);
	}
	return result;
}

int main(void)
{
	int count = 0, i, j;
	char escape;

	while(count < 1 || count > 100)
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
				escape = stohex(input[i] + j + 1);
				putchar(escape);
				j += 3;
			}
			else
			{
				putchar(input[i][j]);
				j++;
			}
		}
		putchar('\n');
	}
	
	return 0;
}
