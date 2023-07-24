/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>

void waitForEnter()
{
    int c;
    printf("Presiona Enter para continuar...\n");
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Vaciar el búfer de entrada hasta encontrar Enter o el final del archivo (EOF)
    }
    printf("Has pulsado Enter\n");
}

int main()
{
    // Llamamos a la función waitForEnter para esperar a que el usuario presione Enter
    waitForEnter();

    // Aquí puedes continuar con el resto del código
    // ...
    return 0;
}

