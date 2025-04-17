#define SCALE_N 3
#define TRANSPOSE_N 3
#define TRANSPOSE_M 2
#define MULT_N 3
#define MULT_P 2
#define ADD_N 2
#include <iostream>

class MatrixFunctions 
{
    public:
    // column matrix + column matrix
    void addMatrices(int m, int result[], int mat1[], int mat2[])
    {
        for (int i = 0; i < m; i++)
        {
            result[i] = mat1[i]+mat2[i];
        }
    }
    // row matrix + row matrix
    void addMatrices(int n, int result[][ADD_N], int mat1[][ADD_N], int mat2[][ADD_N])
    {
        for (int i = 0; i < n; i++)
        {
            result[1][i] = mat1[1][i]+mat2[1][i];
        }
    }
    // m by n matrix + m by n matrix where m and n != 1
    void addMatrices(int m, int n, int result[][ADD_N], int mat1[][ADD_N], int mat2[][ADD_N])
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][j] = mat1[i][j]+mat2[i][j];
            }
        }
    }
    // C * matrix where C is a constant and matrix is not a column matrix
    void scaleMatrix(int C, int m, int n, int mat[][SCALE_N])
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = C * mat[i][j];
            }
        }
    }
    // C * matrix where C is a constant and matrix is a column matrix
    void scaleMatrix(int C, int m, int mat[])
    {
        for (int i = 0; i < m; i++)
        {
            mat[i] = C * mat[i];
        }
    }
    // m by n matrix * n by p matrix where n and p != 1
    void multiplyMatrices(int m, int n, int p, int result[][MULT_P], int mat1[][MULT_N], int mat2[][MULT_P])
    {
        int dprod = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < p; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    dprod += mat1[i][k] * mat2[k][j];
                }
                result[i][j] = dprod;
                dprod = 0;
            }
        }
    }
    // column matrix * row matrix 
    void multiplyMatrices(int m, int p, int result[][MULT_P], int mat1[], int mat2[1][MULT_P])
    {
        int dprod = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < p; j++)
            {
                dprod += mat1[i] * mat2[0][j];
                result[i][j] = dprod;
                dprod = 0;
            }
        }
    }
    // row matrix * column matrix
    void multiplyMatrices(int n, int p, int result[][1], int mat1[][MULT_P], int mat2[])
    {
        int dprod = 0;
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dprod += mat1[0][j] * mat2[j];
            }
        }
        result[0][0] = dprod;
    }
    // m by n * column matrix
    void multiplyMatrices(int m, int n, int result[], int mat1[][MULT_N], int mat2[MULT_N])
    {
        int dprod = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dprod += mat1[i][j] * mat2[n];
            }
            result[i] = dprod;
            dprod = 0;
        }
    }
    // transpose m by n matrix where m and n != 1
    void transposeMatrix(int m, int n, int result[][TRANSPOSE_M], int mat[][TRANSPOSE_N])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result[i][j] = mat[j][i];
            }
        }
    }
    // transpose row matrix
    void transposeMatrix(int n, int result[], int mat[][TRANSPOSE_N])
    {
        for (int i = 0; i < n; i++)
        {
            result[i] = mat[0][i];
        }
    }
    // transpose column matrix
    void transposeMatrix(int m, int result[][TRANSPOSE_M], int mat[])
    {
        for (int i = 0; i < m; i++)
        {
            result[0][i] = mat[i];
        }
    }
    
};

int main()
{
    // test matrices
    int A[2][2] = {{6,4}, {8,3}};
    int B[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int C[2][3] = {{2, 4, 6}, {1, 3, 5}};
    // matrices that will hold result of each operation
    int transposeC[3][2];
    int multBC[2][2];
    int D[2][2];
    // operations
    MatrixFunctions p;
    // 3 * B
    p.scaleMatrix(3, 2, 3, B);
    // C transpose
    p.transposeMatrix(2, 3, transposeC, C);
    // multiply B by C transpose
    p.multiplyMatrices(2, 3, 3, multBC, B, transposeC);
    // add A to product
    p.addMatrices(2, 2, D, A, multBC);
    // output result to console
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << D[i][j] << " ";
        }
        std::cout << std::endl;
    }
}