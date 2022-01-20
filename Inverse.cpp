#include<iostream>
using namespace std;
int main(){
    int r, c;
    cout << "Enter the size of rows and columns\n";
    cin >> r >> c;
    float a[r][c + c], temp[c + c], ratio,tt;

    cout << "Enter the matrix in argumented matric form\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = c; j < c + c; j++)
        {
            if(j - c == i)
            a[i][j]=1;
            else
            a[i][j]=0;
        }
    }

    cout << "Matrix :\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c + c; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c ; j++)
        {
            if ( i > j )
            {
                if (a[i][j] != 0)
                {
                    ratio = a[i][j] / a[j][j];
                    for (int k = 0; k < c + c; k++)
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
            if ((i==j) && (a[i][j]!=1))
            {
                tt=(a[i][j]);
                for(int k=0;k<c+c;k++)
                {
                    a[i][k] = (a[i][k]) / tt;
                }
            }
        }
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c ; j++)
        {
            if ( i < j )
            {
                if (a[i][j] != 0)
                {
                    ratio = a[i][j] / a[j][j];
                    for (int k = 0; k < c + c; k++)
                    {
                        a[i][k] = (a[i][k]) - (ratio * a[j][k]);
                    }
                }
            }
        }
    }
    for(int i=0;i < r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if( i==j && a[i][j]==0)
            {
                cout<<"Zero element found in identity matrix\n";
                return 0;
            }
        }
    }
    cout << "Inverse :\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = c; j < c + c; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}