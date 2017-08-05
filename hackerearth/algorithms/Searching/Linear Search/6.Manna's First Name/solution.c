#include <stdio.h>

int suvo, suvojith;

int present(char *string, int i, char *pattern)
{
	for(int k = i, j = 0; string[k] != '\0' && pattern[j] != '\0'; k++, j++)
	{
		// printf("%c %c\n",string[k], pattern[j] );
		if(string[k] != pattern[j])
			return 0;
	}
	return 1;
}

void search(char *string)
{
	for(int i = 0; string[i] != '\0'; i++)
	{
		if(present(string, i, "SUVOJIT"))
			suvojith++;
		else if(present(string, i, "SUVO"))
			suvo++;
	}
}

int main()
{
	int n, i;
	char string[151] = "\0";
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		suvojith = 0;
		suvo = 0;
		fgets(string, 151, stdin);
		search(string);
		printf("SUVO = %d, SUVOJIT = %d\n",suvo, suvojith );
	}
}
