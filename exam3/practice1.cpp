/*
9. For this question, we'll do some OOP and inheritance. You are tasked with writing an abstract class
    Sorting  with the pure virtual functions  sort(std::vector<int>)  and
    worst_case_runtime() . This class is then subclassed into three classes which you are responsible
   for:  InsertionSort , QuickSort , and MergeSort . Within these classes, you are to implement
   a function  sort  which sorts a vector of integers according to the type of sorting algorithm you have.
   (You are free to implement this however you wish.)  worst_case_runtime()  would then return a
    std::string containing the worst case runtime of the algorithm.
*/

#include <iostream>
#include <vector>
#include <string>

class Sorting {
public:
    virtual std::string worst_case_runtime() = 0;
    virtual void sort(std::vector<int>& vec) = 0;
};

class InsertionSort: public Sorting {
public:
    std::string worst_case_runtime() override {
        return "O(n^2)";
    }
    
    void sort(std::vector<int>& vec) override {
        // Insertion Sort: builds the sorted array one element at a time
        int key, j;
        int n = vec.size();

        for (int i = 1; i < n; i++) {
            key = vec[i];      // The element to be inserted into the sorted part
            j = i - 1;

            // Move elements of vec[0..i-1] that are greater than key
            // to one position ahead of their current position
            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j--;
            }

            // Place key after the last element smaller than it
            vec[j + 1] = key;
        }
    };
};

class QuickSort: public Sorting {
public:
    std::string worst_case_runtime() override {
        return "O(n^2)";
    }

    void sort(std::vector<int>& vec) override {
        // Quick Sort: recursive, divide-and-conquer sorting
        quickSort(vec, 0, vec.size()-1);
    }

    void quickSort(std::vector<int>& vec, int left, int right) {
        if (left < right) {
            // Partition the array and get the pivot index
            int pivot = partition(vec, left, right);
            // Recursively sort elements before and after partition
            quickSort(vec, left, pivot - 1);
            quickSort(vec, pivot + 1, right);
        }
    }

    int partition(std::vector<int>& vec, int left, int right) {
        // Partition function: places pivot element at correct position
        int pivot = vec[left];         // Choose the leftmost element as pivot
        int from_left = left + 1;
        int from_right = right - 1;
        int tmp;

        // Move elements smaller than pivot to the left, larger to the right
        while (from_left != from_right) {
            if (vec[from_left] <= pivot) {
                from_left++;
            } else {
                while ((from_left != from_right) && (pivot <= vec[from_right])) {
                    from_right--;
                }
                std::swap(vec[from_right], vec[from_left]);
            }
        }

        // Place the pivot in its correct position
        if (vec[from_left] > pivot) {
            from_left--;
        }
        vec[left] = vec[from_left];
        vec[from_left] = pivot;

        return from_left; // Return the pivot index
    }
};

class MergeSort: public Sorting {
public:
    std::string worst_case_runtime() override {
        return "O(n log n)";
    }

    void sort(std::vector<int>& vec) override {
        // Merge Sort: recursive, divide-and-conquer sorting
        mergeSortHelper(vec, 0, vec.size()-1);
    }

    void mergeSortHelper(std::vector<int>& vec, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            
            // Recursively sort first and second halves
            mergeSortHelper(vec, left, mid);
            mergeSortHelper(vec, mid + 1, right);

            // Merge the sorted halves
            merge(vec, left, mid, right);
        }
    }

    void merge(std::vector<int>& vec, int left, int mid, int right) {
        // Merge two sorted subarrays vec[left..mid] and vec[mid+1..right]
        int i, j, k;
        std::vector<int> L(mid - left + 1, 0); // Left subarray
        std::vector<int> R(right - mid, 0);    // Right subarray

        // Copy data to temp arrays L[] and R[]
        for (i = 0; i < mid - left + 1; i++) {
            L[i] = vec[left + i];
        }

        for (j = 0; j < right - mid; j++) {
            R[j] = vec[mid + left + j];
        }

        i = 0;
        j = 0;
        k = left;

        // Merge the temp arrays back into vec[left..right]
        while (i < mid - left + 1 && j < right - mid) {
            if (L[i] <= R[j]) {
                vec[k] = L[i];
                i++;
            } else {
                vec[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy any remaining elements of L[]
        while (i < mid - left + 1) {
            vec[k] = L[i];
            i++;
            k++;
        }

        // Copy any remaining elements of R[]
        while (j < right - mid) {
            vec[k] = R[j];
            j++;
            k++;
        }
    }
};

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    Sorting* sorter;

    // Choose sorting algorithm
    sorter = new InsertionSort();
    // sorter = new QuickSort();
    // sorter = new MergeSort();

    std::cout << "Worst case runtime: " << sorter->worst_case_runtime() << std::endl;

    sorter->sort(vec);

    std::cout << "Sorted array: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    delete sorter;
    return 0;
}