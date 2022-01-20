#include<iostream>
#include<math.h>
using namespace std;

int det(int n, int a[10][10])
{
    int suba[10][10]; 
    int d = 0; 
    if (n == 2) 
    {
        d=( (a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
        return d;
    }
    else
    {  
        for(int c = 0; c < n; c++)
        {  
            int subi = 0,subj=0;  
            for(int i = 1; i < n; i++)
            {  
                for(int j = 0; j < n; j++)
                {    
                    if (j == c)
                    {
                        continue;
                    }
                    suba[subi][subj] = a[i][j];
                    subj++;
                    if(subj == n-1)
	                {
		                subi++;
		                subj = 0;
	                }
                }
            }
        d = d + (pow(-1 ,c) * a[0][c] * det(n - 1 ,suba));
        }
    }
    return d;
}
int main()
{
    int n;
    cout<<"Enter the size of marix : " ;
    cin>>n;
    int arr[10][10];
    cout<<"Enter the elements :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"\nDeterminant of marix is :"<<det(n,arr);
}