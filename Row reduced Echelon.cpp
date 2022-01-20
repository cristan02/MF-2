#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter the size of rows and columns\n";
    cin >> r >> c;
    float a[r][c + 1], temp[c + 1], ratio, hold;

    cout << "Enter the matrix in argumented matric form\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            cin >> a[i][j];
        }
    }

    if (a[r - 1][c - 1] == 0)
    {
        for (int i = r - 2; i >= 0; i--)
        {
            int f = 0;
            if (a[i][c - 1] != 0)
            {
                for (int k = 0; k < c; k++)
                {
                    temp[k] = a[r - 1][k];
                    a[r - 1][k] = a[i][k];
                    a[i][k] = temp[k];
                }
                f = 1;
            }
            if (f = 1)
                break;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((i == j) && (a[i][j] == 0))
            {
                for (int l = i + 1; l < r; l++)
                {
                    int f = 0;
                    if (a[l][j] != 0)
                    {
                        for (int k = 0; k < c; k++)
                        {
                            temp[k] = a[i][k];
                            a[i][k] = a[i + l][k];
                            a[i + l][k] = temp[k];
                            f = 1;
                        }
                    }
                    if (f == 1)
                        break;
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j && a[i][j] == 0)
            {
                cout << "\tError!!!\n";
                return 0;
            }
        }
    }

    cout << "Matrix :\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    getch();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i > j)
            {
                if (a[i][j] != 0)
                {
                    ratio = a[i][j] / a[j][j];
                    for (int k = 0; k < c + 1; k++)
                    {
                        a[i][k] = (a[i][k]) - (ratio * a[j][k]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            if ((i == j) && (a[i][j] != 1))
            {
                hold = (a[i][j]);
                for (int k = 0; k < c + 1; k++)
                {
                    a[i][k] = (a[i][k]) / hold;
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i < j)
            {
                if (a[i][j] != 0)
                {
                    ratio = a[i][j] / a[j][j];
                    for (int k = 0; k < c + 1; k++)
                    {
                        a[i][k] = (a[i][k]) - (ratio * a[j][k]);
                    }
                }
            }
        }
    }
    cout << "The matrix in row echelon form :\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    getch();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j && a[i][j] != 1)
            {
                cout << "\tError!!!\n";
                return 0;
            }
        }
    }
    if (r != c)
        cout << "System for given linear eqn is inconsistent\n";
    else
    {
        cout << "The solution for linear eqn is :\n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c + 1; j++)
            {
                if (i == j)
                {
                    cout << "x" << i + 1 << " = " << a[i][c] << endl;
                }
            }
        }
    }
    getch();
    return 0;
}