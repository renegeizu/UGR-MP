
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -ansi -pedantic -Wall -Wextra -Wwrite-strings -Werror -g -c -std=c++0x -I$(INC)

all: $(BIN)/arteASCII2 $(BIN)/testarteASCII $(BIN)/testimagen

# ************ Creacion de Objetos ************


# ************ Creacion de bibliotecas ************

	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Limpiando..."
	rm -rf $(OBJ)/* $(LIB)/*
	
mrproper: clean
	rm -rf $(BIN)/* doc/html/*
