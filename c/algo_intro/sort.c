#include <stdio.h>
#include <limits.h>

#define MAX 10

void insertion_sort(int [], int);
void mergesort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);

int main(void)
{
    int i;
    int a[] = {1, 8, 9, 3, 4, 2, 5};
    //测试插入排序
    //insertion_sort(a,7);

    //测试归并排序
    mergesort(a, 0, 6);

    for (i=0; i<7; ++i)
        printf("%d\n", a[i]);
    return 0;
}

void insertion_sort(int arr[], int n)
{
    int i;
    for (i=0; i<n; ++i)
    {
        int j = i + 1;
        int key = arr[j];
        while (key<arr[j-1] && j>0)
        {
            arr[j] = arr[j-1];
            --j;
            //printf("\ti=%d,j=%d", i, j);
        }
        arr[j] = key;
    }

}

void mergesort(int arr[], int p, int r)
{
    if (p<r)
    {
        int q = (p + r) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}
    
void merge(int arr[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[MAX], right[MAX];
    for (i=0; i<n1; ++i)
    {
        left[i] = arr[p+i];
        //printf("\tarr[%d]=%d", p+i, arr[p+i]);
    }
    for (j=0; j<n2; ++j)
    {
        right[j] = arr[q+1+j];
        //printf("\tarr[%d]=%d", q+1+j, arr[q+1+j]);
    }
    
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    
    i = j = 0;
    for (k=p; k<=r; k++)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
    }
}
        

    
    


    
    
