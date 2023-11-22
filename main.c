#include <stddef.h>
#include <stdio.h>
#include <string.h>

void swap_nums(int *a, int *b);
void print_int_array(int *arr, size_t size);

void bubblesort(int *arr, size_t size);
void insertionsort(int *arr, size_t size);
void selectionsort(int *arr, size_t size);

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

void mergesort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("No algo specified. Try bubblesort.");
        return 1;
    }

    int my_arr[] = { 35, 29, 8, 90, 15, 33 };
    size_t arr_len = sizeof(my_arr) / sizeof(my_arr[0]);

    // Initial array
    print_int_array(my_arr, arr_len);

    if (strcmp(argv[1], "bubblesort") == 0)
    {
        bubblesort(my_arr, arr_len);
    }
    else if (strcmp(argv[1], "selectionsort") == 0)
    {
        selectionsort(my_arr, arr_len);
    }
    else if (strcmp(argv[1], "insertionsort") == 0)
    {
        insertionsort(my_arr, arr_len);
    }
    else if (strcmp(argv[1], "quicksort") == 0)
    {
        quicksort(my_arr, 0, (int)arr_len);
    }
    else if (strcmp(argv[1], "mergesort") == 0)
    {
        mergesort(my_arr, 0, (int)arr_len);
    }
    else
    {
        printf("No matching sorting algo\n");
        return -1;
    }

    // sorted array
    print_int_array(my_arr, arr_len);

    return 0;
}

void bubblesort(int *arr, size_t size)
{
    int i, j;
    short swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (j = 0; j < size - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap_nums(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
    }
}

void selectionsort(int *arr, size_t size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        int max = 0;
        int j;

        for (j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }

        int last = size - 1 - i;
        if (max != last)
        {
            swap_nums(&arr[max], &arr[last]);
        }
    }
}

void insertionsort(int *arr, size_t size)
{
    int i;

    for (i = 1; i < size; i++)
    {
        int curr = arr[i];
        int j = i;

        while (j >= 1 && arr[j - 1] > curr)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = curr;
    }
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot);
        quicksort(arr, pivot + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right)
    {
        while (arr[left] <= pivot && left < high)
        {
            left++;
        }

        while (arr[right] > pivot && right > low)
        {
            right--;
        }

        if (left < right)
        {
            swap_nums(&arr[left], &arr[right]);
        }
    }

    arr[low] = arr[right];
    arr[right] = pivot;
    return right;
}

void mergesort(int *arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int l_size = mid - left + 1;
    int r_size = right - mid;

    int l_arr[l_size];
    int r_arr[r_size];

    for (int i = 0; i < l_size; i++) {
        l_arr[i] = arr[left + i];
    }

    for (int i = 0; i < r_size; i++) {
        r_arr[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < l_size && j < r_size)
    {
        if (l_arr[i] <= r_arr[j])
        {
            arr[k] = l_arr[i];
            i++;
        }
        else
        {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }

    while (i < l_size)
    {
        arr[k] = l_arr[i];
        i++;
        k++;
    }

    while (j < r_size)
    {
        arr[k] = r_arr[j];
        j++;
        k++;
    }
}

void swap_nums(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_int_array(int *arr, size_t size) {
    int i;
    printf("[ ");
    for (i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }
    printf(" ]\n");
}
