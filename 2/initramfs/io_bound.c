#include <stdio.h>
#include <unistd.h>

int main()
{
	char c;
	
	while (1)
	{
		// printf("Insira um caracter: ");
		c = getc(stdin);
		
		// printf("O caracter inserido eh: ");
		putchar(c);
		printf("\n\n");
		
		c = getc(stdin);
		sleep(1);
	}
	
	return 0;
}
