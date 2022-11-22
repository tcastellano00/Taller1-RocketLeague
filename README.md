# Taller1-RocketLeagues
TP Final de la materia Taller de programación 1

| Integrantes    | Padron |
| -------------- | ------ |
| Couttulenc Marcos| 106381 |
| Castellanos Tomas   |   |
| Bursztyn Fernando   | 100898  |


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
apt-get install SDL2_mixer-devel.
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


# Instrucciones una vez instaladas las dependencias

## Descarga de la repo

Clonar localmente el repo del siguente link: https://github.com/tcastellano00/Taller1-RocketLeague.git


## Compilar aplicación
Para compilar la aplicacion, en una consola ejecutar el script ya hecho en el proyecto.

```
$ sh script.sh
```
El cual ya realiza los siguientes comandos.

```
$ sudo rm -rf build
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Correr Server
```
./build/rocket_league-server <Puerto>
```

## Correr Cliente
```
./build/rocket_league <Servicio> <Puerto>
```
En caso de querer correrlo de manera local:
```
./build/rocket_league localhost <Puerto>
```

# In Game
## Lobby
Una vez los clientes se encuentren en el Lobby, pueden crear o unirse a una partida mediante los siguientes comandos:
```
CREAR <CantidadMaximaDeJugadores> <NombreDePartida>
UNIR <NombreDePartida>
```
#NOTA: el lobby se implementará de manera gráfica en QT, por ahora es en consola.
Cuando la partida se llene, El jugador saldra del lobby y entrara en la partida.

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




Diagramas:

![](http://www.plantuml.com/plantuml/png/bL7BQiCm4BplL-XKN4pw0JcKG0wba5wQzWDaQN54PQb8gpum_VVQicWsaI_rmR0pevbXTnT91ag31MLbZ69l3JeQeSruSmi_K9YZLsz8uzzyy5ttlIPya0CUILAAJzuPyc64I7gx7HBXbyX_Q3llhUWdvMFSMnzHJmvjbaKAnlKpLrncviCRBM8UNz-r96ourk7dBCNL4YFaB9LJW3-JYfAqYweqCgNDVp9vxQBdwtWv1PJw89DJ9mpd_JsZqnWcf2I5F3VLzcv4Vmrbz_bRhYKsc_lb71oeZ3XvMOepfHR7okaXHuYxCt3fmfag_AeIb9ZbKQLUSwv5kyaZ3VON)

![](http://www.plantuml.com/plantuml/png/TP71JiCm44Jl_WeVYwhq0oeKLUJ0XKf0-G5Zhve8EnjvRII4-7SMqwZPkZr5anc_YISxIYQc7BootX3fjpw2SKycZxQ7-AtMnL_TgH-brAC9S4WcPThZE2ICkcbQVNwh1AGBxfKVaY8Yx5iOFaLYdITd4foXzQa3Z8NwZkZrvCtNC1wlL3n7J6ZH5xZRRYb53khutxa78dE4lqPYtYmNINPAmq2THmAtP3zuj1-SUScGuRx34CpeMcwQClMhazOsE8RCQiBfjACIAvSLBpUx7U7Rt_3bfafAtMnQNVr0jMGMoBnQTRpoHBbSv0AxgMrnsJfH0-fFtx6PW_y5)


Links la edicion de los diagramas de clases(en PlantUML):
http://www.plantuml.com/plantuml/uml/bL7BJiCm4BplL_Y4WgBo0JsWIZqWf7AXy05El4ej71lPQnwA-7UITQ1EdKjpYBGpuvdHxYwGz1Hx0z0Q6OBO6usM1gYPg6xXvuyvklODQVYV3wvfljU43xB78qcAuSbPJSuF44Xjjtqa_1ByXxfnpeXkL3w6lN41rUXGiooGrxPZBhbCp8VJIWGUNz-L9AnohSNFIOgh9GRWh9PJ87ycMuhI9DNSICzjhiXSraxwV1ql9uzI7MIqxGdzUN_FQ1Nw4PcJFCzLiRqRqLr2apj_wLfYixbFvyY1mYWdbwLo9jLQOkdqm17YxWmiNNAc2B-e17DCUbIervnB4UpGgjYRNm00
http://www.plantuml.com/plantuml/uml/TP71JiCm44Jl_WeVYwhq0oeKLUJ0XKf0-G5Zhve8EnjvRII4-7SMqwZPkZr5anc_YISxIYQc7BootX3fjpw2SKycZxQ7-AtMnL_TgH-brAC9S4WcPThZE2ICkcbQVNwh1AGBxfKVaY8Yx5iOFaLYdITd4foXzQa3Z8NwZkZrvCtNC1wlL3n7J6ZH5xZRRYb53khutxa78dE4lqPYtYmNINPAmq2THmAtP3zuj1-SUScGuRx34CpeMcwQClMhazOsE8RCQiBfjACIAvSLBpUx7U7Rt_3bfafAtMnQNVr0jMGMoBnQTRpoHBbSv0AxgMrnsJfH0-fFtx6PW_y5
Link a la edicion del diagrama de accion del server(en excalidraw):
https://excalidraw.com/#room=f124f8de2eabcd6b127c,OPp9lKtPSRsemZVk_IFf-A
