#include <stdio.h>

void quicksort(int ar[], int left, int right)
{
    int pivot, l, r, temp;
    if (left < right)
    {
        pivot = ar[left];
        l = left;
        r = right;
        while (l < r)
        {
            while (ar[l] <= pivot && l <= right)
            {
                l++;
            }
            while (ar[r] > pivot && r >= left)
            {
                r--;
            }
            if (l < r)
            {
                temp = ar[l];
                ar[l] = ar[r];
                ar[r] = temp;
            }
        }
        temp = ar[r];
        ar[r] = pivot;
        pivot = temp;
        quicksort(ar, left, r - 1);
        quicksort(ar, r + 1, right);
    }
}


void main()
{
    int ar[7]={20,11,23,14,55,66,43};
    int i;
    quicksort(ar, 0, 6);
    printf("After applying quick sort\n");
    for (i = 0; i < 7; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}
