#include <stdio.h>

void insertion_sort(int [], int);

int main(void)
{
    int i;
    int a[] = {1, 8, 9, 3, 4, 2, 5};
    insertion_sort(a,7);
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
