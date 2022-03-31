#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

using namespace std;

//returns max of two paramaters
int get_max(int a, int b) {
	
	return (a > b)? a : b;

}

//finds the max value that can be put into knapsack of capacity W recursively
int knapSack_recursive(int W, int wt[], int val[], int n) {

	//base case
	if (n == 0 || W == 0) {
		return 0;
	}

	//if the weight is more than the knapsack's capacity then if is not an optimal choice
	if (wt[n - 1] > W) {
		return knapSack_recursive(W, wt, val, n - 1);
	}

	else
	//finds max of nth item and not 
		return get_max(
			val[n - 1] + knapSack_recursive(W - wt[n - 1], wt, val, n - 1), knapSack_recursive(W, wt, val, n - 1));

}


//finds the max value that can be put into knapsack of capacity W with dynamic programming
int knapSack_DP( int W,int wt[], int val[], int n) {

	int i = 0;
	int w = 0;
	
	int K[n + 1][W + 1];

	//building table K[][]
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0) {
				K[i][w] = 0;
			}
			else if (wt[i - 1] <= w) {
				K[i][w] = get_max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			}
			else {
				K[i][w] = K[i - 1][w];
			}

		}
	}

	return K[n][W];
}

//print outs of n, W, rec time, dp time, max rec and max DP
void print_time(int n, int w, double recursivetime, double dptime, int recursive, int dp) {

	cout << "N = " << n; 
	cout << "  " ;
	cout << "W = " << w;
	cout << "  ";
	cout << "Rec time = " << recursivetime;
	cout << "  ";
	cout << "DP time = " << dptime;
	cout << "  ";
	cout << "max Rec = " << recursive;
	cout << "  ";
	cout << "max DP = " << dp;

	cout<< endl;

}


int main() {

	int n = 5;
	clock_t s, e; 
	int W = 10000;	


	for (int i = 1; i <= 20; i ++) {
		int* val = (int*)malloc(n* sizeof(int));
		int* wt = (int*)malloc(n* sizeof(int));

		for (int y = 0; y < n; y++) {
			val[y] = rand() % 1000; 
			wt[y] = rand() % 1000;
		}

		s = clock();
		int recurs = knapSack_recursive(W, wt, val, n);
		e = clock();
		double t = ((double)(e - s)) / (CLOCKS_PER_SEC/1000);

		s = clock();
		int dp = knapSack_DP(W, wt, val, n);
		e = clock();
		double t_dp = ((double)(e - s)) / (CLOCKS_PER_SEC/1000);

		print_time(n, W, t, t_dp, recurs, dp);

		n += 5;

	}


	return 0; 
}


