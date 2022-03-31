#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <climits>

/**********************************
 * Date: 2/22/21
 * Source URL: https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
 * Title of program: Prim's MST Greedy Algo-5
 * Author: code is contributed by rathbhupendra/ GeeksforGeeks 
 * Explanation: The code below is the prim's mst algorithm which helps me find the weight of the MST for each test case in this problem
*******************************/


using namespace std;

//Finding the vertex with min key value 
int minKey(int key[], bool mstSet[], int vertices)
{


    int min = INT_MAX, min_index;
    
    //set of vertices are not included in MST yet
    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)

            min = key[v], min_index = v;

    return min_index;
}

//prints out the MST weight of each test case
void printMST(int parent[], int matrix[50][50], int vertices)
{
    int total = 0;
 
    //adding up the mst weights and printing it out after each test case     
    for (int i = 1; i < vertices; i++) {
        
        total = total + matrix[i][parent[i]];

    }
    //printing out mst weight
    cout << " MST weight " << total << endl;
}


//constructs MST using adjacency matrix
void primMST(int matrix[50][50], int vertices)
{

    //initializing arrays
    int parent[50];
    int key[50];
    bool mstSet[50];

    //initialize all keys as INFINITE
    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;
        
    key[0] = 0;
    parent[0] = -1; 
    
    for (int count = 0; count < vertices - 1; count++)
    {
	//finds the min key vertex by calling minKey
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;    
	//updating parent and key value
        for (int v = 0; v < vertices; v++)     
            if (matrix[u][v] && mstSet[v] == false && matrix[u][v] < key[v])
                parent[v] = u, key[v] = matrix[u][v];
    }
    //calling printMST
    printMST(parent, matrix, vertices);
}


int main() {

    //if it cannot find graph.txt then ir prints out an error statement   
    ifstream in("graph.txt");
    if (in.fail()) {
        cout << "The file did NOT open successfully" << endl;
    }
    //reads in cases numbers
    int cases;
    in >> cases;

    //making vertices variable and creating array for the coordinates of the points (vertices)
    int vertices = 0;
    int x[500];
    int y[500];
  

    int distance;
    int count = 1;
    int matrix[50][50];
 
    //https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
    //reading in data to array to store to x and y coordinate of the points in that test case   
    for (int i = 1; i <= cases; i++) {
        in >> vertices;
        for (int j = 0; j < vertices; j++) {
            in >> x[j];
            in >> y[j];
            
        }

        cout << "Test case: " << count;
        count++;

        //distance function calcuations
        double result = 0;
        float total = 0;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {

                result = sqrt(pow(x[i] - x[j], 2) +
                    pow(y[i] - y[j], 2));

                total = round(result);

                matrix[i][j] = total;

            }
        }
        
        primMST(matrix, vertices);
        cout << endl;
    }

}
