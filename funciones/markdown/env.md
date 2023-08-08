# ENV

## Ejemplos simples:

1. Mostrar todas las variables de entorno:
   ```
   env
   ```

2. Mostrar el valor de una variable de entorno específica (por ejemplo, PATH):
   ```
   env | grep PATH
   ```

3. Establecer una nueva variable de entorno en un solo comando:
   ```
   env MY_VAR="Hola mundo" bash
   ```

4. Ejecutar un comando con una variable de entorno específica:
   ```
   env VAR_NAME=valor comando
   ```

5. Ejecutar un script de Bash con una variable de entorno específica:
   ```
   env VAR_NAME=valor script.sh
   ```

## Ejemplos complejos:

6. Ejecutar un programa en un entorno virtual de Python:
   ```
   env/bin/python programa.py
   ```

7. Establecer múltiples variables de entorno en un solo comando:
   ```
   env VAR1=valor1 VAR2=valor2 env
   ```
este no lo hacen todos.

8. Cambiar el valor de una variable de entorno existente y ejecutar un script:
   ```
   env VAR_NAME=nuevo_valor script.sh
   ```

9. Leer variables de entorno desde un archivo y ejecutar un comando:
   ```
   env $(cat variables.txt) comando
   ```

10. Crear un archivo `.env` con variables de entorno y ejecutar un script utilizando esas variables:
    ```
    source .env && script.sh
    ```

Recuerda que `env` se utiliza para establecer variables de entorno temporales para un comando o script en particular.