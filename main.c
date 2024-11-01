#include <stdio.h>
#include <stdlib.h>


int optionMenu() {
    
    int opt;

    printf("Select option: (0 for exit)\n");
    printf("1) Solve matrix\n");
    printf("2) Oprerations with 2 matrixes\n");
    scanf("%d", &opt);
    if (opt == 1) {
        printf("\n");
        printf("1) Find determinant\n");    // 11
        printf("2) Solve {x, y, z}\n");     // 12
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                return 11;
                break;
            case 2:
                return 12;
                break;
            case 0:
                return -2;
                break;
            default:
                return -1;
                break;
        }
    }
    else if (opt == 2) {
        printf("\n");
        printf("1) A + B\n");   // 21
        printf("2) A - B\n");   // 22
        printf("3) A * B\n");   // 23
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                return 21;
                break;
            case 2:
                return 22;
                break;
            case 3:
                return 23;
                break;
            case 0:
                return -2;
                break;
            default:
                return -1;
                break;

        }
    }
    else if (opt == 0) {
        return -2;
    }
    else {
        return -1;
    }
    
}

// MATRIX INITIALIZATION / DESTRUCTION   
int **matrix(int rows, int cols) {
    
    int **m = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        m[i] = malloc(sizeof(int) * cols);
    }

    return m;
    
}

void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("[%d][%d] >>> ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixDtor(int **matrix) {
    free(matrix);
}

// OPERATIONS WITH 2 MATRIXES


int main() {

    int option;

    while (1) {

        option = optionMenu();
        
        // Controls right menu option
        switch (option) {
            case -1:
                fprintf(stderr, "!!! Please choose a right option\n");  // Wrong option
                break;
            case -2:
                printf("\nLeaving...\n");   // Exit program
                return 0;
            case 11:    // (and below) - Self explanatory
                printf("\nFIND DETERMINANT OF A MATRIX\n");
                break;
            case 12:
                printf("\nSOLVE SYSTEM OF EQUATIONS\n");
                break;
            case 21:
                printf("\nSUM OF MATRIXES (A+B)\n");
                break;
            case 22:
                printf("\nSUBSTRACTION OF MATRIXES (A-B)\n");
                break;
            case 23:
                printf("\nMULTIPLICATION OF MATRIXES (A x B)\n");
                break;

        }




    }

    return 0;
}