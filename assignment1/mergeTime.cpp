#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

void merge(int arr[], int p, int q, int r) {

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

void merge_sort(int arr[], int l, int r) {
    if (l < r) {

        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


//Got this code from our class lecture
int main() {

    srand(time(NULL));
    int B[100000], B2[10000];
    int n = 1000;

    for (int i = 0; i < n; i++) {
        B[i] = rand() % 10000;
        B2[i] = B[i];
    }

    int m = 11;
    for (int n = 5000 ; n <= 90000 ; n = n + 5000) {
        double total = 0, total3 = 0;
        for (int i = 1; i <= m; i++) {
            for (int i = 0; i < n; i++) {
                B[i] = rand() % 50;
                B2[i] = B[i];
            }

            clock_t tStart = clock();
            merge_sort(B, 0, n - 1);
            clock_t tEnd = clock();
            double runtime = (double)(tEnd - tStart) / (CLOCKS_PER_SEC / 1000);
            total = total + runtime;

        }
        double average = total / m;

        cout << n << "  " << average << endl;
    }

    return 0;
}

