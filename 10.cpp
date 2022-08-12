void Swap(int* x,int* y);

void bubble_sort(int *arr,int size)
{
    for(int i=1;i<=size-1;++i)
    {
        for(int j=0;j<=size-2;++j)
        {
            if(arr[j]>arr[j+1]) Swap(&arr[j],&arr[j+1]);
        }
    }
}

//In case of sorted array: bubble sort Time complexity = O(n);

void insertion_sort(int *arr,int size)
{
    for(int i=1;i<size;++i)
    {
        int key = arr[i]; int j=i-1;
        
        while(j>=0,arr[j]>key)
        {
            arr[j+1] = arr[j]; j--;
        }

        arr[j+1] = key;
    }
}

//In case of sorted array: insertion sort Time complexity = O(n);

//Algorithm for counting sort:

/*Step1: Find max value of arr[n].
Step2:  Take int count[max+1] and find frequency of arr values
Step3:  Take int count_sum[max+1] array and calculate prefix sums
Step4:  Take int final[n] array. 
In final array:
    for int i=n-1-->0
        int k = --count_sum[arr[i]];
        final[k] = arr[i]; 
*/

//Time complexity of counting sort : O(n); but space complexity depends on the max element of arr. And depending on the size of max element it may be impossible to implement counting sort despite the array being sorted. So, it is impractical to implement it.

//So, for sorted array, the insertion sort will take less time because the inner loop won't work unlike bubble sort where the inner loop and if conditions occure despite there being no swappings.