#include<iostream>
using namespace std;

void input_array(int size,long int a[])
{
    a[0] = 0;
    for(int i=1;i<size;++i)
    {
        cin>>a[i];
    }
}

void prefix_sum(int size,long int sum[],long int a[])
{
    sum[0] = a[0];
    for(int i=1;i<size;++i)
    {
        if(a[i]>0) sum[i] = a[i] + sum[i-1];
        
        else sum[i] = sum[i-1];
    }
}

int main() {

    int N; cin>>N; long int A[N+1]; long int sum[N+1]; int Q;

    input_array(N+1,A); prefix_sum(N+1,sum,A); cin>>Q; int L,R;

    for(int i=1;i<=Q;++i)
    {
        cin>>L>>R; cout<<sum[R]-sum[L-1]<<endl;
    }

    return 0;

}