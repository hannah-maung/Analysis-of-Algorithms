#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

void insertion_sort(int arr[], int n){

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


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

            insertion_sort(arr, x);
            for (int i = 0; i < x; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }     
    
}

