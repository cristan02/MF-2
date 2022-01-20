#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number :";
    cin >> n;
    float x[n], y[n], p , yp=0,ypc, xp;
    cout << "Enter values of x\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cout << "Enter values of y\n";
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    cout << "Enter interpolating value : ";
    cin >> xp;
    cout << "Langranges interpolation :  ";
    for (int i = 0; i < n; i++)
    {
        p = 1;
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        yp = yp + p * y[i];
        
        if (i ==0 )
            cout << yp;
        else
        {
            ypc=yp-ypc;
            cout <<" + " <<ypc;
        }
            
      
    }
    cout << "\nInterpolated value at " << xp << " is " << yp << endl;
    return 0;
}