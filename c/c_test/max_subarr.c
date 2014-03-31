//max_subarr.c
//求解最大子数组
#include <stdio.h>

int main(void)
{
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(a)/sizeof(int);
    force_search(a, n);

    return 0;
}

void force_search(int a[], int n)
{
    int i, j, p, q;
    int sum, max=0;
    for (i=0; i<=n; ++i)
        printf("\t%d", a[i]);
    printf("\n");
    for (i=0; i<n; ++i)
    {
        sum = 0;
        for (j=i; j<n; ++j)
        {
            sum += a[j]; 
            if (sum > max)
            {
                max = sum;
                p = i;
                q = j;
            }

        }
    }

    printf("%d", max);
    for (i=p; i<=q; ++i)
        printf("\t%d", a[i]);
} 

int recure_search(int a[], int b[], int p, int r)
{
    if (p==r)
        return a[p];
    else
    {
        int q = (p + r) / 2;
        recure_search(a, p, q);
        recure_search(a, q+1, r);
    }

}
