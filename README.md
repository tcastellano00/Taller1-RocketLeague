# Taller1-RocketLeagues
TP Final de la materia Taller de programación 1

![alt text](https://app.travis-ci.com/tcastellano00/Taller1-RocketLeague.svg?token=i5sYMvqAzCxYcsKUK5yF&branch=main)

| Integrantes    | Padron |
| -------------- | ------ |
| Couttulenc Marcos| 106381 |
| Martín Tomás   | 100835  |
| Bursztyn Fernando   | 100898  |


# Informes
[Documentación Técnica](https://docs.google.com/document/d/1GZ37hIVslaq5qQRa4rIikDMMmVd59vRMnn6P-WR4FyY/edit?usp=sharing)

[Manual de Proyecto](https://docs.google.com/document/d/1O9OWEeqHpET_tjnT7PkV4QW3vANfpnvZn209kwH9aao/edit?usp=sharing)


# Dependencias

```
cmake
build-essential
qt5-default
libsdl2-dev
libsdl2-image-dev
libsdl2-ttf-dev
libyaml-cpp-dev
libsdl2-mixer-dev
```
## Instalación de SDL
```
apt-get install libsdl2-dev
apt-get install libsdl2-image-dev
apt-get install SDL2_ttf-devel
apt-get install SDL2_mixer-devel
apt-get install libgtest-dev
```

## Instalación de CMake
```
sudo apt-get -y install cmake

```

## Instalación de QT
```
sudo apt-get install build-essential
sudo apt-get install qtcreator
sudo apt-get install qt5-default
```

## Instalación de GTest
```
sudo apt install libgtest-dev
```


# Instrucciones una vez instaladas las dependencias

## Descarga de la repo

Clonar localmente el repo del siguente link: https://github.com/tcastellano00/Taller1-RocketLeague.git


## Instalar aplicación
Para instalar la aplicacion, posicionese en la raiz del proyecto, abra una consola y ejecute el siguiente script para compilar el programa.
```
$ sh script.sh
```
Luego, si la ejecucion fue satisfactoria, ejecute el siguiente script.

```
$ sh installer.sh
```

Al finalizar la ejecucion, la aplicación se encontrara instalada en la carpeta /usr/local/bin, ingrese a esta carpeta.

## Correr Server
Una vez posicionado en la carpeta, abra una nueva consola y corra el siguiente comnado
```
./rocket_league-server <Puerto>
```

## Correr Cliente
Luego, en la misma carpeta, abra otra consola y corra el siguiente comando
```
./rocket_league <Servicio> <Puerto>
```
En caso de querer correrlo de manera local:
```
./rocket_league localhost <Puerto>
```

# In Game
## Lobby

Una vez los clientes se encuentren en el Lobby, deben ingresar su nombre para entrar a la pantalla principal del lobby, en donde pueden crear o unirse a una partida.

![](https://github.com/tcastellano00/Taller1-RocketLeague/blob/main/READMEMultimedia/lobby1.png)
![](https://github.com/tcastellano00/Taller1-RocketLeague/blob/main/READMEMultimedia/lobby2.png)
![](https://github.com/tcastellano00/Taller1-RocketLeague/blob/main/READMEMultimedia/lobby3.png)
![](https://github.com/tcastellano00/Taller1-RocketLeague/blob/main/READMEMultimedia/lobby4.png)
![](https://github.com/tcastellano00/Taller1-RocketLeague/blob/main/READMEMultimedia/lobby5.png)
![](https://github.com/tcastellano00/Taller1-RocketLeague/blob/main/READMEMultimedia/lobby6.png)
![](https://github.com/tcastellano00/Taller1-RocketLeague/blob/main/READMEMultimedia/lobby7.png)
![](https://github.com/tcastellano00/Taller1-RocketLeague/blob/main/READMEMultimedia/lobby8.png)



## Reglas de la partida
* La duracion de la partida es de 3 minutos (en el futuro, tiempo configurable).
* En caso de empatar, se otorgara una prorroga de 30 segundos. En caso de empatar de nuevo, se aplicara esta prorroga indefinidamente hasta que un equipo gane.
* El ganador es el equipo con mas goles anotados al momento de finalizar la partida.
* El gol es otorgado cuando la totalidad del esférico entra en el arco.

## Controles
| Tecla   | Accion |
| -------------- | ------ |
| t | turbo |
| space | salto / doble salto / flip  |
| → | avanzar a la derecha  |
| ←	 | avanzar a la izquierda  |
| ↑ | rotar antohorario |
| ↓ | rotar horario  |

## Acciones especiales

### Doble salto
Estando en el aire y sin estar presionando las teclas de avanzar para los costados, tocar space para realizar un segundo impulso hacia arriba.

### Flip
Estando en el aire y mientras se esta presionando una tecla de avanzar hacia algun costado, tocar space para realizar un flip hacia ese lado.

### Red Shot
Estando cerca de la pelota y de frente a ella, realizar un flip en la direccion de la pelota.

### Gold Shot
Estando cerca de la pelota pero mirando en direccion contraria a ella, realizar un flip en la direccion contraria a la pelota.

### Purple Shot
Estando cerca de la pelota, posicionar el auto de tal manera que las ruedas del mismo queden orientadas hacia la pelota. En esa posicion, tocar la tecla space.

