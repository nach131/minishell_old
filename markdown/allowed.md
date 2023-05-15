# Funciones permitidas

[readline](#readline), [rl_clear_history](#rl_clear_history), [rl_on_new_line](#rl_on_new_line), [rl_replace_line](#rl_replace_line), [rl_redisplay](#rl_redisplay), [add_history](#add_history), [access](#access), [fork](#fork), [wait](#wait), 


### [readline](../funciones/permitidas/readline.c)

```c
char *readline(const char *prompt);
```

<details>
  <summary>Descripción</summary>

### [Instalar readline](./../funciones/permitidas/readline.md)

`readline()` esta incluida en la biblioteca `libreadline`, que proporcionan una funcionalidad avanzada para la lectura de líneas de entrada desde el usuario en la línea de comandos.


La función `readline()` lee una línea de entrada desde el usuario y la devuelve como un puntero a una cadena de caracteres dinámicamente asignada en memoria. La sintaxis de la función `readline()` es la siguiente:

- `prompt` es una cadena de caracteres que se muestra en la línea de comandos para indicar que se está esperando la entrada del usuario.

La función `readline()` devuelve un puntero a una cadena de caracteres que contiene la línea de entrada leída. El usuario debe liberar la memoria asignada a esta cadena utilizando la función `free()` cuando ya no se necesite.

</details>

___

### [rl_clear_history](../funciones/permitidas/rl_clear_history.c)

```c
void rl_clear_history(void);
```

<details>
  <summary>Descripción</summary>

La función `rl_clear_history` es una función de la biblioteca de línea de comandos `readline` en C, que se utiliza para borrar el historial de entrada. La función se define en el archivo de encabezado `readline/history.h`.

La función no toma argumentos y no devuelve ningún valor.

La función `rl_clear_history` borra todo el historial de entrada almacenado en la memoria por la biblioteca readline. El historial de entrada se almacena en un archivo oculto en el directorio de inicio del usuario, por lo que borrar el historial con esta función solo borra los datos de la memoria, no del archivo en sí.

Es importante tener en cuenta que la función `rl_clear_history` solo borra el historial de entrada que ha sido almacenado por la biblioteca readline. Si está utilizando otra biblioteca o un enfoque personalizado para manejar la entrada de la línea de comandos, es posible que deba implementar su propia función de limpieza de historial.

</details>

___


### [rl_on_new_line](../funciones/permitidas/rl_on_new_line.c)

```c
void rl_on_new_line(void);
```

<details>
  <summary>Descripción</summary>

La función `rl_on_new_line` es una función de la biblioteca `readline` en C, que se utiliza para notificar a la biblioteca que se ha llegado a una nueva línea en la entrada. La función se define en el archivo de encabezado `readline/readline.h`.

La función no toma argumentos y no devuelve ningún valor.

Cuando se llama a la función `rl_on_new_line`, la biblioteca `readline` procesa la línea actual de entrada y la agrega al historial. También restablece el estado de la línea de entrada a la configuración inicial para la siguiente entrada. Esta función debe llamarse siempre que se completa una línea de entrada y antes de leer una nueva línea de entrada.

</details>

___

### [rl_replace_line](../funciones/permitidas/rl_replace_line.c)

```c
void rl_replace_line(const char* text, int clear_undo);
```

<details>
  <summary>Descripción</summary>

	La función `rl_replace_line` es una función de la biblioteca `readline` en C, que se utiliza para reemplazar la línea actual de entrada con una nueva línea. La función se define en el archivo de encabezado `readline/readline.h`.

La función toma dos argumentos: 

1. `text` es un puntero a una cadena de caracteres que se utilizará para reemplazar la línea actual de entrada.
2. `clear_undo` es un valor booleano (0 o 1) que indica si se deben borrar los datos de deshacer (undo) de la línea actual de entrada antes de reemplazarla.

Cuando se llama a la función `rl_replace_line`, la biblioteca `readline` reemplaza la línea actual de entrada con la cadena de caracteres especificada en `text`. Si `clear_undo` es `1`, se borrarán los datos de deshacer (undo) de la línea actual de entrada. Si `clear_undo` es `0`, los datos de deshacer (undo) permanecerán intactos.

En este ejemplo, utilizamos un ciclo `while` para leer continuamente líneas de entrada utilizando la función `readline`. Después de procesar la entrada, llamamos a la función `rl_replace_line` para reemplazar la línea actual de entrada con una nueva línea que dice "Nueva línea". También especificamos que se deben borrar los datos de deshacer (undo) de la línea actual de entrada utilizando `1` como segundo argumento.

Luego llamamos a la función `rl_redisplay` para redibujar la nueva línea en la consola. Finalmente, liberamos la memoria utilizada por `readline` para la entrada utilizando la función `free`.

</details>

___

### [rl_redisplay](../funciones/permitidas/rl_redisplay.c)

<details>
  <summary>Descripción</summary>

  La función `rl_redisplay()` es parte de la biblioteca `readline` en C y se utiliza para redibujar la línea de entrada actual en la consola. Esto puede ser útil si necesitas actualizar la línea de entrada para que refleje un cambio en el estado del programa, por ejemplo, para mostrar un mensaje de error o para actualizar el prompt.

</details>

___

## [add_history](../funciones/permitidas/add_history.c)

```c
void add_history(const char *line);
```

<details>
  <summary>Descripción</summary>

`add_history` es una función de la biblioteca `readline` que se utiliza para agregar una línea de texto al historial de comandos. El historial de comandos es una lista de comandos previamente ingresados por el usuario, que se puede recuperar y reutilizar en la consola con el uso de teclas de flecha hacia arriba y hacia abajo. 

Donde `line` es un puntero a una cadena de caracteres que representa el comando a agregar al historial.

</details>

___

### [access](../funciones/permitidas/access.c)

```c
int access(const char *path, int mode);
```

<details>
  <summary>Descripción</summary>

se utiliza para verificar si se puede acceder a un archivo o si un archivo existe. La función devuelve un valor entero distinto de cero si se puede acceder al archivo o si el archivo existe, y devuelve cero si no se puede acceder al archivo o si el archivo no existe.

Donde `path` es un puntero a una cadena de caracteres que representa la ruta del archivo a verificar, y `mode` es un conjunto de indicadores que especifican los permisos de acceso a comprobar.

Los valores posibles de `mode` son los siguientes:

- `F_OK`: Verifica si el archivo existe.
- `R_OK`: Verifica si el archivo es legible.
- `W_OK`: Verifica si el archivo es escribible.
- `X_OK`: Verifica si el archivo es ejecutable.

</details>

___

### [fork](../funciones/permitidas/fork.c)

<details>
  <summary>Descripción</summary>

La función `fork()` se utiliza para crear un nuevo proceso a partir del proceso actual. El proceso que llama a `fork()` se conoce como proceso padre y el proceso recién creado se conoce como proceso hijo.

La función `fork()` devuelve un valor entero que representa el resultado de la llamada. Si el valor es negativo, significa que se produjo un error al crear el proceso hijo. Si el valor es cero, significa que la llamada a `fork()` se realizó correctamente en el proceso hijo. Si el valor es positivo, significa que la llamada a `fork()` se realizó correctamente en el proceso padre y el valor devuelto es el ID del proceso hijo.

</details>

___

### [wait](../funciones/permitidas/wait.c)

```c
pid_t wait(int *status);
```

<details>
  <summary>Descripción</summary>

La función `wait` en C es una llamada al sistema que suspende la ejecución del proceso actual hasta que uno de sus procesos hijos finaliza su ejecución. La función `wait` tiene la siguiente sintaxis:

Donde `status` es un puntero a una variable de tipo `int` que contiene información sobre el estado del proceso hijo que finalizó su ejecución.

A continuación, se presentan tres ejemplos que ilustran el uso de la función `wait` en C:

#### Ejemplo 1: Esperando a un proceso hijo

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Este es el proceso hijo
        printf("Soy el proceso hijo\n");
        exit(0);
    } else if (pid > 0) {
        // Este es el proceso padre
        printf("Soy el proceso padre\n");
        wait(NULL);
        printf("El proceso hijo ha finalizado\n");
    } else {
        // Error al crear el proceso hijo
        perror("fork");
        exit(1);
    }
    
    return 0;
}
```

En este ejemplo, se crea un proceso hijo utilizando la función `fork`. El proceso hijo imprime un mensaje y sale de la ejecución utilizando la función `exit`. El proceso padre espera a que el proceso hijo finalice su ejecución utilizando la función `wait`. Una vez que el proceso hijo ha finalizado, el proceso padre imprime un mensaje indicando que el proceso hijo ha finalizado.

#### Ejemplo 2: Manejando el estado de salida del proceso hijo

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int status;
    
    if (pid == 0) {
        // Este es el proceso hijo
        printf("Soy el proceso hijo\n");
        exit(1);
    } else if (pid > 0) {
        // Este es el proceso padre
        printf("Soy el proceso padre\n");
        wait(&status);
        if (WIFEXITED(status)) {
            printf("El proceso hijo ha finalizado con estado %d\n", WEXITSTATUS(status));
        } else {
            printf("El proceso hijo ha finalizado de manera anormal\n");
        }
    } else {
        // Error al crear el proceso hijo
        perror("fork");
        exit(1);
    }
    
    return 0;
}
```

En este ejemplo, se crea un proceso hijo utilizando la función `fork`. El proceso hijo imprime un mensaje y sale de la ejecución con un código de salida de 1 utilizando la función `exit`. El proceso padre espera a que el proceso hijo finalice su ejecución utilizando la función `wait` y obtiene información sobre el estado de salida del proceso hijo utilizando la macro `WIFEXITED`. Si el proceso hijo finalizó de manera normal, se imprime el estado de salida del proceso hijo utilizando la macro `WEXITSTATUS`. Si el proceso hijo finalizó de manera anormal, se imprime un mensaje indicando que el proceso hijo finalizó de manera anormal.

#### Ejemplo 3: Manejando señales del proceso hijo

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int sig) {
    printf("Se recibió la señal %d\n", sig);
}

int main() {
pid_t pid = fork();
if (pid == 0) {
    // Este es el proceso hijo
    printf("Soy el proceso hijo\n");
    sleep(2);
    printf("Proceso hijo terminando de manera anormal\n");
    raise(SIGTERM);
} else if (pid > 0) {
    // Este es el proceso padre
    printf("Soy el proceso padre\n");
    signal(SIGTERM, handler);
    wait(NULL);
    printf("El proceso hijo ha finalizado\n");
} else {
    // Error al crear el proceso hijo
    perror("fork");
    exit(1);
}
return 0;
}
```
Se crea un proceso hijo utilizando la función `fork`. Si `fork` devuelve 0, se está ejecutando en el proceso hijo, de lo contrario, se está ejecutando en el proceso padre. 

En el proceso hijo, se imprime un mensaje indicando que es el proceso hijo y se espera 2 segundos utilizando la función `sleep`. Luego, se imprime otro mensaje indicando que el proceso hijo está terminando de manera anormal y se envía una señal `SIGTERM` al proceso padre utilizando la función `raise`.

En el proceso padre, se establece un manejador de señal para la señal `SIGTERM` utilizando la función `signal`. Luego, se espera a que el proceso hijo finalice su ejecución utilizando la función `wait`. La función `wait` suspende la ejecución del proceso padre hasta que el proceso hijo haya terminado. Si se pasa NULL como argumento, no se devuelve ninguna información sobre el estado de salida del proceso hijo. Después de que el proceso hijo ha finalizado, se imprime un mensaje indicando que el proceso hijo ha finalizado.

En caso de que haya un error al crear el proceso hijo, se imprime un mensaje de error utilizando la función `perror` y se sale del programa utilizando la función `exit`.

Por último, se devuelve 0 para indicar que el programa ha finalizado correctamente.

</details>

___

### [waitpid](../funciones/permitidas/waitpid.c)

```c
pid_t waitpid(pid_t pid, int *status, int options);
```

<details>
  <summary>Descripción</summary>

  Se utiliza para suspender la ejecución de un proceso padre hasta que uno de sus procesos hijos termine su ejecución. Esta función permite esperar específicamente a un proceso hijo particular o a cualquier proceso hijo, según los parámetros que se le pasen.

- `pid`: El ID del proceso hijo que se desea esperar. Puede tener diferentes valores:
  - Si `pid` es igual a -1, `waitpid` espera a cualquier proceso hijo.
  - Si `pid` es igual a 0, `waitpid` espera a cualquier proceso hijo cuyo grupo de procesos sea igual al del proceso padre.
  - Si `pid` es mayor que 0, `waitpid` espera al proceso hijo con ese ID.

- `status`: Un puntero a una variable entera donde `waitpid` almacenará el estado de salida del proceso hijo. Puede ser `NULL` si no se necesita el estado de salida.

- `options`: Un entero que puede contener varias opciones que afectan el comportamiento de `waitpid`. Puede ser `0` para ninguna opción o utilizar la macro `WNOHANG` para realizar una espera no bloqueante.

**Ejemplo 1: Esperar a cualquier proceso hijo**

En este ejemplo, se utiliza `waitpid` para esperar a que cualquier proceso hijo finalice su ejecución:

```c
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t childPid;
    int status;

    childPid = fork();

    if (childPid == 0) {
        // Código del proceso hijo
        printf("Proceso hijo ejecutándose\n");
        sleep(2);
        exit(0);
    } else if (childPid > 0) {
        // Código del proceso padre
        printf("Proceso padre esperando a que el hijo termine\n");
        waitpid(-1, &status, 0);
        printf("Proceso hijo terminado\n");
    } else {
        perror("Error al crear el proceso hijo");
        exit(1);
    }

    return 0;
}
```

</details>

___

### [wait3](../funciones/permitidas/wait3.c)


```c

pid_t wait3(int *status, int options, struct rusage *rusage);
```

<details>
  <summary>Descripción</summary>

 Se utiliza para suspender la ejecución de un proceso padre hasta que uno de sus procesos hijos termine su ejecución y obtener información detallada sobre su estado de salida. Esta función es similar a `waitpid`, pero proporciona más información sobre el estado de salida del proceso hijo.

- `status`: Un puntero a una variable entera donde `wait3` almacenará el estado de salida del proceso hijo. Puede ser `NULL` si no se necesita el estado de salida.

- `options`: Un entero que puede contener varias opciones que afectan el comportamiento de `wait3`. Puede ser `0` para ninguna opción o utilizar la macro `WNOHANG` para realizar una espera no bloqueante.

- `rusage`: Un puntero a una estructura `rusage` donde `wait3` almacenará información detallada sobre el uso de recursos del proceso hijo, como tiempo de CPU, uso de memoria, etc. Puede ser `NULL` si no se necesita esta información.

A continuación, se presentan dos ejemplos de código para ilustrar el uso de la función `wait3`:

**Ejemplo 1: Esperar a cualquier proceso hijo y obtener información de uso de recursos**

En este ejemplo, se utiliza `wait3` para esperar a que cualquier proceso hijo finalice su ejecución y obtener información detallada sobre su uso de recursos:

```c
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    pid_t childPid;
    int status;
    struct rusage usage;

    childPid = fork();

    if (childPid == 0) {
        // Código del proceso hijo
        printf("Proceso hijo ejecutándose\n");
        sleep(2);
        exit(0);
    } else if (childPid > 0) {
        // Código del proceso padre
        printf("Proceso padre esperando a que el hijo termine\n");
        wait3(&status, 0, &usage);
        printf("Proceso hijo terminado\n");
        printf("Uso de recursos del hijo: Tiempo de CPU = %ld segundos, Memoria = %ld KB\n",
               usage.ru_utime.tv_sec, usage.ru_maxrss);
    } else {
        perror("Error al crear el proceso hijo");
        exit(1);
    }

    return 0;
}
```

En este ejemplo, el proceso padre crea un proceso hijo utilizando `fork`. El proceso hijo imprime un mensaje y luego se suspende durante 2 segundos usando `sleep` antes de salir con `exit(0)`. Mientras tanto, el proceso padre llama a `wait3` para esperar a que el proceso hijo termine y obtener información detallada sobre su uso de recursos. El estado de salida del proceso hijo se almacena en la variable `status`, y la información de uso de recursos se almacena en la estructura `usage`. Después de que el proceso hijo termina, el proceso padre imprime un mensaje indicando que el proceso hijo ha terminado, junto con la información de uso de recursos obtenida.

</details>

___

### [wait4](../funciones/permitidas/wait4.c)

```c
pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);
```

<details>
  <summary>Descripción</summary>

La función `wait4` en C se utiliza para esperar a un proceso hijo específico o a cualquier proceso hijo, y permite obtener estadísticas de utilización de recursos y proporcionar opciones adicionales. Aquí tienes la sintaxis de la función `wait4`:

- `pid`: El ID del proceso hijo al que se desea esperar. Puede tener diferentes valores:
  - Si `pid` es igual a -1, `wait4` espera a cualquier proceso hijo.
  - Si `pid` es igual a 0, `wait4` espera a cualquier proceso hijo cuyo grupo de procesos sea igual al del proceso padre.
  - Si `pid` es mayor que 0, `wait4` espera al proceso hijo con ese ID.

- `status`: Un puntero a una variable entera donde `wait4` almacenará el estado de salida del proceso hijo. Puede ser `NULL` si no se necesita el estado de salida.

- `options`: Un entero que puede contener varias opciones que afectan el comportamiento de `wait4`. Puede ser `0` para ninguna opción o utilizar macros como `WNOHANG` para realizar una espera no bloqueante o `WUNTRACED` para esperar por procesos detenidos.

- `rusage`: Un puntero a una estructura `rusage` donde `wait4` almacenará información detallada sobre la utilización de recursos del proceso hijo, como tiempo de CPU, uso de memoria, etc. Puede ser `NULL` si no se necesita esta información.

Aquí tienes dos ejemplos de código para ilustrar el uso de la función `wait4`:

**Ejemplo 1: Esperar a cualquier proceso hijo y obtener información de utilización de recursos**

En este ejemplo, utilizamos `wait4` para esperar a que cualquier proceso hijo termine su ejecución y obtener información detallada sobre su utilización de recursos:

```c
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    pid_t childPid;
    int status;
    struct rusage usage;

    childPid = fork();

    if (childPid == 0) {
        // Código del proceso hijo
        printf("Proceso hijo ejecutándose\n");
        sleep(2);
        exit(0);
    } else if (childPid > 0) {
        // Código del proceso padre
        printf("Proceso padre esperando a que el hijo termine\n");
        wait4(-1, &status, 0, &usage);
        printf("Proceso hijo terminado\n");
        printf("Uso de recursos del hijo: Tiempo de CPU = %ld segundos, Memoria = %ld KB\n",
               usage.ru_utime.tv_sec, usage.ru_maxrss);
    } else {
        perror("Error al crear el proceso hijo");
        exit(1);
    }

    return 0
}
</details>
```
___

### [getcwd](../funciones/permitidas/getcwd.c)

```c
#include <unistd.h>

char *getcwd(char *buf, size_t size);
```

<details>
  <summary>Descripción</summary>

La función `getcwd` en C se utiliza para obtener el directorio de trabajo actual (Current Working Directory, CWD). Permite obtener la ruta absoluta del directorio en el que se encuentra actualmente el programa en ejecución.

- `buf`: Un puntero a un búfer de caracteres donde se almacenará el directorio de trabajo actual. Puede ser `NULL` para que la función asigne automáticamente un búfer.

- `size`: El tamaño del búfer especificado en `buf`.

La función `getcwd` devuelve un puntero a la cadena de caracteres que contiene el directorio de trabajo actual en caso de éxito, o `NULL` en caso de error.


**Ejemplo 1: Obtener el directorio de trabajo actual y mostrarlo por pantalla**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    char cwd[256];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Directorio de trabajo actual: %s\n", cwd);
    } else {
        perror("Error al obtener el directorio de trabajo actual");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `getcwd` para obtener el directorio de trabajo actual y lo almacenamos en el búfer `cwd`. Luego, imprimimos el directorio de trabajo actual por pantalla. Si la función `getcwd` falla, se imprime un mensaje de error utilizando `perror`.

**Ejemplo 2: Cambiar de directorio y obtener el nuevo directorio de trabajo actual**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    char cwd[256];

    if (chdir("/tmp") == 0) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Nuevo directorio de trabajo actual: %s\n", cwd);
        } else {
            perror("Error al obtener el directorio de trabajo actual");
            return 1;
        }
    } else {
        perror("Error al cambiar de directorio");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `chdir` para cambiar al directorio "/tmp". Luego, utilizamos `getcwd` para obtener el nuevo directorio de trabajo actual y lo almacenamos en el búfer `cwd`. Finalmente, imprimimos el nuevo directorio de trabajo actual por pantalla. Si alguna de las funciones `chdir` o `getcwd` falla, se imprime un mensaje de error utilizando `perror`.

</details>