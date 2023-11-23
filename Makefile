CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=vla -MMD
#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
EXEC = chess
SOURCES = $(wildcard Graphics/*.cpp) $(wildcard pieces/*.cpp) $(wildcard *.cpp) 
OBJECTS = ${SOURCES:.cpp=.o}
DEPENDS = ${OBJECTS:.o=.d}

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IC:\msys64\mingw_dev_lib\x86_64-w64-mingw32\include\SDL2 -IC:\msys64\mingw_dev_lib\x86_64-w64-mingw32-image\include\SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LC:\msys64\mingw_dev_lib\x86_64-w64-mingw32\lib -LC:\msys64\mingw_dev_lib\x86_64-w64-mingw32-image\lib

%.o: %.cpp ${SOURCES}
	${CXX} -c -o $@ $< ${CXXFLAGS}  ${INCLUDE_PATHS} ${LIBRARY_PATHS}  ${LINKER_FLAGS}

all: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} ${INCLUDE_PATHS} ${LIBRARY_PATHS} ${LINKER_FLAGS} -o ${EXEC} 
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
