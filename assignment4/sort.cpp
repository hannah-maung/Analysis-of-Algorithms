#include <iostream>
#include <fstream>
using namespace std;


/***************************
 * URL: https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
 * Date retrieved: 2/7/2021
 * Title: Activity Selection
 * Type: source code
 * Author name: n/a
 * Explanation: I referenced this website. Did not copy it entirely because it is not the problem that this 
 * assignment is asking us to do. But it goes over how to implement when activities are not sorted.
 * Code version: n/a
**************************/

//Job has a start, finish, then an activity 
struct Activity {

	int start, finish, num;
};




//finds the max set of activities 
void print_maxact(Activity arr[], int n) {


	cout << "Activities: ";

	int count = 1 ;
	int i = 0;
	cout << arr[i].start << " ";
	for (int j = 1; j < n; j++) {
		//if activity has greater or equal time to the finish time of the act before that one, then print		
		if(arr[j].start >= arr[i].finish) {
			cout << arr[j].num << " ";
			i = j;
			count++;
			

		}
	}
	cout << endl;
	
	cout << "Number of activities selected = " << count << endl;
}



int main() {

	Activity arr[50];
	int n;
	//reads file act.txt, prints out error message if it cannot be found
	ifstream act("act.txt");
	if (act.fail()) {
		cout << "The file did NOT open successfully" << endl;
	}

	int count = 1;

	int num[50];
	int start[50];
	int finish[50];

	while(act >> n){
		for(int j = 0; j < n; j++) {
			act >> arr[j].num;
			act >> arr[j].start;
			act >> arr[j].finish;
		}	

		//keeping track of what number set it is
		cout << "Set " << count << endl;
		count++;
		print_maxact(arr,n);
		cout << endl;	
	}

}

