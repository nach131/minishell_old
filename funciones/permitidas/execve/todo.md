
Mostrar los archivos modificados en las últimas 24 horas y guardar la lista en un archivo "archivos_modificados.txt".

```
find /ruta/directorio -type f -mtime 0 | sort > archivos_modificados.txt
```

con varibale de entorno

```
find $PWD -type f -mtime 0 | sort > archivos_modificados.txt
```

Mostrar los procesos en ejecución que contengan la palabra "firefox" y guardar la salida en un archivo "procesos_firefox.txt" (agregando al final del archivo si ya existe).

```
ps aux | grep a.out >> procesos_a_out.txt
```