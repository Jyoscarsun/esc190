# include <stdio.h>

int main()
{
    int *p = 0;
    *p = 90;
    printf("%d\n", *p);

    int **p_p_int = (int **)malloc(50*sizeof(int *));
    int *p_int = *p_p_int;
    int a = *p_int;
    // Create segmentation error, try to access the value at a randomly generated location
    printf("%d\n", a);
}