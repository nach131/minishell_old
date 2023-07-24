## cositas a hacer....!!!

- getenv usar para asignar el valor de  home a "~"

- getcwd para conseguir la ruta donde estas

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

~~hacer un read del file descriptor, y ponerlo en un array de lo que contenga el fichero~~

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

### ~~clear~~
~~cmd: /usr/bin/clear, filefd: 0-1~~
~~TERM environment variable not set.~~

### ejecucion ./***.sh
No puedo ejecuar ./archivo
mensaje de error
-Minishell: ./minishell: command not found

```bash
man ls | vim -
```

```bash
ls -la | vim -
```

## Contemplar

~~cat<toma.txt|grep a~~

~~sin espacios entre las redirecciones o los pipes~~

~~cat Makefile|grep "make"~~

./push_swap 42 84 2> error.txt

sort < archivo.txt

## ctrl + z
man ls
para salir hay que pulsar ctrl+Z, a mi me sale del minishell

## Alba

cat | ls

Despues del Enter tiene que cerra el pipe

export A='foo   ' B='bar   ' C='baz    '

```bash
BASH-3.2$ echo $A"$B"$C
foo bar   baz
BASH-3.2$ echo $A$B$C
foo bar baz
BASH-3.2$
```

hay que controlar SHLVL=1 cada vez que se inicie un nuevo minishell

cuando se pase de SHLVL=10000

dar mesaje de error

bash: warning: shell level (10001) too high, resetting to 1

Y reiniciar el SHLVL a 1


