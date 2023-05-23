
### Sintaxis de la consola

`#`

Si la entrada indica el comienzo de un comentario, el shell ignora el símbolo de comentario `#`, y el resto de esa línea.

Hay que separar en palabras y operadores. con las reglas de las comillas para seleccionar que asignar a la variable `word` y `caracter`

Luego, el shell analiza estos tokens en comandos y otras construcciones, elimina el significado especial de ciertas palabras o caracteres, expande otros, redirige la entrada y la salida según sea necesario, ejecuta el comando especificado, espera el estado de salida del comando y hace que ese estado de salida esté disponible. para su posterior inspección o procesamiento.

### Operaciones

- Leer la entrada
	- Desde un archivo.
	- Desde los argumentos.
	- Desde terminal (escrito por el usuario).
- Dividir la entra en `word` y `operadores`, según las reglas [Quoting](#Quoting) y las separación por [Tokens](#Tokens) `metacharacters`
- Analiza los token en comandos simples y compuestos.
- Realiza varias expansiones, dividiendo los token expandidos en listas de nombres de archivos, comandos y argumentos.
- Realiza las redirecciones necesarias, elimina los operadores de redirección y sus operadores de la lista de argumentos.
- Ejecuta el comando.
- Si es necesario, espera a que se complete el comando y recopila su estado de salida.

### Quoting