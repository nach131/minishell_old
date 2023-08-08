
1. Pipe (|): Permite redirigir la salida de un comando como entrada al siguiente comando.

```bash
ls -l | grep ".txt"
```

Este comando listaría el contenido del directorio actual con detalles (`ls -l`) y luego pasaría la salida a través del pipe (`|`) al comando `grep`, que buscaría líneas que contengan ".txt".

2. Redirección de salida (>): Permite redirigir la salida de un comando hacia un archivo en lugar de la salida estándar.

```bash
ls -l > archivo.txt
```

Este comando listaría el contenido del directorio actual con detalles (`ls -l`) y redirigiría la salida al archivo "archivo.txt".

3. Redirección de entrada (<): Permite tomar la entrada de un archivo en lugar de la entrada estándar para un comando.

```bash
sort < archivo.txt
```

Este comando tomaría el contenido del archivo "archivo.txt" y lo pasaría como entrada al comando `sort`, que ordenaría las líneas alfabéticamente.

4. Redirección de salida y anexar (>>): Permite redirigir la salida de un comando y anexarla a un archivo existente en lugar de sobrescribirlo.

```bash
echo "Nuevo contenido" >> archivo.txt
```

Este comando agregaría la cadena "Nuevo contenido" al final del archivo "archivo.txt" sin eliminar su contenido existente.

5. Comando en segundo plano (&): Permite ejecutar un comando en segundo plano, lo que significa que se ejecuta simultáneamente mientras el usuario puede continuar con otras tareas.

```bash
sleep 10 &
```

Este comando ejecutaría el comando `sleep 10` en segundo plano, lo que provocaría una pausa de 10 segundos sin bloquear la terminal, lo que permitiría al usuario seguir ingresando otros comandos.

Estos son solo ejemplos básicos de comandos combinados en Bash. Hay muchas otras combinaciones y técnicas avanzadas disponibles para realizar tareas más complejas en un script de Bash.

```bash
ls -lh > listado.txt
```

Crea el arachivo `listado.txt` con ls de la carpeta actual

```bash
sort -k 9 listado.txt | uniq
```
Ordenara el contenido de `listado.txt` segun los valores de la 9 columna y solo mostrara los resultados unicos.

### find

Busar todos los fichero que tiene 0 bytes los borra y si es ok realizar el archivo registro.txt

```bash
find /ruta/a/directorio -type f -size 0 -delete &> registro.txt
```

Busar todos los fichero que tiene 0 bytes los visualiza

```bash
find /ruta/a/directorio -type f -size 0 -print
```

Busar todos los fichero que tiene 0 bytes los borra

```bash
find /ruta/a/directorio -type f -size 0 -delete
```
Busar todos los diretorios vacios  y los visualiza

```bash
find /ruta/a/directorio -type d -empty
```

Buscar todos los directorios vacios y los borra
```bash
find /ruta/a/directorio -type d -empty -delete
```

