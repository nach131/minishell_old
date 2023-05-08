
## instalción

La biblioteca `libreadline` se utiliza comúnmente en sistemas operativos basados en Unix, como Linux y macOS, y generalmente se incluye en la mayoría de las distribuciones de estas plataformas. Sin embargo, si necesita descargar y compilar la biblioteca manualmente, puede seguir estos pasos:

1. Abra la terminal en su sistema operativo y asegúrese de que el sistema tenga instalado el compilador de C y el administrador de paquetes. En una distribución de Linux basada en Debian, puede usar el siguiente comando:

```
sudo apt-get update
sudo apt-get install build-essential
```

2. Descargue la última versión de `libreadline` desde el sitio web oficial de GNU Readline en https://ftp.gnu.org/gnu/readline/. Seleccione la versión más reciente y descargue el archivo `tar.gz`.

3. Extraiga el archivo descargado en un directorio temporal utilizando el siguiente comando:

```
tar xvf readline-X.Y.tar.gz
```

Reemplace `X.Y` con la versión que descargó.

4. Cambie al directorio donde se extrajo la biblioteca:

```
cd readline-X.Y
```

5. Configure y compile la biblioteca utilizando los siguientes comandos:

```
./configure
make
sudo make install
```

El comando `./configure` configura la biblioteca para su sistema, `make` compila la biblioteca y `sudo make install` instala la biblioteca en su sistema. Si todo sale bien, la biblioteca `libreadline` se instalará en el sistema y podrá utilizarla en su código fuente de C.

Tenga en cuenta que puede ser necesario instalar otras dependencias para compilar `libreadline` con éxito. En un sistema basado en Debian, puede instalar estas dependencias utilizando el comando `sudo apt-get build-dep readline`.

## instalado desde Brew

brew install readline

Después de la instalación, debes agregar la ruta de búsqueda de la biblioteca libreadline al archivo de configuración de la variable de entorno DYLD_LIBRARY_PATH. Puedes hacerlo agregando el siguiente comando a tu archivo .bashrc o .bash_profile en tu directorio de inicio:

    export DYLD_LIBRARY_PATH=/usr/local/opt/readline/lib:$DYLD_LIBRARY_PATH

Luego, abra una nueva ventana de terminal o ejecute el siguiente comando para actualizar la variable de entorno:

    source ~/.bashrc

En la compilación es necesario incluir el flag `-lreadline`

La opción -lreadline le indica al compilador que enlace con la biblioteca libreadline.


