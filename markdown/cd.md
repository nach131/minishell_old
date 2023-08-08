El comando "cd" en Bash se utiliza para cambiar el directorio actual. Existen dos formas de especificar la ubicación del directorio al que deseas cambiar: mediante rutas relativas y rutas absolutas.

- Ruta relativa: Una ruta relativa se especifica en relación con el directorio actual en el que te encuentras. No comienza con una barra `(/)` y puede usar referencias como ".." para indicar el directorio padre o `"."` para indicar el directorio actual.

Por ejemplo, si te encuentras en el directorio `"/home/usuario/"` y deseas cambiar al directorio "/home/usuario/documentos/", puedes utilizar una ruta relativa como esta:
```
cd documentos
```
Esto te llevará al directorio `"documentos"` en relación con tu directorio actual.

- Ruta absoluta: Una ruta absoluta se especifica desde la raíz del sistema de archivos y siempre comienza con una barra `(/)`. Indica la ruta completa hasta el directorio objetivo, independientemente del directorio actual en el que te encuentres.

Por ejemplo, si te encuentras en cualquier directorio y deseas ir directamente a `"/home/usuario/documentos/"`, puedes especificar la ruta absoluta de la siguiente manera:
```
cd /home/usuario/documentos
```
El comando `"cd"` cambiará directamente al directorio `"/home/usuario/documentos"` sin importar dónde te encuentres actualmente.

En resumen, la diferencia clave entre una ruta relativa y una ruta absoluta es que una ruta relativa se basa en el directorio actual, mientras que una ruta absoluta se especifica desde la raíz del sistema de archivos. Las rutas relativas son útiles cuando deseas navegar de forma relativa a tu ubicación actual, mientras que las rutas absolutas son útiles cuando deseas ir directamente a un directorio específico, sin importar dónde te encuentres actualmente.