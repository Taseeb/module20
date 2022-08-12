#include<iostream>
#include<cmath>
#include<cstdbool>
using namespace std;

bool is_Prime(int num)
{
    if(num==1) return false;

    else if(num==2) return true;

    else if(num>=3)
    {
        for(int i=2;i<=sqrt(double(num));i++)
        {
            if(num%i==0) return false;
        }
    }

    return true;
}

int main()
{
    int N; cin>>N;

    for(int i=1;i<=N;++i)
    {
        if(is_Prime(i)) cout<<i<<" ";
    }

    return 0;
}