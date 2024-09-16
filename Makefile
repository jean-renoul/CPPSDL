TARGET = game2048


INCLUDE_DIR = C:/Users/micka/Documents/Dev/C++/Games/2048/Library/SDL2-devel-2.30.7-mingw/SDL2-2.30.7/x86_64-w64-mingw32/include
LIB_DIR = C:/Users/micka/Documents/Dev/C++/Games/2048/Library/SDL2-devel-2.30.7-mingw/SDL2-2.30.7/x86_64-w64-mingw32/lib


SRCS = Main.cpp Grid.cpp Bloc.cpp Action.cpp Score.cpp


CXX = g++
CXXFLAGS = -Wall -g -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/SDL2
LDFLAGS = -L$(LIB_DIR) -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf


all: $(TARGET)


$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)


run: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(TARGET)
