#include <stdio.h>
#include "my_mat.h"

#define True 1

// as requested this function run all my_mat.c functions based on the user choice:
int main(){
    int matrix[10][10] = {0};

    while(True){
        // getting the input:
        char func= '0';
        scanf(" %c", &func);

        //calling get_input function 
        if(func == 'A'){
            get_input(matrix);
            // also call function floyd
            floyd_warshall(matrix);
        }
        // calling path_is_availible function
        else if(func == 'B'){
            path_is_availible(matrix);
        }
        // calling shortest_path function 
        else if(func == 'C'){
            shortest_path(matrix);
        }
        // finishing the program + exit
        else if(func == 'D'){
            break;
        }
    }

    return 0;
}
