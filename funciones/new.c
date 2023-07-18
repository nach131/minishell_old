
#include <stdio.h>

int main(void)
{
	int i = 0;

	((i = 1) && printf("i: %d\n", i) && (i = 10));
	printf("i: %d\n", i);
	return (0);
}
