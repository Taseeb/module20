#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N,K; cin>>N>>K; int A[N];

    for(int i=0;i<N;++i)
    {
        cin>>A[i];
    }

    sort(A,A+N);

    cout<<A[K-1]<<" "<<A[N-K];

    return 0;
}