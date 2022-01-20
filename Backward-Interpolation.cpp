//Write a program to implement Newton Backward Interpolation.
#include <iostream>
using namespace std;
int fact(int);
int main()
{
    int n, i, j, ch = 30;
    float arr[10][11], px = 1, x, y, p, h;
    cout << "\nEnter the no of data:";
    cin >> n;
    cout << "\nEnter the data:";
    for (i = 0; i < n; i++)
    {
        cout << "\nX"<< i + 1<< "=";
        cin >> arr[i][0];
        cout << "\nY"<< i + 1<< "=";
        cin >> arr[i][1];
    }
    //forming the difference table
    for (j = 2; j <= n; j++)
    {
        for (i = 0; i < n - 1; i++)
            arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];
    }
    //printing table
    cout << "\nThe difference table";
    cout << "\n\tX \tY";
    for (i = 0; i < n - 1; i++)
        cout << "\t%"<< ch<<"^"<< i + 1;
    for (i = 0; i < n; i++)
    {
        cout << "\n";
        for (j = 0; j < n + 1 - i; j++)
            cout << "\t"<< arr[i][j];
    }
    cout << "\nEnter the value of x for f(x)";
    cin >> x;
    //calculate the value of f(x) for x
    h = arr[n - 1][0] - arr[n - 2][0];
    p = (x - arr[n - 1][0]) / h;
    y = arr[n - 1][1];
    for (i = 1; i < n; i++)
    {
        px = px * (p + (i - 1));
        y = y + (arr[n - 1 - i][i + 1] * px) / fact(i);
    }
    cout << "\nthe value of f(x) at x= "<< x<<" is "<< y;
}
int fact(int n)
{
    int f = 1, i;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}