/*
https://app.codesignal.com/interview-practice/task/pMvymcahZ8dY4g75q

Given an array a that contains only numbers in the range from 1 to a.length, 
find the first duplicate number for which the second occurrence has the minimal index. 
In other words, if there are more than 1 duplicated numbers, 
return the number for which the second occurrence has a smaller index than the second occurrence of the other number does. 
If there are no such elements, return -1.

*/



// Arrays are already defined with this interface:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 typedef struct arr_integer {
   int size;
   int *arr;
 } arr_integer;

 arr_integer alloc_arr_integer(int len) {
   arr_integer a = {len, len > 0 ? malloc(sizeof(int) * len) : NULL};
   return a;
 }

 int firstDuplicate(arr_integer a);

int main()
{
    arr_integer arr = alloc_arr_integer(6);
    arr.arr[0] = 2;
    arr.arr[1] = 1;
    arr.arr[2] = 3;
    arr.arr[3] = 5;
    arr.arr[4] = 3;
    arr.arr[5] = 2;

    printf("%d", firstDuplicate(arr));
    return 0;
}

//MyCode, 264/300 score
/*
int firstDuplicate(arr_integer a) 
{
    int minIdx = a.size + 1;

    for (int i = 0; i < a.size; i++)
        for (int j = i + 1; j < a.size + 1; j++)
            if (a.arr[i] == a.arr[j] && minIdx > j)
                    minIdx = j;

    return minIdx > a.size ? -1 : a.arr[minIdx];
}
*/


int firstDuplicate(arr_integer a)
{
    int minIdx = a.size + 1;

    for (int i = 0; i < a.size; i++)
        for (int j = i + 1; j < a.size + 1; j++)
            if (a.arr[i] == a.arr[j] && minIdx > j)
                    minIdx = j;

    return minIdx > a.size ? -1 : a.arr[minIdx];
}
