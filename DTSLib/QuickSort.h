/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

namespace DTS {

class QuickSort {
public:
    template<typename Container>
    static void quickSort(Container& container) {
        quickSort(0, container.size() - 1, container);
    }

private:
    template<typename Container>
    static void quickSort(int low, int high, Container& container) {
        if (low < high) {
            auto pivot = partition(low, high, container); // Must be auto to allow for strings, ints, floats, etc.

            quickSort(low, pivot - 1, container);
            quickSort(pivot + 1, high, container);
        }
    }

    template<typename Container>
    static int partition(int low, int high, Container& container) {
        auto pivot = container[high]; // Must be auto to allow for strings, ints, floats, etc.
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (container[j] < pivot) {
                i++;
                // swap container[j] and container[i]
                auto temp = container[j];
                container[j] = container[i];
                container[i] = temp;
            }
        }
        auto temp = container[i + 1];
        container[i + 1] = container[high];
        container[high] = temp;

        return i + 1;
    }
};

}