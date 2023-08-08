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

```

</details>

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

___

### [chdir](../funciones/permitidas/chdir.c)

```c
#include <unistd.h>

int chdir(const char *path);
```

<details>
  <summary>Descripción</summary>

  La función `chdir` en C se utiliza para cambiar el directorio de trabajo actual (Current Working Directory, CWD) a un directorio especificado. Permite cambiar el directorio en el que se encuentra el programa en ejecución.

- `path`: Una cadena de caracteres que especifica la ruta del directorio al que se desea cambiar. Puede ser una ruta absoluta o relativa.

La función `chdir` devuelve 0 en caso de éxito, indicando que el cambio de directorio se realizó correctamente, o -1 en caso de error.

**Ejemplo 1: Cambiar al directorio "/tmp"**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    if (chdir("/tmp") == 0) {
        printf("Directorio cambiado correctamente\n");
    } else {
        perror("Error al cambiar el directorio");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `chdir` para cambiar al directorio "/tmp". Si el cambio de directorio se realiza correctamente, se imprime un mensaje de éxito por pantalla. Si `chdir` falla, se imprime un mensaje de error utilizando `perror`.

**Ejemplo 2: Cambiar al directorio especificado por el usuario**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    char path[256];

    printf("Ingrese el directorio al que desea cambiar: ");
    scanf("%s", path);

    if (chdir(path) == 0) {
        printf("Directorio cambiado correctamente\n");
    } else {
        perror("Error al cambiar el directorio");
        return 1;
    }

    return 0;
}
```

En este ejemplo, solicitamos al usuario que ingrese el directorio al que desea cambiar. Almacenamos la entrada del usuario en el búfer `path` y luego utilizamos `chdir` para cambiar al directorio especificado. Si el cambio de directorio se realiza correctamente, se imprime un mensaje de éxito por pantalla. Si `chdir` falla, se imprime un mensaje de error utilizando `perror`.

</details>

___

### [stat](../funciones/permitidas/stat.c)

```c
int stat(const char *path, struct stat *buf);
```

<details>
  <summary>Descripción</summary>

  La función `stat` en C se utiliza para obtener información sobre un archivo o directorio específico. Permite obtener detalles como los permisos, tamaño, tipo de archivo, información de tiempo, etc.

- `path`: Una cadena de caracteres que especifica la ruta del archivo o directorio sobre el cual se desea obtener información.

- `buf`: Un puntero a una estructura `stat` donde se almacenarán los detalles del archivo o directorio.

La función `stat` devuelve 0 en caso de éxito, indicando que se pudo obtener la información correctamente, o -1 en caso de error.

**Ejemplo 1: Obtener información de un archivo existente**

```c
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int	main(void)
{
	const char	*path;
	struct stat	fileStat;

	path = "archivo.txt";
	if (stat(path, &fileStat) == 0)
	{
		printf("Información del archivo:\n");
		printf("Tamaño: %lld bytes\n", fileStat.st_size);
		printf("Permisos: %o\n", fileStat.st_mode & 0777);
		printf("Último acceso: %s", ctime(&fileStat.st_atime));
		printf("Última modificación: %s", ctime(&fileStat.st_mtime));
		printf("Último cambio de estado: %s", ctime(&fileStat.st_ctime));
	}
	else
	{
		perror("Error al obtener información del archivo");
		return (1);
	}
	return (0);
}
```

En este ejemplo, utilizamos `stat` para obtener información del archivo "archivo.txt". Si la función `stat` se ejecuta correctamente, imprimimos detalles como el tamaño, los permisos y las fechas de último acceso, modificación y cambio de estado del archivo utilizando la estructura `stat` y las funciones de la biblioteca estándar.

**Ejemplo 2: Verificar la existencia de un directorio**

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *path = "directorio";
    struct stat dirStat;

    if (stat(path, &dirStat) == 0) {
        if (S_ISDIR(dirStat.st_mode)) {
            printf("El directorio existe\n");
        } else {
            printf("El directorio no existe\n");
        }
    } else {
        perror("Error al obtener información del directorio");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `stat` para obtener información del directorio "directorio". Si la función `stat` se ejecuta correctamente, verificamos si el archivo es un directorio utilizando la macro `S_ISDIR` y la información de permisos de la estructura `stat`. Luego, imprimimos un mensaje indicando si el directorio existe o no.

</details>

### [lstat](../funciones/permitidas/lstat.c)

```c

int lstat(const char *path, struct stat *buf);
```

<details>
  <summary>Descripción</summary>

La función `lstat` en C se utiliza para obtener información sobre un archivo o enlace simbólico específico, sin seguir el enlace simbólico para obtener información sobre el archivo al que apunta.

- `path`: Una cadena de caracteres que especifica la ruta del archivo o enlace simbólico sobre el cual se desea obtener información.

- `buf`: Un puntero a una estructura `stat` donde se almacenarán los detalles del archivo o enlace simbólico.

La función `lstat` devuelve 0 en caso de éxito, indicando que se pudo obtener la información correctamente, o -1 en caso de error.


**Ejemplo 1: Obtener información de un archivo regular**

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    const char *path = "archivo.txt";
    struct stat fileStat;

    if (lstat(path, &fileStat) == 0) {
        if (S_ISREG(fileStat.st_mode)) {
            printf("El archivo es un archivo regular\n");
            printf("Tamaño: %lld bytes\n", fileStat.st_size);
            printf("Permisos: %o\n", fileStat.st_mode & 0777);
        } else {
            printf("El archivo no es un archivo regular\n");
        }
    } else {
        perror("Error al obtener información del archivo");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `lstat` para obtener información del archivo regular "archivo.txt". Si la función `lstat` se ejecuta correctamente, verificamos si el archivo es un archivo regular utilizando la macro `S_ISREG` y la información de permisos de la estructura `stat`. Si es un archivo regular, imprimimos detalles como el tamaño y los permisos del archivo.

**Ejemplo 2: Obtener información de un enlace simbólico**

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    const char *path = "enlace_simbolico";
    struct stat fileStat;

    if (lstat(path, &fileStat) == 0) {
        if (S_ISLNK(fileStat.st_mode)) {
            printf("El archivo es un enlace simbólico\n");
            printf("Tamaño: %ld bytes\n", fileStat.st_size);
        } else {
            printf("El archivo no es un enlace simbólico\n");
        }
    } else {
        perror("Error al obtener información del enlace simbólico");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `lstat` para obtener información del enlace simbólico "enlace_simbolico". Si la función `lstat` se ejecuta correctamente, verificamos si el archivo es un enlace simbólico utilizando la macro `S_ISLNK` y la información de permisos de la estructura `stat`. Si es un enlace simbólico, imprimimos el tamaño del enlace simbólico.

</details>

___

### [fstat](../funciones/permitidas/fstat.c)

```c
int fstat(int fd, struct stat *buf);
```

<details>
  <summary>Descripción</summary>

La función `fstat` en C se utiliza para obtener información sobre un descriptor de archivo específico, proporcionando detalles sobre el archivo asociado al descriptor.

- `fd`: El descriptor de archivo del cual se desea obtener información.

- `buf`: Un puntero a una estructura `stat` donde se almacenarán los detalles del archivo asociado al descriptor.

La función `fstat` devuelve 0 en caso de éxito, indicando que se pudo obtener la información correctamente, o -1 en caso de error.

**Ejemplo 1: Obtener información de un archivo abierto**

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    struct stat fileStat;
    if (fstat(fd, &fileStat) == 0) {
        if (S_ISREG(fileStat.st_mode)) {
            printf("El archivo es un archivo regular\n");
            printf("Tamaño: %ld bytes\n", fileStat.st_size);
            printf("Permisos: %o\n", fileStat.st_mode & 0777);
        } else {
            printf("El archivo no es un archivo regular\n");
        }
    } else {
        perror("Error al obtener información del archivo");
        return 1;
    }

    close(fd);

    return 0;
}
```

En este ejemplo, abrimos el archivo "archivo.txt" utilizando la función `open` y obtenemos un descriptor de archivo `fd`. Luego, utilizamos `fstat` para obtener información del archivo asociado al descriptor. Si la función `fstat` se ejecuta correctamente, verificamos si el archivo es un archivo regular utilizando la macro `S_ISREG` y la información de permisos de la estructura `stat`. Si es un archivo regular, imprimimos detalles como el tamaño y los permisos del archivo.

**Ejemplo 2: Obtener información de la entrada estándar**

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat fileStat;
    if (fstat(STDIN_FILENO, &fileStat) == 0) {
        if (S_ISCHR(fileStat.st_mode)) {
            printf("El descriptor de archivo se refiere a una terminal\n");
        } else {
            printf("El descriptor de archivo no se refiere a una terminal\n");
        }
    } else {
        perror("Error al obtener información del descriptor de archivo");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `fstat` para obtener información del descriptor de archivo `STDIN_FILENO`, que representa la entrada estándar. Si la función `fstat` se ejecuta correctamente, verificamos si el descriptor de archivo se refiere a una terminal utilizando la macro `S_ISCHR` y la información de permisos de la estructura `stat`. Si es una terminal, imprimimos un mensaje indicando que el descriptor de archivo se refiere a una terminal.

</details>

___

### [unlink](../funciones/permitidas/unlink.c)

```c
int unlink(const char *pathname);
```

<details>
  <summary>Descripción</summary>

La función `unlink` en C se utiliza para eliminar un archivo del sistema de archivos.

- `pathname`: Una cadena de caracteres que especifica la ruta y nombre del archivo que se desea eliminar.

La función `unlink` devuelve 0 en caso de éxito, indicando que el archivo se eliminó correctamente, o -1 en caso de error.

**Ejemplo 1: Eliminar un archivo existente**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *filename = "archivo.txt";
    
    if (unlink(filename) == 0) {
        printf("Archivo eliminado exitosamente.\n");
    } else {
        perror("Error al eliminar el archivo");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `unlink` para eliminar el archivo "archivo.txt". Si la función `unlink` se ejecuta correctamente, imprimimos un mensaje indicando que el archivo se eliminó exitosamente. En caso de error, utilizamos `perror` para imprimir un mensaje de error detallado.

**Ejemplo 2: Eliminar varios archivos**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *filenames[] = {"archivo1.txt", "archivo2.txt", "archivo3.txt"};
    int numFiles = sizeof(filenames) / sizeof(filenames[0]);

    for (int i = 0; i < numFiles; i++) {
        if (unlink(filenames[i]) == 0) {
            printf("Archivo %s eliminado exitosamente.\n", filenames[i]);
        } else {
            perror("Error al eliminar el archivo");
            return 1;
        }
    }

    return 0;
}
```

En este ejemplo, utilizamos `unlink` en un bucle para eliminar varios archivos de una vez. Los nombres de los archivos se almacenan en un array `filenames`. Iteramos sobre el array y, para cada archivo, utilizamos `unlink` para eliminarlo. Si la función `unlink` se ejecuta correctamente, imprimimos un mensaje indicando que el archivo se eliminó exitosamente. En caso de error, utilizamos `perror` para imprimir un mensaje de error detallado.

</details>


### [execve](../funciones/permitidas/execve.c)

```c
int execve(const char *pathname, char *const argv[], char *const envp[]);
```

<details>
  <summary>Descripción</summary>

La función `execve` se utiliza para reemplazar la imagen del proceso actual con una nueva imagen de programa. Permite ejecutar un programa específico con argumentos y variables de entorno personalizados.

- `pathname`: Una cadena de caracteres que especifica la ruta y nombre del programa que se desea ejecutar.

- `argv`: Un arreglo de cadenas de caracteres que representan los argumentos pasados al programa. El último elemento del arreglo debe ser `NULL`.

- `envp`: Un arreglo de cadenas de caracteres que representan las variables de entorno pasadas al programa. El último elemento del arreglo debe ser `NULL`.

La función `execve` devuelve -1 en caso de error y, en caso de éxito, no se devuelve ningún valor, ya que el programa actual es reemplazado por el nuevo programa ejecutado.

Aquí tienes dos ejemplos de código que ilustran el uso de la función `execve`:

**Ejemplo 1: Ejecutar un programa con argumentos personalizados**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    char *const argv[] = {"ls", "-l", NULL};
    char *const envp[] = {NULL};

    if (execve("/bin/ls", argv, envp) == -1) {
        perror("Error al ejecutar el programa");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `execve` para ejecutar el programa `ls` con la opción `-l`. Definimos un arreglo `argv` que contiene los argumentos pasados al programa `ls`, donde el primer elemento es el nombre del programa (`ls`), el segundo elemento es la opción `-l` y el último elemento es `NULL`. El arreglo `envp` se define como `NULL` ya que no pasamos variables de entorno personalizadas. Si la función `execve` se ejecuta correctamente, el programa actual será reemplazado por el programa `ls` con los argumentos personalizados.

**Ejemplo 2: Ejecutar un programa con variables de entorno personalizadas**

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    char *const argv[] = {"echo", "Hello, World!", NULL};
    char *const envp[] = {"CUSTOM_VAR=42 Barcelona", NULL};

    if (execve("/bin/echo", argv, envp) == -1) {
        perror("Error al ejecutar el programa");
        return 1;
    }

    return 0;
}
```

En este ejemplo, utilizamos `execve` para ejecutar el programa `echo` con el argumento `"Hello, World!"` y una variable de entorno personalizada `"CUSTOM_VAR"` establecida en `"42 Barcelona"`. Definimos el arreglo `argv` con el nombre del programa y el argumento, y el arreglo `envp` con la variable de entorno personalizada. Si la función `execve` se ejecuta correctamente, el programa actual será reemplazado por el programa `echo` con el argumento y la variable de entorno personalizados.

Ten en cuenta que el programa que se intenta ejecutar debe tener los permisos de ejecución adecuados y la ruta completa debe ser especificada en `pathname`. Además, debes tener cuidado al utilizar `

</details>

___

### [dup](../funciones/permitidas/dup.c)

```c
int dup(int oldfd);
```

<details>
  <summary>Descripción</summary>

La función `dup` en C se utiliza para duplicar un descriptor de archivo existente. Crea una nueva entrada en la tabla de descriptores de archivo del proceso y devuelve un nuevo descriptor de archivo que hace referencia al mismo archivo o flujo que el descriptor original.

- `oldfd`: El descriptor de archivo que se desea duplicar.

La función `dup` devuelve el nuevo descriptor de archivo en caso de éxito, o -1 en caso de error.

Aquí tienes dos ejemplos de código que ilustran el uso de la función `dup`:

**Ejemplo 1: Duplicar un descriptor de archivo**

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int newfd = dup(fd);
    if (newfd == -1) {
        perror("Error al duplicar el descriptor de archivo");
        return 1;
    }

    printf("Descriptor de archivo original: %d\n", fd);
    printf("Nuevo descriptor de archivo: %d\n", newfd);

    close(fd);
    close(newfd);

    return 0;
}
```

En este ejemplo, abrimos el archivo "archivo.txt" utilizando la función `open` y obtenemos un descriptor de archivo `fd`. Luego, utilizamos `dup` para duplicar el descriptor `fd` y obtener un nuevo descriptor `newfd`. Imprimimos ambos descriptores de archivo para verificar que son diferentes. Luego, cerramos ambos descriptores de archivo.

</details>

___

### [dup2](../funciones/dup2.c)


```c
int dup2(int oldfd, int newfd);
```

<details>
  <summary>Descripción</summary>

La función `dup2` en C se utiliza para duplicar un descriptor de archivo existente en otro descriptor de archivo específico. Permite especificar un descriptor de archivo de destino en lugar de dejar que el sistema operativo seleccione automáticamente el siguiente descriptor disponible.

- `oldfd`: El descriptor de archivo que se desea duplicar.
- `newfd`: El descriptor de archivo de destino donde se colocará la duplicación.

La función `dup2` devuelve el nuevo descriptor de archivo en caso de éxito, o -1 en caso de error.


**Ejemplo 1: Redirigir la salida estándar a un archivo**

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("Error al redirigir la salida estándar");
        return 1;
    }

    printf("Este texto se escribirá en el archivo salida.txt\n");

    close(fd);

    return 0;
}
```

En este ejemplo, abrimos el archivo "salida.txt" utilizando la función `open` en modo de escritura (`O_WRONLY`). Si el archivo no existe, se crea. Si ya existe, se trunca a un tamaño de cero. Obtenemos un descriptor de archivo `fd` para este archivo.

Luego, utilizamos `dup2` para duplicar el descriptor `fd` y asignarlo al descriptor de archivo de la salida estándar (`STDOUT_FILENO`). De esta manera, cualquier salida escrita en `stdout` se redirigirá al archivo "salida.txt". En este ejemplo, utilizamos `printf` para imprimir un mensaje, pero en lugar de mostrarse en la consola, se escribirá en el archivo.

Cerramos el descriptor de archivo `fd` ya que no lo necesitamos más.

**Ejemplo 2: Duplicar un descriptor de archivo en un descriptor específico**

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int newfd = open("copia.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (newfd == -1) {
        perror("Error al abrir el archivo de destino");
        return 1;
    }

    if (dup2(fd, newfd) == -1) {
        perror("Error al duplicar el descriptor de archivo");
        return 1;
    }

    printf("Archivo duplicado exitosamente.\n");

    close(fd);
    close(newfd);

    return 0;
}
```

En este ejemplo, abrimos el archivo "archivo.txt" en modo de lectura (`O_RDONLY`) y obtenemos un descriptor de archivo `fd`. Luego, abrimos el archivo "copia.txt" en modo de escritura (`O_WRONLY | O_CREAT | O_TRUNC`) y obtenemos un nuevo descriptor de archivo `new
</details>

___

### [pipe](../funciones/permitidas/pipe.c)

<details>
  <summary>Descripción</summary>

La función `pipe` se utiliza para crear una tubería o canal de comunicación unidireccional entre dos procesos. Permite la transferencia de datos de un proceso a otro, donde un proceso actúa como el escritor (productor) y el otro proceso actúa como el lector (consumidor) de los datos.

**Ejemplo 1: Comunicación entre procesos padre e hijo**

En este ejemplo, se crea una tubería entre un proceso padre y un proceso hijo. El proceso hijo enviará un mensaje al proceso padre a través de la tubería, y el proceso padre lo leerá y lo imprimirá en la salida estándar.

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd[2]; // Arreglo de descriptores de archivo para la tubería
    char message[] = "Hola desde el proceso hijo";

    if (pipe(fd) == -1) {
        perror("Error al crear la tubería");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Proceso hijo
        close(fd[0]); // Cierra el extremo de lectura de la tubería

        write(fd[1], message, strlen(message) + 1); // Escribe el mensaje en la tubería

        close(fd[1]); // Cierra el extremo de escritura de la tubería

        exit(EXIT_SUCCESS);
    } else {
        // Proceso padre
        close(fd[1]); // Cierra el extremo de escritura de la tubería

        char received_message[100];
        read(fd[0], received_message, sizeof(received_message)); // Lee el mensaje de la tubería

        printf("Mensaje recibido: %s\n", received_message);

        close(fd[0]); // Cierra el extremo de lectura de la tubería
    }

    return 0;
}
```

En este ejemplo, se utiliza `pipe` para crear la tubería en el arreglo `fd`. El proceso padre cierra el extremo de escritura de la tubería (`fd[1]`) y lee el mensaje del extremo de lectura de la tubería (`fd[0]`). El proceso hijo cierra el extremo de lectura de la tubería (`fd[0]`) y escribe el mensaje en el extremo de escritura de la tubería (`fd[1]`).

**Ejemplo 2: Comunicación entre procesos mediante redirección**

En este ejemplo, se redirige la salida de un proceso hijo hacia la entrada de otro proceso padre utilizando `pipe`.

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2]; // Arreglo de descriptores de archivo para la tubería

    if (pipe(fd) == -1) {
        perror("Error al crear la tubería");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Proceso hijo
                close(fd[0]); // Cierra el extremo de lectura de la tubería

        dup2(fd[1], STDOUT_FILENO); // Redirige la salida estándar al extremo de escritura de la tubería

        // Ejecuta el comando 'ls' y redirige su salida al proceso padre
        execlp("ls", "ls", NULL);

        close(fd[1]); // Cierra el extremo de escritura de la tubería

        exit(EXIT_SUCCESS);
    } else {
        // Proceso padre
        close(fd[1]); // Cierra el extremo de escritura de la tubería

        dup2(fd[0], STDIN_FILENO); // Redirige la entrada estándar al extremo de lectura de la tubería

        // Lee y muestra la salida del proceso hijo
        char buffer[256];
        ssize_t bytesRead;
        while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytesRead);
        }

        close(fd[0]); // Cierra el extremo de lectura de la tubería
    }

    return 0;
}
```

En este ejemplo, se utiliza `pipe` para crear la tubería en el arreglo `fd`. El proceso hijo cierra el extremo de lectura de la tubería (`fd[0]`) y redirige su salida estándar al extremo de escritura de la tubería (`fd[1]`) utilizando `dup2`. Luego, ejecuta el comando "ls" utilizando `execlp`, lo cual redirige la salida del comando hacia el proceso padre. El proceso padre cierra el extremo de escritura de la tubería (`fd[1]`) y redirige su entrada estándar al extremo de lectura de la tubería (`fd[0]`) utilizando `dup2`. Luego, lee los datos del proceso hijo desde la entrada estándar y los muestra en la salida estándar.

</details>

___

### [opendir](../funciones/permitidas/opendir.c)

<details>
  <summary>Descripción</summary>

Se utiliza para abrir un directorio y obtener un puntero a una estructura `DIR` que representa dicho directorio. Proporciona una forma de acceder a los archivos y subdirectorios contenidos en el directorio abierto.

**Ejemplo 1: Listar archivos de un directorio**

En este ejemplo, se utiliza `opendir` para abrir un directorio y luego se recorren los archivos y subdirectorios contenidos en él utilizando la función `readdir`.

```c
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("directorio/"); // Reemplaza "directorio/" con la ruta de tu directorio

    if (dir == NULL) {
        perror("Error al abrir el directorio");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}
```

En este ejemplo, se abre el directorio utilizando `opendir`, pasando la ruta del directorio como argumento. Si `opendir` devuelve un puntero nulo, indica que hubo un error al abrir el directorio. Luego, se utiliza un bucle while y la función `readdir` para obtener cada entrada del directorio (`struct dirent`) y mostrar el nombre de archivo o subdirectorio (`d_name`) en la salida estándar. Finalmente, se cierra el directorio utilizando `closedir`.

**Ejemplo 2: Verificar si un directorio existe**

En este ejemplo, se utiliza `opendir` para intentar abrir un directorio. Si `opendir` tiene éxito, significa que el directorio existe; de lo contrario, indica que no existe.

```c
#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>

bool directoryExists(const char *path) {
    DIR *dir = opendir(path);

    if (dir) {
        closedir(dir);
        return true;
    }

    return false;
}

int main() {
    const char *path = "directorio/"; // Reemplaza "directorio/" con la ruta de tu directorio

    if (directoryExists(path)) {
        printf("El directorio existe.\n");
    } else {
        printf("El directorio no existe.\n");
    }

    return 0;
}
```

En este ejemplo, se define una función `directoryExists` que utiliza `opendir` para intentar abrir el directorio especificado por la ruta. Si `opendir` tiene éxito, se cierra el directorio y la función devuelve `true`, lo que indica que el directorio existe. Si `opendir` devuelve un puntero nulo, la función devuelve `false`, lo que indica que el directorio no existe. En la función `main`, se llama a `directoryExists` para verificar si el directorio existe y se muestra un mensaje apropiado en la salida estándar.

</details>

___

### [readdir](../funciones/readdir.c)

<details>
  <summary>Descripción</summary>

Se utiliza para leer las entradas de un directorio abierto previamente utilizando la función `opendir`. Proporciona una forma de acceder a los archivos y subdirectorios contenidos en el directorio.

**Ejemplo 1: Listar archivos de un directorio**

Este ejemplo muestra cómo utilizar `readdir` para obtener y mostrar los nombres de los archivos y subdirectorios contenidos en un directorio.

```c
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("directorio/"); // Reemplaza "directorio/" con la ruta de tu directorio

    if (dir == NULL) {
        perror("Error al abrir el directorio");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}
```

En este ejemplo, se abre el directorio utilizando `opendir`, pasando la ruta del directorio como argumento. Si `opendir` devuelve un puntero nulo, indica que hubo un error al abrir el directorio. Luego, se utiliza un bucle while para llamar a `readdir` en cada iteración y obtener la siguiente entrada del directorio (`struct dirent`). El nombre del archivo o subdirectorio se accede a través del miembro `d_name` de la estructura `dirent`. En este ejemplo, simplemente se muestra el nombre en la salida estándar. Finalmente, se cierra el directorio utilizando `closedir`.

**Ejemplo 2: Filtrar archivos por extensión**

Este ejemplo muestra cómo utilizar `readdir` para filtrar y mostrar solo los archivos con una extensión específica en un directorio.

```c
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    const char *extension = ".txt"; // Extensión a filtrar

    dir = opendir("directorio/"); // Reemplaza "directorio/" con la ruta de tu directorio

    if (dir == NULL) {
        perror("Error al abrir el directorio");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && strstr(entry->d_name, extension) != NULL) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}
```

En este ejemplo, se abre el directorio utilizando `opendir`, pasando la ruta del directorio como argumento. Si `opendir` devuelve un puntero nulo, indica que hubo un error al abrir el directorio. Luego, se utiliza un bucle while para llamar a `readdir` en cada iteración y obtener la siguiente entrada del directorio (`struct dirent`). Se utiliza la condición `entry->d_type == DT_REG` para filtrar solo los archivos regulares (no directorios ni enlaces simbólicos). Luego, se utiliza `strstr` para verificar si el nombre del archivo contiene la extensión deseada. Si se cumple ambas condiciones, se muestra el nombre del archivo en la salida estándar. Finalmente, se cierra el directorio utilizando `
</details>

___

### [closedir](../funciones/permitidas/closedir.c)

<details>
  <summary>Descripción</summary>

  La función `closedir` se utiliza para cerrar un directorio previamente abierto utilizando la función `opendir`. Permite liberar los recursos asociados al directorio después de haber terminado de trabajar con él.

**Ejemplo 1: Listar archivos de un directorio**

```c
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("directorio/"); // Reemplaza "directorio/" con la ruta de tu directorio

    if (dir == NULL) {
        perror("Error al abrir el directorio");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir); // Cerrar el directorio

    return 0;
}
```

En este ejemplo, se abre el directorio utilizando `opendir`, pasando la ruta del directorio como argumento. Si `opendir` devuelve un puntero nulo, indica que hubo un error al abrir el directorio. Luego, se utiliza un bucle while y la función `readdir` para obtener cada entrada del directorio (`struct dirent`) y mostrar el nombre de archivo o subdirectorio (`d_name`) en la salida estándar. Finalmente, se cierra el directorio utilizando `closedir`.

**Ejemplo 2: Verificar si un directorio existe**

En este ejemplo, se utiliza `opendir` para intentar abrir un directorio y se verifica si el directorio existe utilizando `closedir`.

```c
#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>

bool directoryExists(const char *path) {
    DIR *dir = opendir(path);

    if (dir) {
        closedir(dir); // Cerrar el directorio
        return true;
    }

    return false;
}

int main() {
    const char *path = "directorio/"; // Reemplaza "directorio/" con la ruta de tu directorio

    if (directoryExists(path)) {
        printf("El directorio existe.\n");
    } else {
        printf("El directorio no existe.\n");
    }

    return 0;
}
```

En este ejemplo, se define una función `directoryExists` que utiliza `opendir` para intentar abrir el directorio especificado por la ruta. Si `opendir` tiene éxito, se cierra el directorio utilizando `closedir` y la función devuelve `true`, lo que indica que el directorio existe. Si `opendir` devuelve un puntero nulo, la función devuelve `false`, lo que indica que el directorio no existe. En la función `main`, se llama a `directoryExists` para verificar si el directorio existe y se muestra un mensaje apropiado en la salida estándar.

</details>

___

### [strerror](../funciones/permitidas/strerror.c)

<details>
  <summary>Descripción</summary>

La función `strerror` se utiliza para obtener una cadena de caracteres que describe el último error ocurrido en el programa. Proporciona una forma de obtener información más detallada sobre el motivo de un error específico.

**Ejemplo 1: Manejo de errores en la apertura de un archivo**

```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE *file = fopen("archivo_no_existente.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error al abrir el archivo: %s\n", strerror(errno));
        return 1;
    }

    // Resto del código para trabajar con el archivo

    fclose(file);

    return 0;
}
```

En este ejemplo, se intenta abrir un archivo llamado "archivo_no_existente.txt" en modo lectura utilizando `fopen`. Si `fopen` devuelve un puntero nulo, indica que hubo un error al abrir el archivo. Luego, se utiliza `strerror` para obtener una cadena de caracteres que describe el error ocurrido, y se muestra este mensaje de error en la salida de error estándar utilizando `fprintf`. El código `errno` es una variable global que contiene el número de error del último error ocurrido. Al pasar `errno` a `strerror`, se obtiene una cadena de caracteres con una descripción legible del error. Finalmente, el programa retorna con un código de error.

**Ejemplo 2: Manejo de errores en la asignación de memoria**

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int *ptr = malloc(1000000000000); // Intenta asignar una cantidad excesiva de memoria

    if (ptr == NULL) {
        fprintf(stderr, "Error al asignar memoria: %s\n", strerror(errno));
        return 1;
    }

    // Resto del código para trabajar con el puntero asignado

    free(ptr);

    return 0;
}
```

En este ejemplo, se intenta asignar una cantidad excesiva de memoria utilizando `malloc`. Si `malloc` devuelve un puntero nulo, indica que hubo un error en la asignación de memoria. Luego, se utiliza `strerror` para obtener una cadena de caracteres que describe el error ocurrido, y se muestra este mensaje de error en la salida de error estándar utilizando `fprintf`. Al igual que en el ejemplo anterior, se utiliza `errno` para obtener el número de error y pasarlo a `strerror`. Finalmente, el programa retorna con un código de error.

</details>

___

### [perror](../funciones/permitidas/perror.c)

<details>
  <summary>Descripción</summary>

  La función `perror` se utiliza para imprimir un mensaje de error descriptivo basado en el valor de `errno`. Proporciona una forma conveniente de mostrar información sobre el último error ocurrido en el programa.

**Ejemplo 1: Manejo de errores en la apertura de un archivo**

En este ejemplo, se utiliza `perror` para imprimir un mensaje de error descriptivo cuando ocurre un error durante la apertura de un archivo.

```c
#include <stdio.h>
#include <errno.h>

int main() {
    FILE *file = fopen("archivo_no_existente.txt", "r");

    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Resto del código para trabajar con el archivo

    fclose(file);

    return 0;
}
```

En este ejemplo, se intenta abrir un archivo llamado "archivo_no_existente.txt" en modo lectura utilizando `fopen`. Si `fopen` devuelve un puntero nulo, indica que hubo un error al abrir el archivo. Luego, se llama a `perror` pasando un mensaje descriptivo como argumento. `perror` imprimirá este mensaje seguido de una descripción del error específico basado en el valor de `errno`. Finalmente, el programa retorna con un código de error.

</details>

___

### [isatty](../funciones/permitidas/isatty.c)

<details>
  <summary>Descripción</summary>

  La función `isatty` se utiliza para determinar si un descriptor de archivo se asocia con un terminal interactivo. Devuelve un valor distinto de cero si el descriptor de archivo se asocia con un terminal, y devuelve 0 si no es así.

**Ejemplo 1: Comprobación de la entrada estándar**

En este ejemplo, se utiliza `isatty` para determinar si la entrada estándar (`stdin`) se asocia con un terminal.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    if (isatty(fileno(stdin))) {
        printf("La entrada estándar es un terminal interactivo.\n");
    } else {
        printf("La entrada estándar no es un terminal interactivo.\n");
    }

    return 0;
}
```

En este ejemplo, se utiliza `fileno` para obtener el descriptor de archivo correspondiente a la entrada estándar (`stdin`), y luego se pasa este descriptor de archivo a `isatty`. Si `isatty` devuelve un valor distinto de cero, indica que `stdin` está asociado con un terminal, por lo que se muestra un mensaje apropiado en la salida estándar.

**Ejemplo 2: Comprobación de la salida estándar**

En este ejemplo, se utiliza `isatty` para determinar si la salida estándar (`stdout`) se asocia con un terminal.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    if (isatty(fileno(stdout))) {
        printf("La salida estándar es un terminal interactivo.\n");
    } else {
        printf("La salida estándar no es un terminal interactivo.\n");
    }

    return 0;
}
```

En este ejemplo, se utiliza `fileno` para obtener el descriptor de archivo correspondiente a la salida estándar (`stdout`), y luego se pasa este descriptor de archivo a `isatty`. Si `isatty` devuelve un valor distinto de cero, indica que `stdout` está asociado con un terminal, por lo que se muestra un mensaje apropiado en la salida estándar.

Estos ejemplos ilustran el uso básico de la función `isatty` en C para determinar si un descriptor de archivo está asociado con un terminal interactivo. Esto puede ser útil para realizar acciones diferentes según si el programa se está ejecutando en un entorno interactivo o en un contexto no interactivo, como en un redireccionamiento de entrada/salida.
</details>

___

### [ttyname](../funciones/permitidas/ttyname.c)

<details>
  <summary>Descripción</summary>

La función `ttyname` se utiliza para obtener el nombre del dispositivo de terminal asociado con un descriptor de archivo de terminal. Devuelve un puntero al nombre del dispositivo de terminal si se puede determinar, y devuelve `NULL` si no se puede determinar. 

**Ejemplo 1: Obtención del nombre del terminal interactivo de entrada**

En este ejemplo, se utiliza `ttyname` para obtener el nombre del dispositivo de terminal asociado con la entrada estándar (`stdin`) si `stdin` está asociado con un terminal.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char *name = ttyname(fileno(stdin));
    if (name != NULL) {
        printf("El nombre del dispositivo de terminal de entrada es: %s\n", name);
    } else {
        printf("La entrada estándar no está asociada con un dispositivo de terminal.\n");
    }

    return 0;
}
```

En este ejemplo, se utiliza `fileno` para obtener el descriptor de archivo correspondiente a la entrada estándar (`stdin`), y luego se pasa este descriptor de archivo a `ttyname`. Si `ttyname` devuelve un puntero distinto de `NULL`, indica que `stdin` está asociado con un terminal, por lo que se muestra el nombre del dispositivo de terminal en la salida estándar.

**Ejemplo 2: Obtención del nombre del terminal interactivo de salida**

En este ejemplo, se utiliza `ttyname` para obtener el nombre del dispositivo de terminal asociado con la salida estándar (`stdout`) si `stdout` está asociado con un terminal.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char *name = ttyname(fileno(stdout));
    if (name != NULL) {
        printf("El nombre del dispositivo de terminal de salida es: %s\n", name);
    } else {
        printf("La salida estándar no está asociada con un dispositivo de terminal.\n");
    }

    return 0;
}
```

En este ejemplo, se utiliza `fileno` para obtener el descriptor de archivo correspondiente a la salida estándar (`stdout`), y luego se pasa este descriptor de archivo a `ttyname`. Si `ttyname` devuelve un puntero distinto de `NULL`, indica que `stdout` está asociado con un terminal, por lo que se muestra el nombre del dispositivo de terminal en la salida estándar.

</details>

___

### [ttyslot](../funciones/permitidas/ttyslot.c)

<details>
  <summary>Descripción</summary>

La función `ttyslot` se utiliza para obtener el número de la ranura (slot) en la tabla de terminales del archivo `/etc/ttys`. Esta función se utiliza principalmente en sistemas Unix para determinar el índice del terminal asociado con el proceso actual.


En este ejemplo, se utiliza `ttyslot` para obtener el número de ranura del terminal actual y luego se utiliza ese número para obtener información adicional del terminal utilizando la función `getttyent`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ttyent.h>

int main() {
    int slot = ttyslot();
    if (slot == -1) {
        perror("Error al obtener el número de ranura del terminal");
        return 1;
    }

    struct ttyent *tty = getttyent();
    if (tty == NULL) {
        perror("Error al obtener la información del terminal");
        return 1;
    }

    printf("El terminal asociado con la ranura %d es: %s\n", slot, tty->ty_name);

    endttyent();

    return 0;
}
```

En este ejemplo, se obtiene el número de ranura del terminal actual utilizando `ttyslot`. Luego, se utiliza ese número para llamar a `getttyent`, que devuelve un puntero a una estructura `ttyent` que contiene información adicional del terminal asociado con la ranura. Si `getttyent` devuelve `NULL`, indica que ocurrió un error al obtener la información del terminal. En caso contrario, se muestra el nombre del terminal en la salida estándar utilizando `tty->ty_name`. Finalmente, se llama a `endttyent` para cerrar el archivo `/etc/ttys` y liberar los recursos.

</details>

___

### [ioctl](../funciones/permitidas/ioctl.c)

<details>
  <summary>Descripción</summary>

La función `ioctl` en C se utiliza para realizar operaciones de E/S de bajo nivel en un archivo o dispositivo. Esta función se utiliza principalmente en sistemas Unix para enviar comandos a dispositivos y controladores de dispositivos.

**Ejemplo 1: Cambiar el tamaño de la ventana de terminal**

En este ejemplo, se utiliza `ioctl` para cambiar el tamaño de la ventana de terminal en la que se está ejecutando el programa.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main() {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
        perror("Error al obtener el tamaño de la ventana de terminal");
        return 1;
    }

    printf("El tamaño actual de la ventana de terminal es %d columnas x %d filas\n", ws.ws_col, ws.ws_row);

    ws.ws_col = 80;
    ws.ws_row = 24;

    if (ioctl(STDOUT_FILENO, TIOCSWINSZ, &ws) == -1) {
        perror("Error al cambiar el tamaño de la ventana de terminal");
        return 1;
    }

    printf("El tamaño de la ventana de terminal ha sido cambiado a %d columnas x %d filas\n", ws.ws_col, ws.ws_row);

    return 0;
}
```

En este ejemplo, se llama a `ioctl` dos veces: la primera para obtener el tamaño actual de la ventana de terminal utilizando el comando `TIOCGWINSZ`, y la segunda para cambiar el tamaño de la ventana de terminal utilizando el comando `TIOCSWINSZ`. Si `ioctl` devuelve -1, indica que ocurrió un error, por lo que se imprime un mensaje de error utilizando `perror`. Si `ioctl` se ejecuta correctamente, se muestra el tamaño de la ventana de terminal actual y el nuevo tamaño después de cambiarlo.

</details>

___

### [getenv](../funciones/permitidas/getenv.c)

<details>
  <summary>Descripción</summary>

La función `getenv` en C se utiliza para obtener el valor de una variable de entorno. Toma como argumento el nombre de la variable de entorno y devuelve un puntero al valor asociado si la variable existe, o `NULL` si no existe. A continuación, te proporcionaré dos ejemplos de cómo usar la función `getenv` en código.

**Ejemplo 1: Obtención del valor de una variable de entorno existente**

En este ejemplo, se utiliza `getenv` para obtener el valor de la variable de entorno `HOME`, que generalmente almacena la ruta del directorio de inicio del usuario.

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *home = getenv("HOME");
	char *username = getenv("LOGNAME");
	if (home != NULL)
	{
		printf("El valor de la variable HOME es: %s\n", home);
		printf("El valor de la variable LOGNAME es: %s\n", username);
	}
	else
		printf("La variable HOME no está definida.\n");

	return 0;
}
```

En este ejemplo, se llama a `getenv` con el argumento `"HOME"` para obtener el valor de la variable de entorno `HOME`. Si `getenv` devuelve un puntero distinto de `NULL`, indica que la variable de entorno existe y se muestra su valor en la salida estándar. Si `getenv` devuelve `NULL`, indica que la variable de entorno no está definida.

</details>

___

### [tcsetattr](../funciones/permitidas/tcsetattr.c)

<details>
  <summary>Descripción</summary>

La función `tcsetattr` en C se utiliza para establecer la configuración de un terminal asociado a un descriptor de archivo. Permite configurar varios aspectos del terminal, como la velocidad de transmisión, el control de flujo, los caracteres de terminal especiales, entre otros.

**Ejemplo 1: Configuración básica del terminal**

En este ejemplo, se utiliza `tcsetattr` para establecer una configuración básica del terminal, como la velocidad de transmisión y los modos de línea.

```c
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int main() {
    struct termios new_attr;
    if (tcgetattr(STDIN_FILENO, &new_attr) == -1) {
        perror("Error al obtener la configuración del terminal");
        return 1;
    }

    // Configuración básica del terminal
    new_attr.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    new_attr.c_oflag &= ~OPOST;
    new_attr.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    new_attr.c_cflag &= ~(CSIZE | PARENB);
    new_attr.c_cflag |= CS8;

    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_attr) == -1) {
        perror("Error al establecer la configuración del terminal");
        return 1;
    }

    printf("Configuración del terminal establecida correctamente.\n");

    return 0;
}
```

En este ejemplo, se obtiene la configuración actual del terminal utilizando `tcgetattr` y se almacena en la estructura `new_attr`. Luego, se modifican los diferentes campos de `new_attr` para establecer la configuración deseada del terminal. Finalmente, se llama a `tcsetattr` con el flag `TCSANOW` para aplicar la configuración de forma inmediata. Si `tcsetattr` devuelve -1, indica que ocurrió un error, por lo que se imprime un mensaje de error utilizando `perror`. Si `tcsetattr` se ejecuta correctamente, se muestra un mensaje indicando que la configuración del terminal se estableció correctamente.

**Ejemplo 2: Restaurar la configuración original del terminal**

En este ejemplo, se utiliza `tcsetattr` para restaurar la configuración original del terminal después de aplicar una configuración modificada.

```c
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int main() {
    struct termios orig_attr;
    if (tcgetattr(STDIN_FILENO, &orig_attr) == -1) {
        perror("Error al obtener la configuración original del terminal");
        return 1;
    }

    // Aplicar una configuración modificada aquí...

    if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_attr) == -1) {
        perror("Error al restaurar la configuración original del terminal");
        return 1;
    }

    printf("Configuración original del terminal restaurada correctamente.\n");

    return 0;
}
```

En este ejemplo, se obtiene la configuración original del terminal utilizando `tcgetattr` y se almacena en la estructura `orig_attr`. Luego, se aplica cualquier configuración modificada en el bloque correspondiente. Finalmente
</details>

___

### [tcgetattr](../funciones/permitidas/tcgetattr.c)

<details>
  <summary>Descripción</summary>

La función `tcgetattr` en C se utiliza para obtener la configuración actual de un terminal asociado a un descriptor de archivo. Permite obtener los diferentes parámetros de configuración, como la velocidad de transmisión, los modos de línea, el control de flujo, entre otros.

**Ejemplo 1: Obtención de la configuración del terminal**

En este ejemplo, se utiliza `tcgetattr` para obtener la configuración actual del terminal y mostrar algunos de sus parámetros.

```c
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int main() {
    struct termios attr;
    if (tcgetattr(STDIN_FILENO, &attr) == -1) {
        perror("Error al obtener la configuración del terminal");
        return 1;
    }

    printf("Configuración del terminal:\n");
    printf("Velocidad de transmisión: %lu\n", cfgetospeed(&attr));
    printf("Modos de línea: %d\n", attr.c_lflag);
    // Otros parámetros de configuración...

    return 0;
}
```

En este ejemplo, se declara una estructura `termios` llamada `attr` para almacenar la configuración del terminal. Luego, se llama a `tcgetattr` para obtener la configuración actual del terminal asociado al descriptor de archivo de entrada estándar (`STDIN_FILENO`). Si `tcgetattr` devuelve -1, indica que ocurrió un error, por lo que se imprime un mensaje de error utilizando `perror`. Si `tcgetattr` se ejecuta correctamente, se muestra la configuración del terminal en la salida estándar, como la velocidad de transmisión y algunos modos de línea.

**Ejemplo 2: Verificación de parámetros de configuración**

En este ejemplo, se utiliza `tcgetattr` para obtener la configuración actual del terminal y verificar si ciertos parámetros de configuración están activados o desactivados.

```c
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int main() {
    struct termios attr;
    if (tcgetattr(STDIN_FILENO, &attr) == -1) {
        perror("Error al obtener la configuración del terminal");
        return 1;
    }

    if (attr.c_lflag & ECHO) {
        printf("El eco de caracteres está habilitado.\n");
    } else {
        printf("El eco de caracteres está deshabilitado.\n");
    }

    if (attr.c_iflag & IXON) {
        printf("El control de flujo de entrada XON/XOFF está habilitado.\n");
    } else {
        printf("El control de flujo de entrada XON/XOFF está deshabilitado.\n");
    }

    // Otros parámetros de configuración...

    return 0;
}
```

En este ejemplo, se obtiene la configuración actual del terminal utilizando `tcgetattr` y se almacena en la estructura `attr`. Luego, se utilizan operaciones de bits para verificar si ciertos parámetros de configuración están activados o desactivados. En este caso, se verifica si el eco de caracteres (`ECHO`) y el control de flujo de entrada XON/XOFF (`IXON`) están habilitados. Se muestra un mensaje correspondiente en función del resultado de cada verificación.

</details>

___

### [tgetent](../funciones/permitidas/tgetent.c)

<details>
  <summary>Descripción</summary>

La función `tgetent` en C se utiliza para cargar una entrada de la base de datos terminfo que corresponde al nombre del terminal especificado. Proporciona acceso a la información de configuración específica del terminal, como capacidades y atributos.

**Ejemplo 1: Obtención de la entrada terminfo para el terminal actual**

En este ejemplo, se utiliza `tgetent` para cargar la entrada terminfo correspondiente al terminal actual y mostrar algunas de las capacidades disponibles.

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main()
{
	char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

	// Cargar la entrada terminfo para el terminal actual
	if (tgetent(term_buffer, getenv("TERM")) == -1)
	{
		perror("Error al cargar la entrada terminfo");
		return 1;
	}

	// Obtener y mostrar la capacidad de color del terminal
	if (tigetflag("colors") != -1)
	{
		int num_colors = tigetnum("colors");
		printf("El terminal admite %d colores.\n", num_colors);
	}
	else
	{
		printf("El terminal no admite colores.\n");
	}

	return 0;
}
```

En este ejemplo, se utiliza `tgetent` para cargar la entrada terminfo para el terminal actual utilizando el valor de la variable de entorno `TERM`. Si `tgetent` devuelve -1, se imprime un mensaje de error utilizando `perror`.

Luego, se utiliza `tigetflag` para verificar si el terminal admite colores (`colors`). Si la capacidad está disponible, se utiliza `tigetnum` para obtener el número de colores admitidos por el terminal y se muestra en la salida.

Compilar este código en macOS, debes enlazarlo con la biblioteca `curses`. Puedes hacerlo usando la opción `-lcurses` al compilar:

</details>

___

### [tgetflag](../funciones/permitidas/tgetflag.c)

<details>
  <summary>Descripción</summary>

La función `tgetflag` en C se utiliza para obtener el valor de una capacidad de tipo bandera (flag) del terminal desde la base de datos terminfo. Esta función devuelve -1 si la capacidad no está definida para el terminal actual, y 0 o 1 dependiendo del valor de la capacidad.


**Ejemplo 1: Verificar si el terminal admite el cursor parpadeante**

En este ejemplo, utilizaremos `tgetflag` para verificar si el terminal actual admite el cursor parpadeante.

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main() {
    char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

    // Cargar la entrada terminfo para el terminal actual
    if (tgetent(term_buffer, getenv("TERM")) == -1) {
        perror("Error al cargar la entrada terminfo");
        return 1;
    }

    // Verificar si el terminal admite el cursor parpadeante
    if (tgetflag("blink") != -1) {
        printf("El terminal admite el cursor parpadeante.\n");
    } else {
        printf("El terminal no admite el cursor parpadeante.\n");
    }
     if (tgetflag("rev") != -1) {
        printf("El terminal admite el resaltado de texto.\n");
    } else {
        printf("El terminal no admite el resaltado de texto.\n");
    }

    return 0;
}
```

En este ejemplo, después de cargar la entrada terminfo para el terminal actual utilizando `tgetent`, utilizamos `tgetflag` para obtener el valor de la capacidad "blink" (parpadeo). Si `tgetflag` devuelve un valor distinto de -1, significa que la capacidad está definida para el terminal actual. En este caso, imprimimos un mensaje indicando que el terminal admite el cursor parpadeante. De lo contrario, imprimimos un mensaje indicando que no lo admite.

</details>

___

### [tgetnum](../funciones/permitidas/tgetnum.c)

<details>
  <summary>Descripción</summary>

La función `tgetnum` en C se utiliza para obtener el valor de una capacidad de tipo numérica del terminal desde la base de datos terminfo. Esta función devuelve -1 si la capacidad no está definida para el terminal actual, y un valor numérico mayor o igual a cero si está definida.


**Ejemplo 1: Obtener el ancho de la ventana del terminal**

En este ejemplo, utilizaremos `tgetnum` para obtener el ancho de la ventana del terminal actual.

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main() {
    char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

    // Cargar la entrada terminfo para el terminal actual
    if (tgetent(term_buffer, getenv("TERM")) == -1) {
        perror("Error al cargar la entrada terminfo");
        return 1;
    }

    // Obtener el ancho de la ventana del terminal
    int width = tgetnum("cols");
    if (width != -1) {
        printf("Ancho de la ventana del terminal: %d\n", width);
    } else {
        printf("No se pudo obtener el ancho de la ventana del terminal.\n");
    }

    return 0;
}
```

En este ejemplo, después de cargar la entrada terminfo para el terminal actual utilizando `tgetent`, utilizamos `tgetnum` para obtener el valor de la capacidad "cols" (columnas), que representa el ancho de la ventana del terminal en caracteres. Si `tgetnum` devuelve un valor distinto de -1, lo mostramos en la salida. De lo contrario, imprimimos un mensaje indicando que no se pudo obtener el ancho de la ventana del terminal.

</details>

___

### [tgetstr](../funciones/permitidas/tgetstr.c)

<details>
  <summary>Descripción</summary>

La función `tgetstr` en C se utiliza para obtener una secuencia de escape o cadena de caracteres asociada a una capacidad de tipo cadena del terminal desde la base de datos terminfo. Esta función devuelve un puntero a la secuencia de escape si la capacidad está definida para el terminal actual, y `NULL` si no está definida.


**Ejemplo 1: Obtener la secuencia de escape para mover el cursor hacia arriba**

En este ejemplo, utilizaremos `tgetstr` para obtener la secuencia de escape necesaria para mover el cursor hacia arriba en el terminal.

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main() {
    char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

    // Cargar la entrada terminfo para el terminal actual
    if (tgetent(term_buffer, getenv("TERM")) == -1) {
        perror("Error al cargar la entrada terminfo");
        return 1;
    }

    // Obtener la secuencia de escape para mover el cursor hacia arriba
    char *cursor_up = tgetstr("up", NULL);
    if (cursor_up != NULL) {
        printf("Secuencia de escape para mover el cursor hacia arriba: %s\n", cursor_up);
    } else {
        printf("No se pudo obtener la secuencia de escape para mover el cursor hacia arriba.\n");
    }

    return 0;
}
```

En este ejemplo, después de cargar la entrada terminfo para el terminal actual utilizando `tgetent`, utilizamos `tgetstr` para obtener la secuencia de escape asociada a la capacidad "up" (mover el cursor hacia arriba). Si `tgetstr` devuelve un puntero distinto de `NULL`, mostramos la secuencia de escape en la salida. De lo contrario, imprimimos un mensaje indicando que no se pudo obtener la secuencia de escape.

</details>

___

### [tgoto](../funciones/permitidas/tgoto.c)


```c
char *tgoto(const char *cap, int col, int row);
```

<details> 
  <summary>Descripción</summary>

La función `tgoto` se utiliza para construir secuencias de escape que mueven el cursor a una posición específica en el terminal, basándose en la capacidad de posicionamiento del cursor del terminal.

- `cap`: La capacidad de posicionamiento del cursor del terminal.
- `col`: La columna a la que se desea mover el cursor.
- `row`: La fila a la que se desea mover el cursor.

La función `tgoto` toma como entrada una capacidad de posicionamiento del cursor del terminal (`cap`) y las coordenadas (`col` y `row`) a las que se desea mover el cursor. Devuelve una secuencia de escape que realiza el movimiento necesario para llegar a la posición especificada.

**Ejemplo 1: Mover el cursor a una posición específica**

En este ejemplo, utilizaremos la función `tgoto` para generar una secuencia de escape que mueva el cursor a una posición específica en el terminal.

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>

int main() {
    char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

    // Cargar la entrada terminfo para el terminal actual
    if (tgetent(term_buffer, getenv("TERM")) == -1) {
        perror("Error al cargar la entrada terminfo");
        return 1;
    }

    // Obtener la secuencia de escape para mover el cursor a la posición (5, 10)
    char *cursor_pos = tgoto(tgetstr("cm", NULL), 5, 10);
    if (cursor_pos != NULL) {
        printf("Secuencia de escape para mover el cursor a la posición (5, 10): %s\n", cursor_pos);
    } else {
        printf("No se pudo obtener la secuencia de escape para mover el cursor.\n");
    }

    return 0;
}
```

En este ejemplo, después de cargar la entrada terminfo para el terminal actual utilizando `tgetent`, utilizamos `tgetstr` para obtener la capacidad de posicionamiento del cursor `"cm"`. Luego, utilizamos `tgoto` para generar la secuencia de escape que mueve el cursor a la posición (5, 10). Si la secuencia de escape se genera correctamente, la mostramos en la salida. De lo contrario, imprimimos un mensaje indicando que no se pudo obtener la secuencia de escape.

</details> 

___

### [tputs](../funciones/permitidas/tputs.c)

```c
int tputs(const char *str, int affcnt, int (*putc)(int));
```

<details> 
  <summary>Descripción</summary>

La función `tputs` en C se utiliza para enviar secuencias de escape al terminal. Permite enviar una cadena de control al terminal para realizar operaciones como mover el cursor, cambiar los colores, borrar la pantalla, etc.

- `str`: La cadena de control que se enviará al terminal.
- `affcnt`: El número de líneas afectadas por la operación (opcional, se puede pasar 0).
- `putc`: Puntero a una función que envía caracteres al terminal (opcional, se puede pasar NULL).

La función `tputs` toma como entrada una cadena de control `str` y la envía al terminal. Esta cadena de control contiene secuencias de escape que representan operaciones específicas. El parámetro `affcnt` se utiliza para indicar cuántas líneas se verán afectadas por la operación (puede ser 0 si no es relevante). El parámetro `putc` se utiliza para especificar una función que envía caracteres al terminal (puede ser NULL para usar `putchar` por defecto).

La función `tputs` devuelve un valor distinto de 0 si se produjo un error, de lo contrario, devuelve 0.

**Ejemplo 1: Imprimir texto en negrita**

En este ejemplo, utilizaremos la función `tputs` para enviar una secuencia de escape al terminal y hacer que el texto se imprima en negrita.

```c
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>

int main() {
    char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

    // Cargar la entrada terminfo para el terminal actual
    if (tgetent(term_buffer, getenv("TERM")) == -1) {
        perror("Error al cargar la entrada terminfo");
        return 1;
    }

    // Obtener la secuencia de escape para imprimir en negrita
    char *bold_seq = tgetstr("bold", NULL);
    if (bold_seq != NULL) {
        // Enviar la secuencia de escape al terminal utilizando tputs
        if (tputs(bold_seq, 1, putchar) == ERR) {
            perror("Error al enviar la secuencia de escape");
            return 1;
        }

        // Imprimir texto en negrita
        printf("Texto en negrita\n");

        // Restaurar el formato normal
        char *reset_seq = tgetstr("sgr0", NULL);
        if (reset_seq != NULL) {
            tputs(reset_seq, 1, putchar);
        }
    } else {
        printf("No se pudo obtener la secuencia de escape para imprimir en negrita.\n");
    }

    return 0;
}
```

En este ejemplo, después de cargar la entrada terminfo para el terminal actual utilizando `tgetent`, utilizamos `tgetstr` para obtener la capacidad de impresión en negrita `"bold"`. Luego, utilizamos `tputs` para enviar la secuencia de escape al terminal y hacer que el texto se imprima en negrita. Después de imprimir el texto en negrita, utilizamos otra secuencia de escape `"sgr0"` para restablecer el formato al valor normal.

</details> 