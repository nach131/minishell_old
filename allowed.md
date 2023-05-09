# Funciones permitidas

### [readline](funciones/permitidas/readline.c)

```c
char *readline(const char *prompt);
```

<details>
  <summary>Descripción</summary>

### [Instalar readline](./funciones/permitidas/readline.md)

`readline()` esta incluida en la biblioteca `libreadline`, que proporcionan una funcionalidad avanzada para la lectura de líneas de entrada desde el usuario en la línea de comandos.


La función `readline()` lee una línea de entrada desde el usuario y la devuelve como un puntero a una cadena de caracteres dinámicamente asignada en memoria. La sintaxis de la función `readline()` es la siguiente:

- `prompt` es una cadena de caracteres que se muestra en la línea de comandos para indicar que se está esperando la entrada del usuario.

La función `readline()` devuelve un puntero a una cadena de caracteres que contiene la línea de entrada leída. El usuario debe liberar la memoria asignada a esta cadena utilizando la función `free()` cuando ya no se necesite.

</details>

### [rl_clear_history](funciones/permitidas/rl_clear_history.c)

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

### [rl_on_new_line](funciones/permitidas/rl_on_new_line.c)

```c
void rl_on_new_line(void);
```

<details>
  <summary>Descripción</summary>

La función `rl_on_new_line` es una función de la biblioteca `readline` en C, que se utiliza para notificar a la biblioteca que se ha llegado a una nueva línea en la entrada. La función se define en el archivo de encabezado `readline/readline.h`.

La función no toma argumentos y no devuelve ningún valor.

Cuando se llama a la función `rl_on_new_line`, la biblioteca `readline` procesa la línea actual de entrada y la agrega al historial. También restablece el estado de la línea de entrada a la configuración inicial para la siguiente entrada. Esta función debe llamarse siempre que se completa una línea de entrada y antes de leer una nueva línea de entrada.

</details>

### [rl_replace_line](funciones/permitidas/rl_replace_line.c)

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

## [rl_redisplay](funciones/permitidas/rl_redisplay.c)


<details>
  <summary>Descripción</summary>

  La función `rl_redisplay()` es parte de la biblioteca `readline` en C y se utiliza para redibujar la línea de entrada actual en la consola. Esto puede ser útil si necesitas actualizar la línea de entrada para que refleje un cambio en el estado del programa, por ejemplo, para mostrar un mensaje de error o para actualizar el prompt.

  Muy util 

</details>
