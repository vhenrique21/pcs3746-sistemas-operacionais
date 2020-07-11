#include <stdio.h>
#include <unistd.h>

int fatorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * fatorial(n - 1);
}

int main()
{
	int n = 1;
	
	while (1)
	{
		if (n == 10)
			n = 1;
		fatorial(n);
		n++;
		// sleep(2);
	}
	
	return 0;
}
