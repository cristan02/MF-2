#include <iostream>
using namespace std;
int main()
{
    int r, c,rank=0,f;
    cout << "Enter the size of rows and columns\n";
    cin >> r >> c;
    int a[r][c];

    cout << "Enter the matrix \n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c ; j++)
        {
            if ( i > j )
            {
                if (a[i][j] != 0)
                {
                    int ratio = a[i][j] / a[j][j];
                    for (int k = 0; k < c; k++)
                    {
                        a[i][k] = (a[i][k]) - (ratio * a[j][k]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        f=0;
        for (int j = 0; j < c ; j++)
        {
            cout << a[i][j] << "\t";
            if(a[i][j]!=0)
                f=1;
        }
        cout<<endl;
        if( f==1)
            rank++;
    } 
    cout<<"Rank of matrix is : "<<rank<<endl;
    return 0;
}