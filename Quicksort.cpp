#include "Quicksort.hpp"

void Quicksort::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Quicksort::partition(std::vector<int> &stack, int left, int right, int pivot, Window *instance)
{
    while (left <= right)
    {
        while (stack[left] < pivot)
        {
            left++;
        }
        while (stack[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            swap(&stack[left], &stack[right]);
            instance->update_rectangles();
            instance->render();
            left++;
            right--;
        }
    }
    return left;
}

void Quicksort::quicksort(std::vector<int> &stack, int begin, int end, Window *instance)
{
    // A pivot element is selected. For simplicity, the array's middle one.
    if (begin >= end)
    {
        return;
    }
    int pivot = stack[(begin + end) / 2];

    int index = partition(stack, begin, end, pivot, instance);
    quicksort(stack, begin, index - 1, instance);
    quicksort(stack, index, end, instance);
}

void Quicksort::sort(std::vector<int> &_arr, Window *instance)
{
    quicksort(_arr, 0, _arr.size() - 1, instance);
}

void Quicksort::render(sf::RenderTarget &target)
{
}