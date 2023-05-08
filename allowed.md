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