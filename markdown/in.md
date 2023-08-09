En Bash, el símbolo '<' se utiliza para redirigir la entrada de un comando desde un archivo en lugar de usar la entrada estándar. A continuación, te proporciono 5 ejemplos simples y 5 ejemplos más complejos de su utilización:

**Ejemplos simples:**
1. Leer contenido de un archivo y mostrarlo en la pantalla:
```bash
cat < archivo.txt
```

2. Contar el número de líneas en un archivo:
```bash
wc -l < archivo.txt
```

3. Filtrar el contenido de un archivo utilizando `grep`:
```bash
grep "palabra" < archivo.txt
```

~~5. Calcular la suma de valores numéricos en un archivo utilizando `awk`:~~
```bash
awk '{sum += $1} END {print sum}' < numeros.txt
```


4. Ordenar una lista de nombres en orden alfabético desde un archivo y guardar el resultado en otro archivo:
```bash
sort < nombres.txt > nombres_ordenados.txt
```

