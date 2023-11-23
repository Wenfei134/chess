CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=vla -MMD
EXEC = chess
SOURCES = $(shell find . -wholename '**/*.cpp')
OBJECTS = ${SOURCES:.cpp=.o}
DEPENDS = ${OBJECTS:.o=.d}

####################### CHANGE TO YOUR ROOT #######################
ROOT_PATH=/Users/whe/Desktop/Current-Courses/workshop/cs246-chess-main/

####################### WINDOWS ###################################
# # LINKER_FLAGS specifies the libraries we're linking against
# LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
# # INCLUDE_PATHS specifies the additional include paths we'll need
# INCLUDE_PATHS = -IC:\msys64\mingw_dev_lib\x86_64-w64-mingw32\include\SDL2 -IC:\msys64\mingw_dev_lib\x86_64-w64-mingw32-image\include\SDL2
# # LIBRARY_PATHS specifies the additional library paths we'll need
# LIBRARY_PATHS = -LC:\msys64\mingw_dev_lib\x86_64-w64-mingw32\lib -LC:\msys64\mingw_dev_lib\x86_64-w64-mingw32-image\lib

####################### MACOS #####################################
# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -framework SDL2 -framework SDL2_image
# INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS=-I${ROOT_PATH}chess/SDL2.framework/Headers/ -I${ROOT_PATH}chess/SDL2_image.framework/Headers/
# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS=-L${ROOT_PATH}chess/SDL2.framework/Versions/A/ -L${ROOT_PATH}chess/SDL2_image.framework/Versions/A/ -Wl,"-rpath" "${ROOT_PATH}chess/"
# FRAMEWORK_PATHS specifies the frameworks
FRAMEWORK_PATHS=-F${ROOT_PATH}chess/

all: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} ${INCLUDE_PATHS} ${LIBRARY_PATHS} ${FRAMEWORK_PATHS} -o ${EXEC} ${LINKER_FLAGS}
-include ${DEPENDS}

%.o: %.cpp ${SOURCES}
	${CXX} -c -o $@ $< ${CXXFLAGS} ${INCLUDE_PATHS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
