CXX=clang++
CXXFLAGS=-std=c++14 -framework OpenGL -framework GLUT
WARN=-Wno-deprecated-declarations
OUT=paintgl
INCLUDE=src/include

all:
	$(CXX) -o $(OUT) src/*.cpp $(CXXFLAGS) $(WARN) -I$(INCLUDE)
