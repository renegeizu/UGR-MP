# Nombre archivo: makefile
#

# Directorio include (ficheros .h)
INC = include

# Directorio bin (ejecutables)
BIN = bin

# Directorio obj (ficheros .o)
OBJ = obj

# Directorio lib (bibliotecas)
LIB = lib

# Directorio src (ficheros .cpp)
SRC = src

# Opcion: -Wall (Warning)
# Opcion: -o3 (Optimizar)
# Opcion: -g (Optimizar)

all: $(BIN)/central $(BIN)/main2

bin/central: $(OBJ)/central.o $(LIB)/libformas.a
	g++ -o $(BIN)/central $(OBJ)/central.o -L$(LIB)/ -lformas

bin/main2: $(OBJ)/central.o $(LIB)/libformas.a
	g++ -o $(BIN)/main2 $(OBJ)/central.o -L$(LIB)/ -lformas

lib/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	ar rsv $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

# En el -c agregar los flags (opciones)

obj/punto.o: $(SRC)/punto.cpp $(INC)/punto.h
	g++ -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -I$(INC)/

obj/circulo.o: $(SRC)/circulo.cpp $(INC)/circulo.h $(INC)/punto.h
	g++ -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -I$(INC)/

obj/central.o: $(SRC)/central.cpp $(INC)/circulo.h $(INC)/punto.h
	g++ -c $(SRC)/central.cpp -o $(OBJ)/central.o -I$(INC)/

clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	rm $(BIN)/central $(BIN)/main2
