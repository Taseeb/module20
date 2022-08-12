//The pseudo-code for binary search:

int binary_search(int list[],int low,int high, int num)
{
    if(low<=high)
    {
        int mid = (low+high)/2;

        if(list[mid] == num) return mid;                                   

        else if(num<list[mid]) return binary_search(list,low,mid-1,num);

        else return binary_search(list,mid+1,high,num);
    }

    return -1;
}

/*  total length of list = N/2^0 = N
   
    after 1st iteration, length = N/2^1; 
    after 2nd iteration, length = N/2^2;
    after 3rd iteration, length = N/2^3;
    ..................................
    after kth iteration, length = N/2^k;
    N/2^k = 1(stopping condition)
    => N = 2^k => log2(N) = k
    Time complexity = O(logN)
*/
