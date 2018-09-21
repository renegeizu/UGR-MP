
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen


$(BIN)/testimagen: $(OBJ)/testimagen.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/testimagen $(OBJ)/testimagen.o -L$(LIB)/ -limagen

$(BIN)/testplano: $(OBJ)/testplano.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/testplano $(OBJ)/testplano.o -L$(LIB)/ -limagen

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o -L$(LIB)/ -limagen
	
$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	$(CXX) -o $(BIN)/arteASCII $(OBJ)/arteASCII.o -L$(LIB)/ -limagen

	
$(LIB)/libimagen.a: $(OBJ)/pgm.o $(OBJ)/imagen.o $(OBJ)/byte.o
	ar rsv $(LIB)/libimagen.a $(OBJ)/pgm.o $(OBJ)/imagen.o $(OBJ)/byte.o

	
$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp
	$(CXX) -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o $(CPPFLAGS)

$(OBJ)/testplano.o: $(SRC)/testplano.cpp
	$(CXX) -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o $(CPPFLAGS)

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp
	$(CXX) -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o $(CPPFLAGS)
	
$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp
	$(CXX) -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o $(CPPFLAGS)

	
$(OBJ)/imagen.o: $(SRC)/imagen.cpp
	$(CXX) -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o $(CPPFLAGS)

$(OBJ)/pgm.o: $(SRC)/pgm.cpp
	$(CXX) -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o $(CPPFLAGS)

$(OBJ)/byte.o: $(SRC)/byte.cpp
	$(CXX) -c $(SRC)/byte.cpp -o $(OBJ)/byte.o $(CPPFLAGS)

	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	rm $(BIN)/testimagen $(BIN)/testplano $(BIN)/testarteASCII $(BIN)/arteASCII
