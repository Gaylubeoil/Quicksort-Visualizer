#pragma once
#include "PCH.hpp"
#include "window.hpp"
#include <vector>
class Window;

class Quicksort
{
public:
    Quicksort() = default;
    void sort(std::vector<int> &_arr, Window *instance);
    void render(sf::RenderTarget &target);

private:
    void quicksort(std::vector<int> &stack, int begin, int end, Window *instance);
    int partition(std::vector<int> &stack, int left, int right, int pivot, Window *instance);
    void swap(int *a, int *b);
};