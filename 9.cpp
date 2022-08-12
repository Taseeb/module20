#include<iostream>
using namespace std;
int main()
{
    int N,k; cin>>N>>k; int A[N]; int c = 0;

    for(int i=0;i<N;++i)
    {
        cin>>A[i];
    }

    for(int i=0;i<N-1;++i)
    {
        for(int j=i+1;j<N;++j)
        {
            if(A[i]+A[j]==k) c++;
        }
    } 

    cout<<c; return 0;
}