#include <iostream>
#include <algorithm>
using namespace std;

void input_array(int size,int a[])
{
    for(int i=1;i<size;++i)
    {
        cin>>a[i];
    }
}

int binary_search(int array[],int low,int high, int num)
{
    if(low<=high)
    {
        int mid = (low+high)/2;

        if(array[mid] == num) return mid;                                   

        else if(num<array[mid]) return binary_search(array,low,mid-1,num);

        else return binary_search(array,mid+1,high,num);
    }

    return -1;
}

int main()
{
    int N; cin>>N; int k; cin>>k;
    int A[N+1]; input_array(N+1,A); sort(A+1,A+N+1);
    int low = 1; int high = N;
    int index = binary_search(A,low,high,k);
    (index==-1)? cout<<k<<" Not found" : cout<<index;
}