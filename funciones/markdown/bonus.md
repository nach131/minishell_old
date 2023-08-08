
### Operador &&

En Bash, el operador `&&` se utiliza para ejecutar comandos en secuencia, donde el segundo comando se ejecuta solo si el primer comando tiene éxito (es decir, devuelve un código de salida igual a 0).

1. Ejemplo simple 1:
   ```bash
   rm salida.txt && echo "se Borro el fichero salida.txt"
   ```
   En este ejemplo, se ejecuta `comando1` y si su código de salida es 0, se ejecuta `comando2`.

2. Ejemplo simple 2:
   ```bash
   make && ./mi_programa
   ```
   Aquí, se compila un programa utilizando el comando `make` y si tiene éxito, se ejecuta el programa `mi_programa`.

3. Ejemplo simple 3:
   ```bash
   grep "texto" archivo.txt && echo "Se encontró el texto"
   ```
   En este caso, se busca el texto "texto" en el archivo.txt utilizando el comando `grep`, y si se encuentra, se imprime "Se encontró el texto" en la salida estándar.

4. Ejemplo:
   ```bash
   comando1 && (comando2a && comando2b) && comando3
   ```
   Aquí, se ejecutan los comandos de forma más compleja. El comando2a y el comando2b se ejecutan en paralelo, y ambos deben tener éxito para que el comando3 se ejecute. Además, el comando1 debe tener éxito para que se inicie la secuencia.

### Operador ||

En Bash, el operador `||` se utiliza para ejecutar comandos en secuencia, donde el segundo comando se ejecuta solo si el primer comando falla (es decir, devuelve un código de salida distinto de 0). 

1. Ejemplo simple 2:
   ```bash
   rm archivo.txt || echo "No se pudo eliminar el archivo"
   ```
   Aquí, se intenta eliminar el archivo.txt utilizando el comando `rm`, y si no se puede eliminar (porque no existe, por ejemplo), se imprime "No se pudo eliminar el archivo" en la salida estándar.

2. Ejemplo simple 3:
   ```bash
   make || echo "La compilación falló"
   ```
   En este caso, se intenta compilar un programa utilizando el comando `make`, y si la compilación falla, se imprime "La compilación falló" en la salida estándar.

3. Ejemplo compuesto 2:
   ```bash
   grep "texto" archivo.txt || echo "No se encontró el texto"
   ```
   En este ejemplo, se busca el texto "texto" en el archivo.txt utilizando el comando `grep`, y si no se encuentra, se imprime "No se encontró el texto" en la salida estándar.
