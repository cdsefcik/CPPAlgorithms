#include<iostream>
using namespace std;

/*
This was from the Data Structure & algorithm using c++ Zero To Mastery 2024 course.
V2 was from the C++ data structures and algorithms course.

The parameters are an array and the size of the array.

The BIG O is n^2.

ToDo:
Combined the two. Optimize of possible.

*/

#include <iostream>

using namespace std;

void bubbleSort(int a[], int n) {

	for (int count = 1; count <= n - 1; count++) {
		for (int j = 0; j <= n - 2; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void bubbleSortV2(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}



int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    bubbleSortV2(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}
