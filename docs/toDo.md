## cositas a hacer....!!!

- getenv usar para asignar el valor de  home a "~"

https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/

- controlar el crtl+c, ctrl=v
- controlar $

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