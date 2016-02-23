#include <stdio.h>

int main(void)
{
	int T = 0;
	int i, j;
	while(T < 1) scanf("%d", &T);

	char line[T][8];
	for(i = 0; i < T; ++i)
	{
		scanf("%s", line[i]);
		for(j = 0; j < 7; ++j)
		{
			if(line[i][j] != '0')
				line[i][j] = 1;
			else
				line[i][j] = 0;
		}
	}
	// turned into 0 and 1

	return 0;
}
