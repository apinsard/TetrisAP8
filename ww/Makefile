# Répertoire des fichiers sources du projet
SRC = ../src
INCDIRS = -I../src/appliBase
INCDIRS += -I../src/glut
INCDIRS += -I../src/math
INCDIRS += -I../src/tetris

# Répertoire des destinations des binaires
BIN = ../bin

# Usage des librairies Linux
LIBS = -lX11 -lglut -lGL -lGLU -lm

# Commande de compilation
# OPTFLAGS = -W -Wall -ansi -pedantic
OPTFLAGS = -Wall
GPP = g++ $(OPTFLAGS) $(INCDIRS)

all: tetris

#------------------------------------------------------------
# execution projet tetris
#------------------------------------------------------------
tetris: $(BIN)/CProjetTetris.o $(BIN)/CTetrisGame.o $(BIN)/CPieceAbstract.o $(BIN)/CTPiece.o $(BIN)/CRandomizer.o $(BIN)/CGuiGlut.o $(BIN)/CApplication.o $(BIN)/CRenderer.o $(BIN)/CMatrix44.o $(BIN)/CTGameTable.o $(BIN)/main.o
	$(GPP) -o $(BIN)/tetris.bin $^ $(LIBS)

#------------------------------------------------------------
# compilation projet tetris
#------------------------------------------------------------

$(BIN)/%.o: $(SRC)/tetris/%.cpp
	$(GPP) -o $@ -c $<

#------------------------------------------------------------
# compilation application 3D + Matrix44
#------------------------------------------------------------

$(BIN)/%.o: $(SRC)/appliBase/%.cpp
	$(GPP) -o $@ -c $<

$(BIN)/%.o: $(SRC)/math/%.cpp
	$(GPP) -o $@ -c $<

$(BIN)/main.o: $(SRC)/main.cpp
	$(GPP) -o $@ -c $<

#------------------------------------------------------------
# compilation et exécution des tests
#------------------------------------------------------------

test: testPiece

testPiece: testCTPiece testCLPiece testCZPiece

$(BIN)/%.o: $(SRC)/tetris/testPiece/%.cpp
	$(GPP) -o $@ -c $<

testCTPiece: $(BIN)/testCTPiece.o $(BIN)/CTPiece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

testCLPiece: $(BIN)/testCLPiece.o $(BIN)/CLPiece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

testCZPiece: $(BIN)/testCZPiece.o $(BIN)/CZPiece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

#------------------------------------------------------------
# autres commandes
#------------------------------------------------------------
clean:
	rm -rf $(BIN)/*.o

mrproper: clean
	rm -rf $(BIN)/*.bin

cleansrctetris:
	rm -f $(SRC)/tetris/*.*~

