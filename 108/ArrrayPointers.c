#include <stdio.h>

typedef int arr1d10[10];
typedef int arr2d3[3][3];

void test1d0(arr1d10 *arr)
{
    /* This is the same as the case with function test1d1(). */
    printf("Element: %d\n", (*arr)[0]);
}

void test1d1(int (*arr)[10])
{
    /* As arr is a pointer to an array of 10 integers, pointer arithmetic will work with the size of an array of 10 integers, i.e. 
       when you increment arr it will increment by sizeof(arr1d10), which is 40 bytes.
       That's why when you dereference it, you can't simply do arr[1], because it will increment arr by 40 bytes forward.
       Also when dereferencing it, because it thinks it points to a whole array it will give you that array - it's address.
       This is another reason you can't do just arr[i], because those will be just addresses.
       The correct way is to dereference it once(*arr)), to get the address (think of implicitely casting to int*) and then you can do as usually (*arr)[1]).
    */
    printf("Element: %d\n", (*arr)[1]);
}

void test2d0(arr2d3 *arr2d)
{
    /* This is a little more complicated, but the principle is the same as above. */
    printf("Element: %d\n", (*arr2d)[0][0]);
}

void test2d1(int (*arr2d)[3][3])
{
    printf("Element: %d\n", (*arr2d)[0][1]);
}

int main(void)
{
    arr1d10 arr1d = {0, 1, 2};
    arr2d3 arr2d = { {0,1},{2,3},{3,4}};
    int (*p1d)[10] = &arr1d; 
    int (*p2d)[3][3] = &arr2d;

    printf("********** PRINT 1D array **********\n");
    test1d0(&arr1d);
    test1d1(&arr1d);
    test1d0(p1d);
    test1d1(p1d);

    printf("********** PRINT 2D array **********\n");
    test2d0(&arr2d);
    test2d1(&arr2d);
    test2d0(p2d);
    test2d1(p2d);

    return 0;
}