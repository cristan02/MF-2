#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter the size of rows and columns\n";
    cin >> r >> c;
    float a[r][c + 1], temp[c + 1], ratio;

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
    cout << "The matrix is :\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    getch();
    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c ; j++)
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
    cout << "Triangular form matrix :\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    getch();

    if (r != c)
        cout << "System for given linear eqn is inconsistent\n";
    
    cout << "The solution for linear eqn is :\n";
    for (int i = 0; i < r; i++)
    {
        float sum = 0;
        if (i == 0)
        {
            temp[i] = a[r - 1][c] / a[r - 1][c - 1];
        }
        else
        {
            for (int j = 0; j <= i; j++)
            {
                if (j != i)
                {
                    sum = sum + (temp[j] * a[r - 1 - i][c - 1 - j]);
                }
                else
                {
                    sum = a[r - 1 - i][c] - sum;
                    temp[i] = sum / a[r - 1 - i][c - 1 - j];
                }
            }
        }
    }
    for (int i = 0; i < c; i++)
    {
        cout << "x" << c - i << " = " << temp[i] << endl;
    }
    getch();
    return 0;
}