#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;

};

void Display(struct Array arr)
{
    int i;
    cout << "\nElements are \n" << endl;
    for (i = 0; i < arr.length; i++)
        cout << arr.A[i] << endl;

}
void Append(struct Array* arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;

}
void Insert(struct Array* arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
            arr->A[index] = x;
            arr->length++;
        
    }
}
int Delete(struct Array* arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
            
        }
        arr->length--;
        return x;
    }

}
void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
        return -1;
    }
}
int LinearSearchM1(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i;
        }
        return -1;
    }
}
int LinearSearchM2(struct Array* arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
        return -1;
    }
}
int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        
    }
    return -1;
}
int RBinarySearch(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
            return RBinarySearch(a, l, mid - 1, key);
        else
            return RBinarySearch(a, mid + 1, h, key);
            }
    return -1;
}
void InsertSort(struct Array* arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
int isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;

    }
    return 1;
}
void REarrange(struct Array* arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)i++;
        while (arr->A[i] = 0)j--;
        if (i < j)swap(&arr->A[i], &arr->A[j]);
    }
}
int main()
{
    struct Array arr = { {2,-3,25,10,-15,-7},10,7 };
       
    
    Display(arr);
    std::cout << "Hello World!\n";
}

