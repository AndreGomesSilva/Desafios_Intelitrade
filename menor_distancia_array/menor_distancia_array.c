#include <stdio.h>
#include <stdlib.h>

int get_the_difference(int minuend, int subtrahend)
{
    int difference;

    difference = minuend - subtrahend;
    if (difference < 0)
        difference *= -1;
    return (difference);
}

int get_minor_distance(int arr1[], int size_arr1, int arr2[], int size_arr2)
{
    int i;
    int j;
    int result;
    int temp;

    i = 0;
    result = 0;
    temp = 0;
    while (i < size_arr1)
    {
        j = 0;
        while (j < size_arr2)
        {
            temp = get_the_difference(arr1[i], arr2[j]);
            if (temp < result || i == 0)
                result = temp;
            if (result == 0)
                return (result);
            j++;
        }
        i++;
    }
    return (result);
}

int main(void)
{
    int arr1[10] = {23, 55, 456, 5445, 52, -213, 4534, 34, 34634, 534};
    int arr2[10] = {411, -342, 50, 546, 346, 442, 62, -754, 567, -2};
    int size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
    int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);
    int result;

    if (size_arr1 >= 10 || size_arr2 >= 10)
    {
        result = get_minor_distance(arr1, size_arr1, arr2, size_arr2);

        if (result == 0)
            printf("Os dois arrays possuem elementos de mesmo valor\n");
        else
            printf("A menor distance entre os dois arrays de inteiros é: %d\n", result);
    }
    else
    {
        fprintf(stderr, "Error: Quantidade de elementos insuficiente\n");
        exit(1);
    }
    return (0);
}
