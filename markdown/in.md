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

4. Copiar el contenido de un archivo a otro archivo:
```bash
cp < archivo_origen.txt archivo_destino.txt
```

5. Calcular la suma de valores numéricos en un archivo utilizando `awk`:
```bash
awk '{sum += $1} END {print sum}' < numeros.txt
```

**Ejemplos más complejos:**
1. Ejecutar un script de Python que toma la entrada desde un archivo y redirige la salida a otro archivo:
```bash
python script.py < entrada.txt > salida.txt
```

2. Utilizar la entrada redirigida para alimentar datos a un programa interactivo:
```bash
echo "datos" | programa_interactivo < datos_entrada.txt
```

3. Ordenar una lista de nombres en orden alfabético desde un archivo y guardar el resultado en otro archivo:
```bash
sort < nombres.txt > nombres_ordenados.txt
```

4. Realizar una comparación entre dos archivos utilizando el comando `diff`:
```bash
diff < archivo1.txt archivo2.txt
```

5. Ejecutar una secuencia de comandos de MySQL desde un archivo de comandos:
```bash
mysql -u usuario -p contraseña < script_mysql.sql
```

Estos ejemplos muestran cómo puedes utilizar el símbolo '<' para redirigir la entrada de comandos desde archivos en Bash. Ten en cuenta que la redirección de entrada es una poderosa funcionalidad que te permite automatizar tareas y procesar grandes cantidades de datos. Siempre asegúrate de tener los permisos adecuados y de que los archivos de entrada existan antes de realizar la redirección.