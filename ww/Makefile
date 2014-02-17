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
tetris: $(BIN)/CProjetTetris.o $(BIN)/CTetrisGame.o $(BIN)/CPieceAbstract.o $(BIN)/CTPiece.o $(BIN)/COPiece.o $(BIN)/CIPiece.o $(BIN)/CZ1Piece.o $(BIN)/CZ2Piece.o $(BIN)/CL1Piece.o $(BIN)/CL2Piece.o $(BIN)/CRandomizer.o $(BIN)/CGuiGlut.o $(BIN)/CApplication.o $(BIN)/CRenderer.o $(BIN)/CMatrix44.o $(BIN)/CTGameTable.o $(BIN)/main.o
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

testPiece: testCTPiece testCOPiece testCIPiece testCZ1Piece testCZ2Piece testCL1Piece testCL2Piece

$(BIN)/%.o: $(SRC)/tetris/testPiece/%.cpp
	$(GPP) -o $@ -c $<

testCTPiece: $(BIN)/testCTPiece.o $(BIN)/CTPiece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

testCOPiece: $(BIN)/testCOPiece.o $(BIN)/COPiece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

testCIPiece: $(BIN)/testCIPiece.o $(BIN)/CIPiece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

testCZ1Piece: $(BIN)/testCZ1Piece.o $(BIN)/CZ1Piece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

testCZ2Piece: $(BIN)/testCZ2Piece.o $(BIN)/CZ2Piece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

testCL1Piece: $(BIN)/testCL1Piece.o $(BIN)/CL1Piece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
	$(GPP) -o $(BIN)/$@.bin $^
	$(BIN)/$@.bin

testCL2Piece: $(BIN)/testCL2Piece.o $(BIN)/CL2Piece.o $(BIN)/CPieceAbstract.o $(BIN)/test.o
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

