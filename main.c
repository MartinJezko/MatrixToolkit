#include <stdio.h>
#include <stdlib.h>

// Welcome to a very glamorous project of a student that
// till this day fucks up every CS exam.
// This is basically a visual representation that the human
// brain is not only used only in 11% of it's total capacity,
// but can go even lower.
//
// Enjoy <3
//
// https://github.com/MartinJezko


int optionMenu() {
    
    int opt;

    printf("\nSelect option: (0 for exit)\n");
    printf("1) Solve matrix\n");
    printf("2) Operations with 2 matrixes\n");
    scanf("%d", &opt);
    if (opt == 1) {
        printf("\n");
        printf("1) Find determinant\n");    // 11
        printf("2) Solve {x, y, z}\n");     // 12
        printf("3) Find transponed matrix\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                return 11;
                break;
            case 2:
                return 12;
                break;
            case 3:
                return 13;
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
// Allocates desired memory space for the matrix
int **matrix(int rows, int cols) {
    
    int **m = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        m[i] = malloc(sizeof(int) * cols);
    }

    return m;
    
}

// Fills matrix with values
void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("[%d][%d] >>> ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Prints out the matrix in an actually readable way
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Destroys the matrix and frees the memory allocated to it
void matrixDtor(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// SOLVE MATRIX
int findDeterminant() {
    int dim;
    printf("Enter the dimension (m = n) of matrix:");
    scanf("%d", &dim);
    int **m = matrix(dim, dim);
    fillMatrix(m, dim, dim);
    printf("\n (Entered matrix) \n");
    printMatrix(m, dim, dim);

    int determinant;

    // Solve determinant for 2x2
    if (dim == 2) {     
        determinant = m[0][0]*m[1][1] - m[1][0]*m[0][1];
    }
    // Solve determinant for 3x3
    else if (dim == 3) {
        determinant = m[0][0]*m[1][1]*m[2][2] + m[1][0]*m[2][1]*m[0][2] + m[2][0]*m[0][1]*m[1][2];
        determinant -= m[2][0]*m[1][1]*m[0][2] + m[2][1]*m[1][2]*m[0][0] + m[2][2]*m[1][0]*m[0][1];
    }
    // Solve determinant for 4x4 and more...
    // (Laplaceo's developement)
    else {
        printf("I can't count with higher dimensions (yet)\n");
        return 1;
    }

    printf("\n=== D ===\n");
    printf("Determinant = %d\n", determinant);

    matrixDtor(m, dim);
    return 0;
}

// OPERATIONS WITH 2 MATRIXES
int sumMatrixes() {
    int rA, cA, rB, cB; // Initialize rows and collumns for 2 matrixes A and B
    printf("Select number of rows of matrix A: ");
    scanf("%d", &rA);
    printf("Select number of collumns of matrix A: ");
    scanf("%d", &cA);

    printf("Select number of rows of matrix B: ");
    scanf("%d", &rB);
    printf("Select number of collumns of matrix B: ");
    scanf("%d", &cB);

    if (rA != rB || cA != cB) { // Check whether they have the same dimension lengths
        printf("Can't sum these 2 matrixes (need to have same dimensions)\n");
        return 1;
    }

    // Inititializes and adds values to matrixes A and B
    int **matrixA = matrix(rA, cA);
    printf("Fill A:\n");
    fillMatrix(matrixA, rA, cA);
    int **matrixB = matrix(rB, cB);
    printf("Fill B:\n");
    fillMatrix(matrixB, rB, cB);

    printf("\n (A) \n");
    printMatrix(matrixA, rA, cA);
    printf("\n (B) \n");
    printMatrix(matrixB, rB, cB);

    // Creates third matrix "sum" and adds values (a + b)
    int **sum = matrix(rA, cA);
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Frees matrixes A and B
    matrixDtor(matrixA, rA);
    matrixDtor(matrixB, rB);
    
    // Prints out final SUM matrix
    printf("\n=== A + B = ===\n");
    printMatrix(sum, rA, cA);
    printf("\n");

    // Frees the SUM matrix as well, because honestly I don't know
    // How to do it outside the function and i dont give a fuck
    matrixDtor(sum, rA);

    return 0;

}

int substractMatrixes() {
    int rA, cA, rB, cB; // Initialize rows and collumns for 2 matrixes A and B
    printf("Select number of rows of matrix A: ");
    scanf("%d", &rA);
    printf("Select number of collumns of matrix A: ");
    scanf("%d", &cA);

    printf("Select number of rows of matrix B: ");
    scanf("%d", &rB);
    printf("Select number of collumns of matrix B: ");
    scanf("%d", &cB);

    if (rA != rB || cA != cB) { // Check whether they have the same dimension lengths
        printf("Can't sum these 2 matrixes (need to have same dimensions)\n");
        return 1;
    }

    // Inititializes and adds values to matrixes A and B
    int **matrixA = matrix(rA, cA);
    printf("Fill A:\n");
    fillMatrix(matrixA, rA, cA);
    int **matrixB = matrix(rB, cB);
    printf("Fill B:\n");
    fillMatrix(matrixB, rB, cB);

    printf("\n (A) \n");
    printMatrix(matrixA, rA, cA);
    printf("\n (B) \n");
    printMatrix(matrixB, rB, cB);

    // Creates third matrix "subs" and adds values (a - b)
    int **subs = matrix(rA, cA);
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            subs[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    // Frees matrixes A and B
    matrixDtor(matrixA, rA);
    matrixDtor(matrixB, rB);
    
    // Prints out final SUM matrix
    printf("\n=== A - B = ===\n");
    printMatrix(subs, rA, cA);
    printf("\n");

    // Frees the SUBSTRACTION matrix as well, because honestly I don't know
    // How to do it outside the function and i dont give a fuck
    matrixDtor(subs, rA);

    return 0;
}

int multiplyMatrixes() {

    int rA, cA, rB, cB; // Initialize rows and collumns for 2 matrixes A and B
    printf("Select number of rows of matrix A: ");
    scanf("%d", &rA);
    printf("Select number of collumns of matrix A: ");
    scanf("%d", &cA);

    printf("Select number of rows of matrix B: ");
    scanf("%d", &rB);
    printf("Select number of collumns of matrix B: ");
    scanf("%d", &cB);

    if (cA != rB) { // cA x rB --> m_A x n_B
        printf("Num. of collumns in A needs to equal the number of rows in B\n");
        return 1;
    }

    int **matrixA = matrix(rA, cA);
    printf("Fill A:\n");
    fillMatrix(matrixA, rA, cA);
    int **matrixB = matrix(rB, cB);
    printf("Fill B\n");
    fillMatrix(matrixB, rB, cB);
    
    printf("\n (A) \n");
    printMatrix(matrixA, rA, cA);
    printf("\n (B) \n");
    printMatrix(matrixB, rB, cB);

    //  cB x rA --> m_M x n_M
    int **multi = matrix(rA, cB);   // Basically a result matrix

    // multiplication magic :3
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            for (int k = 0; k < cA; k++) {
                multi[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    
    printf("\n=== A * B = ===\n");
    printMatrix(multi, rA, cB);

    matrixDtor(matrixA, rA);
    matrixDtor(matrixB, rB);
    matrixDtor(multi, rA);

    return 0;
}

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
                printf("\nFIND DETERMINANT OF A MATRIX\n\n");
                findDeterminant();
                break;
            case 12:
                printf("\nSOLVE SYSTEM OF EQUATIONS\n\n");
                break;
            case 13:
                printf("\nFIND TRANSPONED MATRIX\n\n");
                break;
            case 21:
                printf("\nSUM OF MATRIXES (A+B)\n\n");
                sumMatrixes();
                break;
            case 22:
                printf("\nSUBSTRACTION OF MATRIXES (A-B)\n\n");
                substractMatrixes();
                break;
            case 23:
                printf("\nMULTIPLICATION OF MATRIXES (A x B)\n\n");
                    multiplyMatrixes();
                break;

        }
    }

    return 0;
}