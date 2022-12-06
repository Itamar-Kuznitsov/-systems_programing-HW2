#include <stdio.h>
#include "my_mat.h"


// function that get from the user the matrix input - 10X10 matrix.
int get_input(int matrix[10][10]){
    int num;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            scanf(" %d", &num);
            matrix[i][j] = num;
        }
    }
    return 0;
}

// assistance function that help use to find the path data of two points-
//  by Floyd-Warshall algorithm which find the shortest path between two ponts.
//      as was mention in the instraction page for this algorithm I based on information from the internet.  
int floyd_warshall(int matrix[10][10]){
    int temp;
    for (int k = 0; k < 10; k++){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                temp = matrix[i][k]+matrix[k][j];
				// edge cases for our undirected graph:
                if (matrix[i][k] == 0 || matrix[k][j] == 0) {
					temp = 0;
				}
				if (i == k || j == k || i == j || temp == 0) {
					continue;
				}
                // updating the shortest path:
				if (matrix[i][j] == 0) {
                    matrix[i][j] = temp;
                }
				if (matrix[i][j] > temp) {
					matrix[i][j] = temp;
				}
            }
        }
    }
    return 0;
}

//  function that print True if there is a path frome i to j, otherwise False. 
int path_is_availible(int matrix[10][10]){
    // getting two points 
    int t,s;
    
    scanf(" %d%d", &t,&s);
    if (matrix[t][s] > 0){
        printf("True\n");
    }
    else
        printf("False\n");
    return 0;
}

// function that print the shortest path from i to j.
int shortest_path(int matrix[10][10]){
    // getting two points 
    int t,s;
    
    scanf(" %d%d", &t,&s);
    if (matrix[t][s] > 0){
        printf("%d\n", matrix[t][s]); 
    }
    else
        printf("-1\n");

    return 0;
}

