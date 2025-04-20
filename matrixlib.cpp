#include <iostream>
#include <vector>

class MatrixFunctions 
{
    public:
    // column matrix + column matrix
    void addMatrices(int m, std::vector<int> &result, std::vector<int> &mat1, std::vector<int> &mat2)
    {
        for (int i = 0; i < m; i++)
        {
            result[i] = mat1[i] + mat2[i];
        }
    }
    // row matrix + row matrix
    void addMatrices(int n, std::vector<std::vector<int>> &result, std::vector<std::vector<int>> &mat1, std::vector<std::vector<int>> &mat2)
    {
        for (int i = 0; i < n; i++)
        {
            result[1][i] = mat1[1][i] + mat2[1][i];
        }
    }
    // m by n matrix + m by n matrix where m and n != 1
    void addMatrices(int m, int n, std::vector<std::vector<int>> &result, std::vector<std::vector<int>> &mat1, std::vector<std::vector<int>> &mat2)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
    }
    // C * matrix where C is a constant and matrix is not a column matrix
    void scaleMatrix(int C, int m, int n, std::vector<std::vector<int>> &mat)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat.at(i).at(j) = C * mat[i][j];
            }
        }
    }
    // C * matrix where C is a constant and matrix is a column matrix
    void scaleMatrix(int C, int m, std::vector<int> &mat)
    {
        for (int i = 0; i < m; i++)
        {
            mat[i] = C * mat[i];
        }
    }
    // m by n matrix * n by p matrix where n and p != 1
    void multiplyMatrices(int m, int n, int p, std::vector<std::vector<int>> &result, std::vector<std::vector<int>> &mat1, std::vector<std::vector<int>> &mat2)
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
    void multiplyMatrices(int m, int p, std::vector<std::vector<int>> &result, std::vector<int> &mat1, std::vector<std::vector<int>> &mat2)
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
    void multiplyMatrices(int n, int p, std::vector<std::vector<int>> &result, std::vector<std::vector<int>> &mat1, std::vector<int> &mat2)
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
    void multiplyMatrices(int m, int n, std::vector<int> &result, std::vector<std::vector<int>> &mat1, std::vector<int> &mat2)
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
    void transposeMatrix(int m, int n, std::vector<std::vector<int>> &result, std::vector<std::vector<int>> &mat)
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
    void transposeMatrix(int n, std::vector<int> &result, std::vector<std::vector<int>> &mat)
    {
        for (int i = 0; i < n; i++)
        {
            result[i] = mat[0][i];
        }
    }
    // transpose column matrix
    void transposeMatrix(int m, std::vector<std::vector<int>> &result, std::vector<int> &mat)
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
    std::vector<std::vector<int>> A = {{6, 4}, {8, 3}};
    std::vector<std::vector<int>> B = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> C = {{2, 4, 6}, {1, 3, 5}};
    std::vector<std::vector<int>> transposeC = {{0, 0}, {0, 0}, {0, 0}};
    std::vector<std::vector<int>> multBC = {{0, 0}, {0, 0}};
    std::vector<std::vector<int>> D = {{0, 0}, {0, 0}};
    MatrixFunctions p;
    p.scaleMatrix(3, 2, 3, B);
    p.transposeMatrix(2, 3, transposeC, C);
    p.multiplyMatrices(2, 3, 2, multBC, B, transposeC);
    p.addMatrices(2, 2, D, A, multBC);
    // output to console
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            std::cout << D[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}