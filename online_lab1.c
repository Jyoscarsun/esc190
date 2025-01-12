# include <stdio.h>

int linear_search(int *a, int sz, int elem)
{
    // This function returns the index of the first occurrence of the element 
    //elem in a block of ints of size sz. Assume elem occurs in a
    for (int i = 0; i < sz; i++)
    {
        if(*(a+i) == elem)
        {
            return i;
        }
    }
}

void reverse_arr(int *arr, int sz)
{
    for(int i = 0; i < sz/2; i++)
    {
        int temp = *(arr+i);
        *(arr+i) = *(arr+sz-i-1);
        *(arr+sz-i-1) = temp;
    }
}

int main()
{
    printf("Hello World!\n");
    int a[] = {1,2,3,4,5,6};
    printf("The index of the element is %d\n", linear_search(a,6,5));
    
    reverse_arr(a,6);
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%d ", a[i]);
    }
}