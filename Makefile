# Nombre del ejecutable
TARGET = carrera

# Compilador
CXX = g++

# Flags para el compilador
CXXFLAGS = -std=c++11 -Wall -pthread

# Archivos fuente
SRC = carreras.cpp

# Comando por defecto para compilar
all: $(TARGET)

# Regla para compilar el programa
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Limpiar los archivos generados
clean:
	rm -f $(TARGET)
