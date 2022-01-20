#include <iostream>
#include <math.h>
using namespace std;
int ele;
float fxl, fxr, fxu, EP = 0.01, a, xr, b;
float solution(float n, float a[])
{
    float temp = a[0];
    for (int i = 1; i < ele; i++)
    {
        temp = temp + (a[i] * pow(n, i));
    }
    return temp;
}
int main()
{
    cout << "Enter the no. of elements\n";
    cin >> ele;
    float arr[ele];
    for (int i = ele - 1; i >= 0; i--)
    {
        cout << "Enter coefficient of x^" << i << endl;
        cin >> arr[i];
    }
    cout << "Enter values of a and b respectively\n";
    cin >> a >> b;

    if (solution(a, arr) * solution(b, arr) > 0)
    {
        cout << "You have taken incorrect values of a and b\n";
        return 0;
    }
    while ((b - a) >= EP)
    {
        xr = (a + b) / 2;
        if (solution(xr, arr) == 0.0)
            break;
        else if (solution(xr, arr) * solution(a, arr) < 0)
            b = xr;
        else
            a = xr;
    }
    cout << "The value of root is : " << xr;
}