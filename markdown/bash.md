
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


## >>

Este operador se utiliza para redireccionar la salida de un comando y agregarla al final de un archivo existente o crear un nuevo archivo si no existe. Si el archivo ya contiene contenido, la salida se añade al final sin sobrescribirlo.

Ejemplos simples:

1. Redireccionar la salida de un comando a un archivo y agregar el resultado al final:
```
ls -l >> archivo.txt
```
Este comando lista los archivos y directorios en el directorio actual y agrega la salida al final del archivo "archivo.txt".

2. Redireccionar el resultado de un comando a un archivo nuevo, sobrescribiendo el contenido existente:
```
date > fecha.txt
```
Este comando guarda la fecha y hora actual en el archivo "fecha.txt", sobrescribiendo cualquier contenido anterior en el archivo.

3. Redireccionar la salida de un comando de error estándar a un archivo:
```
comando_inexistente 2>> errores.txt
```
Este comando intenta ejecutar un comando inexistente y redirecciona cualquier mensaje de error al archivo "errores.txt". El número "2" representa el descriptor de archivo para la salida de error estándar.

Ejemplos más complejos:

4. Redireccionar tanto la salida estándar como la salida de error de un comando a un archivo:
```
comando 1>> salida.txt 2>> errores.txt
```
Este comando ejecuta un comando y redirecciona la salida estándar al archivo "salida.txt" y la salida de error al archivo "errores.txt". El número "1" representa el descriptor de archivo para la salida estándar.

5. Redireccionar la salida de un comando y la entrada de otro mediante el uso de tuberías y redirecciones:
```
cat archivo.txt | grep "palabra" >> resultados.txt
```
Este comando lee el contenido del archivo "archivo.txt", pasa la salida a través de un filtro "grep" que busca la palabra "palabra" y redirige los resultados al archivo "resultados.txt".

6. Concatenar múltiples archivos y redireccionar el resultado a otro archivo:
```
cat archivo1.txt archivo2.txt archivo3.txt >> archivos_concatenados.txt
```
Este comando concatena los contenidos de los archivos "archivo1.txt", "archivo2.txt" y "archivo3.txt" y redirecciona el resultado al archivo "archivos_concatenados.txt" usando el token ">>".

## >

Este operador también se utiliza para redireccionar la salida de un comando hacia un archivo, pero a diferencia de ">>", sobrescribe el contenido existente del archivo si este ya existe. Si el archivo no existe, se crea uno nuevo.

## <<

```
cat > config.txt << FIN
# Archivo de configuración

Nombre de usuario: [Ingrese su nombre]
Contraseña: [Ingrese su contraseña]
FIN
```

Este comando permite al usuario ingresar valores para un archivo de configuración interactivo y los guarda en el archivo "config.txt".