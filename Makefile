CPP_FILES = $(wildcard *.cpp)

CXX_FLAGS = -g -Wall -std=c++11
# Add include paths
CXX_FLAGS += -I/usr/local/include/ -L/usr/local/lib -I../veil/include -I../veil-sdl/include
# Add lib paths
CXX_FLAGS += -L../veil/lib -L../veil-sdl/lib

LIBS = -lveil -lveilsdl -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -luv

RM_RF := rm -rf
CP_R := cp -r

.PHONY: all
all: bin/game

bin/game: bin bin/assets
	make -C ../veil
	make -C ../veil-sdl
	$(CXX) $(CXX_FLAGS) $(CPP_FILES) $(LIBS) -o bin/game

bin/assets:
	@$(CP_R) assets bin

bin:
	@mkdir bin

.PHONY: clean
clean:
	-$(RM_RF) bin

.PHONY: distclean
distclean: clean
	make clean -C ../veil
	make clean -C ../veil-sdl

.PHONY: run
run: bin/game
	@-cd bin && ./game
