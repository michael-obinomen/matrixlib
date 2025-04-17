CXX = g++
CXXFLAGS = -Wall

matrixlib1: matrixlib.cpp
	$(CXX) $(CXXFLAGS) matrixlib.cpp -o matrixlibcpp
matrixlib2: matrixlib.c
	$(CXX) $(CXXFLAGS) matrixlib.c -o matrixlibc

run1:
	./matrixlibcpp
run2:
	./matrixlibc