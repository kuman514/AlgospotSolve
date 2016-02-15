#include <stdio.h>

int stohex(char s[])		// Converts string (2 letters after '%') into a hexadecimal number
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
		scanf("%d", &count);			// 1 <= C <= 100
	
	char input[count][80];				// Each input string can contain at most 80 letters
	for(i = 0; i < count; i++)
		scanf("%s", input[i]);

	for(i = 0; i < count; i++)
	{
		j = 0;
		while(input[i][j] != '\0')
		{
			if(input[i][j] == '%')		// If it encounters '%', an escape letter will be printed.
			{
				escape = stohex(input[i] + j + 1);
				putchar(escape);
				j += 3;					// We must skip 2 letters because of the escape letter.
			}
			else
			{
				putchar(input[i][j]);
				j++;					// Next letter
			}
		}
		putchar('\n');					// End of a string
	}
	
	return 0;
}
