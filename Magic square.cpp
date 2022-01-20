#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of matrix greater the two : ";
    cin>>n;
    int arr[n][n];
    int i,j,c=1;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j]=0;
    i=n/2;
    j=n-1;
    while(c <= (n * n))
    {
        if(c==1)
        {
            arr[i][j]=c;
            c++;
            i=i-1;
            j=j+1;
        }
        else 
        {
            if ((i==-1) && (j==n))
            {
                i=0;
                j=n-2;
            }
            else if((i==-1) || (j==n))
            {
                if(i==-1)
                    i=n-1;
                if(j==n)
                    j=0;
            }
            if(arr[i][j]==0)
            {
                arr[i][j]=c;
                c++;
                i=i-1;
                j=j+1;
            }
            else
            {
                i=i+1;
                j=j-2;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}