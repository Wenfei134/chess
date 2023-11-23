CXX = g++
CXXFLAGS =-std=c++14 -Wall -Werror=vla -MMD
EXEC = chess
OBJECTS = main.o chesscontroller.o chessgame.o board.o square.o move.o pieces/piece.o pieces/pawn.o pieces/knight.o pieces/bishop.o pieces/rook.o pieces/queen.o pieces/king.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

