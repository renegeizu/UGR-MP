
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -ansi -pedantic -Wall -Wextra -Wwrite-strings -Werror -g -c -std=c++0x -I$(INC)


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/arteASCII2


$(BIN)/testplano: $(OBJ)/testplano.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/testplano $(OBJ)/testplano.o -L$(LIB)/ -limagen

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o -L$(LIB)/ -limagen
	
$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/arteASCII $(OBJ)/arteASCII.o -L$(LIB)/ -limagen

$(BIN)/arteASCII2: $(OBJ)/arteASCII2.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/arteASCII2 $(OBJ)/arteASCII2.o -L$(LIB)/ -limagen

	
$(LIB)/libimagen.a: $(OBJ)/pgm.o $(OBJ)/imagen.o $(OBJ)/byte.o $(OBJ)/lista.o
	ar rsv $(LIB)/libimagen.a $(OBJ)/pgm.o $(OBJ)/imagen.o $(OBJ)/byte.o $(OBJ)/lista.o

	
$(OBJ)/testplano.o: $(SRC)/testplano.cpp
	$(CXX) -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o $(CPPFLAGS)

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp
	$(CXX) -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o $(CPPFLAGS)
	
$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp
	$(CXX) -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o $(CPPFLAGS)

$(OBJ)/arteASCII2.o: $(SRC)/arteASCII2.cpp
	$(CXX) -c $(SRC)/arteASCII2.cpp -o $(OBJ)/arteASCII2.o $(CPPFLAGS)

	
$(OBJ)/imagen.o: $(SRC)/imagen.cpp
	$(CXX) -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o $(CPPFLAGS)

$(OBJ)/pgm.o: $(SRC)/pgm.cpp
	$(CXX) -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o $(CPPFLAGS)

$(OBJ)/byte.o: $(SRC)/byte.cpp
	$(CXX) -c $(SRC)/byte.cpp -o $(OBJ)/byte.o $(CPPFLAGS)
	
$(OBJ)/lista.o: $(SRC)/lista.cpp
	$(CXX) -c $(SRC)/lista.cpp -o $(OBJ)/lista.o $(CPPFLAGS)

	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Limpiando..."
	rm -rf $(OBJ)/* $(LIB)/*

mrproper: clean
	rm -rf $(BIN)/* doc/html/* *.pgm *1 *2 *3 *4
