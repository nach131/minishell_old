## cositas a hacer....!!!

- getenv usar para asignar el valor de  home a "~"

~~- controlar el crtl+c, ctrl=v~~
- controlar $

~~`TAB` para listar los elementos de la carpeta actual~~

## EXPORT
Pasar todas las lista a **env y ordenar dentro todo los valores según ASCII

## Dobles comillas o simple
cuando se impar, abrir la consola para que el usuario intruduzca comandos
en el fd 0

```bash
cuando hacer | grep BUSCADO
```
devolver el nombre de BUSCADO en otro color

## env
crear una env nueva

env -i ./minishel

enviromen simples

hacer un read del file descriptor, y ponerlo en un array de lo que contenga el fichero

~~acabar quitar qoutes~~

lst_map
Para quitar o poner las comillas y devolve una nueva lista

## NO es necesario

(o cosas que no funcionan en otros proyectos)
```bash
nombre="Juan"
echo "Hola, $nombre"
```
```bash
env VAR1=valor1 VAR2=valor2 env

echo "La fecha actual es: $(date)"
```

## Flujo

	variables
		getenv-> recuepera el valor del nombre de la variable pasad
			Usar la funcion lst_value como get event.

~~leer todos los env, añadir los que se pasan desde la orden de comandos y pasarlos todos a **array,~~
~~ponerlos en t_cmd y liberar todo desde t_cmdfree~~

## HAY QUE REVISAR

### clear
~~cmd: /usr/bin/clear, filefd: 0-1~~
~~TERM environment variable not set.~~

### ejecucion ./***.sh
No puedo ejecuar ./archivo
mesnaje de error
-Minishell: ./minishell: command not found

```bash
man ls | vim -
```

```bash
ls -la | vim -
```


Contemplar
cat<toma.txt|grep a
(sin espacios entre las redirecciones o los pipes)