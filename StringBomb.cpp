#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

int main(void)
{
	std::stack<char> str;
	std::stack<char> c_sub;
	char sinput[1000001], binput[37];

	int slen = 0, blen = 0;
	while(!((1 <= slen && slen <= 1000000) && (1 <= blen && blen <= 36)))
	{
		char c;
		scanf("%[0-9A-Za-z]", sinput);
		scanf("%*c%[0-9A-Za-z]", binput);
		slen = strlen(sinput);
		blen = strlen(binput);
	}

	for(int i = 0; i < slen; i++)
		str.push(sinput[i]);

	char tmp[blen + 2];
	tmp[blen] = '\0';
	tmp[blen+1] = '\0';

	while(!(str.empty()))
	{
		c_sub.push(str.top());
		std::strcpy(tmp + 1, tmp);
		tmp[blen] = '\0';
		tmp[0] = str.top();
		str.pop();

		if(strcmp(binput, tmp) == 0)
		{
			for(int i = 0; i < blen; i++)
			{
				tmp[i] = ' ';
				c_sub.pop();
			}

			while(!(c_sub.empty()))
			{
				str.push(c_sub.top());
				c_sub.pop();
			}
		}
	}

	while(!(c_sub.empty()))
	{
		str.push(c_sub.top());
		c_sub.pop();
	}

	if(str.empty())
	{
		printf("FRULA\n");
	}
	else
	{
		int rsize = str.size();
		char result[rsize+1];
		result[rsize] = '\0';
		for(int i = rsize-1; i >= 0; i--)
		{
			result[i] = str.top();
			str.pop();
		}
		printf("%s\n", result);
	}

	return 0;
}
