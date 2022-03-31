#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;



//This is the same merge function that I used for Homework1
//This function combines the sorted lists into one
//Inputs: int arr[], int p, int q, int r
//Outputs: list
void merge3(int arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[50];
    int M[50];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] < M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

//This function sorts arrays of integers, splits list into thirds
//and valls Merge3 to merge the thirds back into a sorted list
//Inputs: int arr[], int low, int high
//Output: sorted list
void mergeSort3(int arr[], int low, int high) {

    int i = 1;
    if (high == (low + i)) {
        if (arr[low] > arr[high]) {
            int temporary = arr[low];
            arr[low] = arr[high];
            arr[high] = temporary;
        }
    }

    else if (low < high) {
        int step = (high - low + i) / 3;

        mergeSort3(arr, low, low + step - i);
        mergeSort3(arr, low + step, high - step);
        mergeSort3(arr, high - step + i, high);
	
        merge3(arr, low, low + step - i, high - step);
        merge3(arr, low, high - step, high);

    }
}

//Followed the same format I used in my int main() for Homework 1
//If the file is not detected, it prints out an error message letting the user know
int main() {

    ifstream in("data.txt");
    if (in.fail()) {
        cout << "The file did NOT open successfully" << endl;
    }


    int x;
    while (in >> x) {
        int* arr = new int[x];
        int j = 0;

        while (j < x) {
            in >> arr[j];
            j++;
        }
      
        mergeSort3(arr, 0, x - 1);
 	
	//prints out sorted list
        for (int i = 0; i < x; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
