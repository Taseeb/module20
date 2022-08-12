#include<iostream>
using namespace std;

int main()
{
    int n,m; cin>>n>>m; int A[n+1][m+1]; int sum = 0;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>A[i][j];

            if(i%2==0 && j%2!=0) sum += A[i][j];
        }
    }

    cout<<sum;
}