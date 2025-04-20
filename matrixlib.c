#include <stdio.h>

// m by n matrix + m by n matrix where m and n != 1
void addMatrices(int m, int n, int result[m][n], int mat1[m][n], int mat2[m][n])
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
void scaleMatrix(int C, int m, int n, int mat[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = C * mat[i][j];
        }
    }
}
// m by n matrix * n by p matrix where n and p != 1
void multiplyMatrices(int m, int n, int p, int result[m][p], int mat1[m][n], int mat2[n][p])
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
// transpose m by n matrix where m and n != 1
void transposeMatrix(int m, int n, int result[n][m], int mat[m][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = mat[j][i];
        }
    }
}

int main()
{
    // test matrices
    int A[2][2] = {{6,4}, {8,3}};
    int B[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int C[2][3] = {{2, 4, 6}, {1, 3, 5}};
    int transposeC[3][2];
    int multBC[2][2];
    int D[2][2];
    scaleMatrix(3, 2, 3, B);
    transposeMatrix(2, 3, transposeC, C);
    multiplyMatrices(2, 3, 2, multBC, B, transposeC);
    addMatrices(2, 2, D, A, multBC);
    // output result to console
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
}