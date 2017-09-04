CXX=clang++
CXXFLAGS=-std=c++14 -framework OpenGL -framework GLUT
WARN=-Wno-deprecated-declarations
INCLUDE=include
OUT=target/paintgl

all:
	$(CXX) -o $(OUT) *.cc $(CXXFLAGS) $(WARN) -I$(INCLUDE)

run:
	./$(OUT)
