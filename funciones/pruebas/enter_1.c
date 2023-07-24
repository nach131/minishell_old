#include <stdio.h>
#include <unistd.h>

void waitForEnter()
{
	char c;
	printf("Presiona Enter para continuar...\n");

	while (read(STDIN_FILENO, &c, 1) == 1)
	{
		if (c == '\n')
		{
			printf("Has pulsado Enter\n");
			break;
		}
	}
}

int main()
{
	// Llamamos a la función waitForEnter para esperar a que el usuario presione Enter
	waitForEnter();

	// Aquí puedes continuar con el resto del código
	// ...
	return 0;
}
