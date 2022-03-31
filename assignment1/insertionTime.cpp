#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

void insertion_sort(int arr[], int n) {

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

//got this code from class lecture
int main() {

    srand(time(NULL));
    int B[100000], B2[10000];
    int n = 1000;

    for (int i = 0; i < n; i++) {
        B[i] = rand() % 10000;
        B2[i] = B[i];
    }

    int m = 11;
    for (int n = 500; n <= 7000; n = n + 500) {
        double total = 0, total3 = 0;
        for (int i = 1; i <= m; i++) {
            for (int i = 0; i < n; i++) {
                B[i] = rand() % 50;
                B2[i] = B[i];
            }
            

            clock_t tStart = clock();
            insertion_sort(B, n);
            clock_t tEnd = clock();
            double runtime = (double)(tEnd - tStart) / (CLOCKS_PER_SEC / 1000);
            total = total + runtime;

        }
        double average = total / m;

        cout << n << "  " << average << endl;
    }

    return 0;
}

