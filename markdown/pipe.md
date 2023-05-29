El símbolo `|`, conocido como tubería o pipe en Bash, se utiliza para redirigir la salida de un comando hacia la entrada de otro. Aquí tienes tres ejemplos simples y tres ejemplos compuestos del uso de `|` en Bash:

Ejemplos simples:

1. Uso de tubería para filtrar la salida de un comando:
   ```
   ls | grep ".txt"
   ```
   Este comando lista los archivos en el directorio actual y luego redirige la salida hacia el comando `grep`. `grep` filtra la salida y muestra solo las líneas que contienen la extensión ".txt". De esta manera, se obtiene una lista de archivos que terminan en ".txt".

2. Uso de tubería para contar líneas de un archivo:
   ```
   cat archivo.txt | wc -l
   ```
   Este comando muestra el contenido del archivo "archivo.txt" y luego redirige la salida hacia el comando `wc -l`, que cuenta el número de líneas. Como resultado, se obtiene el recuento de líneas del archivo.

3. Uso de tubería para ordenar y mostrar los resultados:
   ```
   sort lista.txt | uniq
   ```
   Este comando ordena los elementos en el archivo "lista.txt" y luego redirige la salida hacia el comando `uniq`, que muestra solo las líneas únicas en la lista ordenada. De esta manera, se obtiene una lista ordenada y sin duplicados.

Ejemplos compuestos:

4. Uso de múltiples tuberías para realizar un procesamiento complejo:
   ```
   cat archivo.txt | grep "patrón" | sed "s/buscar/reemplazar/g" | sort > salida.txt
   ```
   En este ejemplo, la salida del comando `cat` se redirige hacia `grep`, que filtra las líneas que contienen el patrón especificado. Luego, se redirige la salida de `grep` hacia el comando `sed`, que realiza una sustitución de texto en cada línea. Finalmente, se ordena la salida y se redirige hacia el archivo "salida.txt" utilizando el operador `>`. Este es un ejemplo más complejo de cómo se pueden combinar múltiples tuberías para realizar un procesamiento más elaborado.

5. Uso de tubería con comandos de búsqueda y filtrado:
   ```
   find directorio -name "*.txt" | xargs grep "patrón"
   ```
   En este ejemplo, el comando `find` busca todos los archivos con la extensión ".txt" dentro del directorio especificado. Luego, la lista de archivos encontrados se redirige hacia el comando `xargs`, que toma la lista como entrada y ejecuta el comando `grep` para buscar el patrón especificado en cada archivo. Este ejemplo muestra cómo se pueden combinar múltiples comandos con tuberías para realizar búsquedas y filtrados más complejos.

6. Uso de tubería para calcular estadísticas de archivos:
   ```
   du -h | sort -rh | head -n 5
   ```
   Aquí, el comando `du -h` se utiliza para calcular el tamaño de todos los archivos y directorios en el directorio actual, y la opción `-h` muestra los resultados en un formato legible para humanos. Luego, se redirige la salida hacia el comando `sort -rh`, que ordena los resultados en orden inverso de tamaño. Por último, se utiliza