#include<iostream>
using namespace std;


/*
* This is the binary search algorithm. Code from Data Structures and Algorithms C++: Zero to Mastery in 2024.
* The list needs to be sorted.
*/

int BinarySearch(int a[], int n, int key) {

    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2; //This avoids integer overflow if the start and the end is large.

        if (a[mid] == key) {
            return mid;
        }
        else if (a[mid] > key) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return -1;

}
