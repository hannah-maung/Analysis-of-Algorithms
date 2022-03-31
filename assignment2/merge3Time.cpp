#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;


//This is the same merge function that I used for Homework1,
//This function combines the sorted lists into one 
//Inputs: int arr[], int p, int q, int r
//Output: list
void merge3(int arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[50000];
    int M[50000];


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

//This function sorts array of integers, splits list into 
//thirds and calls Merge3 to merge the thirds back into a sorted list.
//Inputs: int arr[], int low, int high
//Outputs: sorted list 
void mergeSort3(int arr[], int low, int high) {

    //finding the high and low of the list, splitting the array according 
    //to those numbers
    int i = 1;
    if (high == (low + i)) {
        if (arr[low] > arr[high]) {
            int temporary = arr[low];
            arr[low] = arr[high];
            arr[high] = temporary;
        }
    }

 	// splits list into thirds   
    else if (low < high) {
        int step = (high - low + i) / 3;

        mergeSort3(arr, low, low + step - i);
        mergeSort3(arr, low + step, high - step);
        mergeSort3(arr, high - step + i, high);

 	//Merges the thirds back into a sorted array 
        merge3(arr, low, low + step - i, high - step);
        merge3(arr, low, high - step, high);

    }
}

//Looked at lecture for this code, same format as Homework 1 that I used 
//Generates arrays containing random integer values from 0-10000 using rand()%
//Uses system clock to record running times of ten different values: My range was 
//5000-10000 going up by 5000. 
int main() {

    srand(time(NULL));
    int B[100000], B2[10000];
    int n = 1000;

    for (int i = 0; i < n; i++) {
        B[i] = rand() % 10000;
        B2[i] = B[i];
    }

    int m = 11;
    for (int n = 5000; n <= 100000; n = n + 5000) {
        double total = 0, total3 = 0;
        for (int i = 1; i <= m; i++) {
            for (int i = 0; i < n; i++) {
                B[i] = rand() % 50;
                B2[i] = B[i];
            }
            clock_t tStart3 = clock();
            mergeSort3(B, 0, n - 1);
            clock_t tEnd3 = clock();
            double runtime3 = (double)(tEnd3 - tStart3) / (CLOCKS_PER_SEC / 1000);
            total3 = total3 + runtime3;

        }
        double avg = total3/ m;

        cout << n << "  " << avg << endl;
    }

    return 0;
}
