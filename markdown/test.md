# Test hacer en minishell

```bash
export uno dos='dos' tres="tres"
```


## IN '<'

```bash
cat < archivo.txt
```

```bash
wc -l < archivo.txt
```

```bash
grep "palabra" < archivo.txt
```

```bash
awk '{sum += $1} END {print sum}' < numeros.txt
```

## OUT '>'

```bash
date > fecha.txt
```

Redireccionar la salida de un comando de error estándar a un archivo:

```bash
comando 1>> salida.txt 2>> errores.txt
```

```bash
find /ruta/a/directorio -type f -size 0 -print
```

## ECHO

```bash
echo "Suma de los números:"
echo "1 2 3 4 5" | tr " " "+" | bc
15
```

```bash
echo "Cuenta las lineas del fichero:"
cat archivo.txt | echo $(wc -l)
```

```bash
echo "Lista ordenada de nombres:"
echo "Julia John Ana Michael" | tr ' ' '\n' | sort
```

```bash
echo "Archivos más grandes:"
find . -type f -exec du -h {} + | sort -rh | head -5 | tee archivos_mas_grandes.txt
```

```bash
echo "Direcciones IP únicas del archivo de registro:"
cat archivo.log | grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b" | sort | uniq
```

```bash
echo "Cantidad de archivos y directorios en el directorio actual:"
ls -l | grep -v "^d" | wc -l
echo "Cantidad de directorios en el directorio actual:"
ls -l | grep "^d" | wc -l
```

```bash
echo "Archivos y tamaños ordenados por tamaño:"
ls -lh | awk '{print $5, $9}' | sort -hr
```

```bash
echo "Convirtiendo CSV a tabla HTML:"
cat datos.csv | awk 'BEGIN{print "<table>"} {print "<tr>"; for(i=1;i<=NF;i++)print "<td>" $i"</td>"; print "</tr>"} END{print "</table>"}' > tabla.html
```

comando_inexistente 2>> errores.txt