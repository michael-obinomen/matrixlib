Matrix Library in C and C++ by Michael Obinomen, for Prof. Kidd's CMSC313 class (10:00AM-11:15AM)

The purpose of this software is to act as a library for matrix functions. In the C++ version, you will find the MatrixFunctions class, which can execute matrix multiplication for a wide set of cases, addition, and transposition. In the C version, you will find the same functions with no compatibility to column matrices. 

matrixlib.c: C code containing functions for matrix multiplication, addition, and transposition given no matrix is a column matrix.

matrixlib.cpp: C++ code containing functions for matrix multiplication, addition, and transposition for a wide set of possiblities. 
Matrices must be using the vector data structure.

makefile: For building the executables. 

To create the executables, simply enter "make matrixlib1" for the C++ version, and "make matrixlib2" for the C version. To run the executables, type "make run1" for the C++ version, and "make run2" for the C version. 

TESTING METHODOLOGY: 
In the testing of the functions, I created the data structure containing the values, as well as another one that will hold the result. The result must have the correct number and format of indices for the functions to work. 
    
In the C++ version I made a vector with 0'd out indices matching what the actual resulting vector would look like. This way, I could just calculate the values.

In the C version, the result array does not need to be initialized before passing it to the function. The size of each dimension just needs to be correct.

ADDITIONAL INFORMATION:
I use a vector in the C++ version because the native C-style arrays and std::array didn't seem to get along with functions if the 2nd dimension onward doesn't have a predetermined size. 

The C version has such a limited set of use cases because I originally intended to copy and paste from the C++ version, but overloading wasn't supported so I didn't bother (this was before I decided to use vectors). 