#include <stdio.h>
#include <stdlib.h>

using namespace std;


//Reference: similar function to knapSack DP in my knapsack.cpp
//Program name: knapSack_DP
//Purpose: This function finds the optimal prices of items for each family and the items that each family should select. Is a dynamic programming algorithm 
//Input: int W (how much a family member can carry), int wt (items array), int n, int val[] (each item), int * I (item of each member) 
//Output: finds optimal price of items 
int knapSack_DP(int W, int wt[200][2],int n , int val[200],int * I){

	//represents the max price of items that can be carried by each family member 
	int arr[200][200]; 
	
	//sets counter and fills array
	int arraysize = 200; 
	for(int i = 0; i < arraysize; i++){
		arr[0][i] = 0;
		arr[i][0] = 0;
	}

	//finding total max price of items that can be carried by each member in the family
	int money;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j<= W ; j++){
			if(j - wt[i][1] >= 0 ){
				int money = arr[i-1][j-wt[i][1]] + wt[i][0];
				if (money < arr[i-1][j]) {
					arr[i][j] = arr[i-1][j];
				}
				else{
					arr[i][j] = money;
				}
			}
			else {
				arr[i][j] = arr[i-1][j];
			}
		}

	}	
	
	//make variable to equal how much a family member can cary
	int max_weight = W;
	int x = 0;

	//finding the items that compares to the best price 
	for(int i = n; i > 0; i--){
		if(max_weight - wt[i][1] >= 0 ){
			if( arr[i-1][max_weight-wt[i][1]] + wt[i][0] > arr[i-1][max_weight] ){		
				val[x++] = i;
				max_weight = max_weight - wt[i][1];
			}
		}
	}

	//returns total max price of items for each member
	*I = x;
	return(arr[n][W]);

}


int main() {


	//initializing arrays
	int wt[200][2];
	int val[200][200];
	int I[200];	
	int members[200];

	//creates pointer to FILE
	//reads shopping.txt, prints out error message if file cannot be found
	FILE *shop = fopen("shopping.txt","r");
	if (shop == NULL) {
		printf("Error, cannot find file");		
		return 0;
	}
	
	int TC;
	//taking input from file
	fscanf(shop, "%d" , &TC);

	//creates pointer to FILE
	//file access as write mode to results.txt file, prints out error message if file cannot be found
	FILE *results = fopen("results.txt","w");
	if (results == NULL) {
		printf("Error, cannot find file");
		return 0;
	}

	
	int k = 1;	
	int n = 0;
	int i = 0;
	int t = 1;
	int f = 0;
	//loop continues while cases are greater than 0, decreases TC everytime it loops
	int index = 0;
	for (index = 0; TC > 0; TC--){
		
		//taking items information from file 
		fscanf(shop, "%d" , &n);	
		for(i = 1; i <= n; i++){
			fscanf(shop, "%d%d", &wt[i][0], &wt[i][1]);
		}

		//taking members info from file
		fscanf(shop, "%d", &f);
		for(i = 0; i < f; i++){
			fscanf(shop, "%d", & members[i]);
		}

		//calculates total price by calling knapSack_DP function
		int totalCost = 0;
		fprintf(results,"\nTest Case %d\n", t);
		for(i=0 ; i < f; i++){
			totalCost += knapSack_DP(members[i], wt ,n ,val[i], &I[i]);
		}
	
		//printing out total price and members items 
		fprintf(results, "Total Price %d\n", totalCost);
		fprintf(results,"Member Items:");
		for(i = 0; i < f; i++){
			fprintf(results, "\n%d:  ", i + 1);
			for(int j = I[i] - 1; j >= 0; j--){
				fprintf(results,"%d ",val[i][j]);
			}
			
		}
		//new line, increase t
		fprintf(results, "\n");
		t++;
	}
}

