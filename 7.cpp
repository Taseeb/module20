#include<bits/stdc++.h>
using namespace std;
void input_array(int size,int a[])
{
    for(int i=0;i<size;++i)
    {
        cin>>a[i];
    }
}

int max_of_array(int size,int a[])
{
    int max = a[0]; int index = 0;
    for(int i=0;i<size;++i)
    {
        if(a[i]>max) {max = a[i]; index = i;}
    }
    return max;
}

void frequency(int main_size, int main_array[], int counter_array[])
{
    for(int i=0;i<main_size;i++)
    {
        counter_array[main_array[i]]++;
    }
}

int main()
{
    int N;cin>>N; int A[N]; input_array(N,A); int size = max_of_array(N,A)+1;

    int count[size]; memset(count,0,sizeof(count)); int c=0; frequency(N,A,count);

    for(int i=0;i<size;++i)
    {
        if(count[i]>0) c++;
    }

    cout<<c;
}