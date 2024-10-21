# Carreras_ssoo

# Simulación de Carrera de Autos con Hebras

## Descripción

Este programa simula una carrera de autos utilizando la programación concurrente en C++ con la biblioteca estándar de hebras (`std::thread`). Cada automóvil en la carrera es representado por una hebra independiente. Los autos avanzan una distancia aleatoria en cada iteración, con pausas aleatorias que simulan distintas velocidades. El programa permite visualizar en tiempo real el progreso de cada automóvil y muestra el orden final de llegada.

## Requisitos

- **Compilador**: g++ con soporte para C++11 o superior.
- **Bibliotecas**: Se utiliza la biblioteca estándar de C++ (`thread`) para manejar las hebras.

## Funcionalidades

- **Hebras para cada auto**: Cada automóvil es controlado por una hebra independiente.
- **Avance aleatorio**: Los autos avanzan una cantidad aleatoria de metros en cada iteración (máximo 10 metros).
- **Velocidad aleatoria**: Los autos se detienen por un tiempo aleatorio entre 100 y 500 ms en cada iteración, simulando diferentes velocidades.
- **Progreso en tiempo real**: El programa muestra en la terminal el progreso de cada automóvil.
- **Ganador y orden de llegada**: Al finalizar la carrera, se muestra el orden de llegada de los autos.

## Instrucciones de Uso

### Compilación

Puedes compilar el programa usando el compilador `g++` manualmente o mediante `make` con el `Makefile` incluido.

#### Opción 1: Compilar mediante 'make'

Abrir terminal linux y situarse dentro de la carpeta del programa llamada "Carreras_ssoo" donde encontrarás un archivo 'carreras.cpp', 'Makefile' y 'README.md'

- Ejecuta el siguiente comando en la terminal para compilar el programa:

make

- Luego para iniciar la carrera utiliza en la terminal

./carrera 100 3

- Luego se ejecutará la carrera y podrás visualizarla en la terminal y con el comando 'htop'