
1. Uso de comillas dobles para delimitar una cadena:
   ```
   echo "Hola, mundo"
   ```
   Salida: `Hola, mundo`
   
   En este caso, las comillas dobles se utilizan para delimitar una cadena de texto. Bash interpreta el contenido dentro de las comillas como una sola cadena y no realiza ninguna expansión de variables o caracteres especiales dentro de ella. La cadena se muestra tal cual.

2. Uso de comillas dobles para expansión de variables:
   ```
   nombre="Juan"
   echo "Hola, $nombre"
   ```
   Salida: `Hola, Juan`
   
   Aquí, las comillas dobles permiten la expansión de variables. La variable `$nombre` se expande dentro de las comillas y su valor se concatena con el resto de la cadena. Como resultado, se muestra "Hola, Juan" en la salida.

3. Uso de comillas dobles para escapar caracteres especiales:
   ```
   echo "Las comillas \"dobles\" son útiles"
   ```
   Salida: `Las comillas "dobles" son útiles`
   
   En este caso, las comillas dobles se utilizan para escapar las comillas dobles dentro de la cadena. Al colocar una barra invertida `\` antes de las comillas dobles, Bash trata las comillas como caracteres literales en lugar de delimitadores de cadena. Como resultado, se muestra la frase completa con las comillas dobles correctamente escapadas.

	 ==

4. Expansión de comandos dentro de comillas dobles:
   ```
   echo "La fecha actual es: $(date)"
   ```
   Salida: `La fecha actual es: <fecha y hora actual>`
   
   En este caso, las comillas dobles permiten la expansión de comandos utilizando el formato `$(comando)`. El comando `date` se ejecuta y su salida se inserta en el lugar correspondiente dentro de la cadena. Al ejecutar el comando, se mostrará la fecha y hora actual en la salida.

5. Uso de comillas dobles para expansión aritmética:
   ```
   num1=5
   num2=3
   resultado=$((num1 + num2))
   echo "El resultado de la suma es: $resultado"
   ```
   Salida: `El resultado de la suma es: 8`
   
   Aquí, las comillas dobles permiten la expansión aritmética utilizando la sintaxis `$((expresión))`. La expresión `num1 + num2` se evalúa y el resultado se asigna a la variable `resultado`. Luego, esa variable se expande dentro de las comillas y se muestra el resultado de la suma en la salida.

6. Uso de comillas dobles con caracteres especiales:
   ```
   mensaje="Hola, \"amigo\"!"
   echo "$mensaje"
   ```
   Salida: `Hola, "amigo"!`
   
   En este ejemplo, las comillas dobles se utilizan para incluir caracteres especiales, como las comillas dobles, dentro de una cadena. La barra invertida (`\`) se utiliza como carácter de escape para indicar que las comillas dobles son parte de la cadena y no deben interpretarse como delimitadores. Como resultado, se muestra la cadena completa con las comillas dobles correctamente escapadas.

Listar las variables num1 y num2 utilizando el comando declare o echo. Aquí tienes ejemplos de cómo puedes hacerlo:

```
declare -p num1 num2
```