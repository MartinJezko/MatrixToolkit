#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Welcome to a very glamorous project of a student that
// till this day fucks up every CS exam.
// This is basically a visual representation that the human
// brain is not only used only in 11% of it's total capacity,
// but can go even lower.
//
// Enjoy <3
//
// https://github.com/MartinJezko
void clrscr()
{
    // system("@cls||clear");
}

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

// Copies a matrix
int **copyMatrix(int **matrix, int rows, int cols) {
    int **m_copy = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        m_copy[i] = malloc(sizeof(int) * cols);
    }


    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            m_copy[i][j] = matrix[i][j];
        }
    }
    return m_copy;
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
        printf("|\t");
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("|");
        printf("\n");
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
// Finds determinant while initializing the matrix is inside the function
int findDeterminant() {
    int dim;
    printf("Enter the dimension (m = n) of matrix:");
    scanf("%d", &dim);
    if (dim >= 5) {
        printf("Can't find determinant for bigger size 4 (yet)\n");
        return -999999;
    }

    int **m = matrix(dim, dim);
    fillMatrix(m, dim, dim);
    printf("\n (Entered matrix) \n");
    printMatrix(m, dim, dim);

    int determinant = 0;

    // Solve determinant for 2x2
    if (dim == 2) {     
        determinant = m[0][0]*m[1][1] - m[1][0]*m[0][1];
    }
    // Solve determinant for 3x3
    else if (dim == 3) {
        determinant = m[0][0]*m[1][1]*m[2][2] + m[1][0]*m[2][1]*m[0][2] + m[2][0]*m[0][1]*m[1][2];
        determinant -= m[2][0]*m[1][1]*m[0][2] + m[2][1]*m[1][2]*m[0][0] + m[2][2]*m[1][0]*m[0][1];
    }
    // Solve determinant for 4x4
    // (Laplaceo's developement)
    else if (dim == 4) {
        for (int c = 0; c < 4; c++) {
            if (c == 0) {
                determinant += pow(-1, (c+1)+1)*m[0][c] * 
                (m[1][1]*m[2][2]*m[3][3] + m[2][1]*m[3][2]*m[1][3] + m[3][1]*m[1][2]*m[2][3]
                - m[3][1]*m[2][2]*m[1][3] - m[2][1]*m[1][2]*m[3][3] - m[1][1]*m[3][2]*m[2][3]);
            }
            else if (c == 1) {
                determinant += pow(-1, (c+1)+1)*m[0][c] * 
                (m[1][0]*m[2][2]*m[3][3] + m[2][0]*m[3][2]*m[1][3] + m[3][0]*m[1][2]*m[2][3]
                - m[3][0]*m[2][2]*m[1][3] - m[2][0]*m[1][2]*m[3][3] - m[1][0]*m[3][2]*m[2][3]);
            }
            else if (c == 2) {
                determinant += pow(-1, (c+1)+1)*m[0][c] * 
                (m[1][0]*m[2][1]*m[3][3] + m[2][0]*m[3][1]*m[1][3] + m[3][0]*m[1][1]*m[2][3]
                - m[3][0]*m[2][1]*m[1][3] - m[2][0]*m[1][1]*m[3][3] - m[1][0]*m[3][1]*m[2][3]);
            }
            else if (c == 3) {
                determinant += pow(-1, (c+1)+1)*m[0][c] * 
                (m[1][0]*m[2][1]*m[3][2] + m[2][0]*m[3][1]*m[1][2] + m[3][0]*m[1][1]*m[2][2]
                - m[3][0]*m[2][1]*m[1][2] - m[2][0]*m[1][1]*m[3][2] - m[1][0]*m[3][1]*m[2][2]);
            }
        }
    }


    matrixDtor(m, dim);
    return determinant;
}

// Finds determinant with externally initialized matrix
int findDeterminant2(int **m, int dim) {
    int determinant = 0;

    // Solve determinant for 2x2
    if (dim == 2) {     
        determinant = m[0][0] * m[1][1] - m[1][0] * m[0][1];
        return determinant;
    }
    // Solve determinant for 3x3
    else if (dim == 3) {
        determinant = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
                    - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
                    + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        return determinant;
    }
    // Solve determinant for 4x4
    // (Laplace's expansion along the first row)
    else if (dim == 4) {
        for (int c = 0; c < 4; c++) {
            int cofactor;

            // Calculate cofactor based on column (c)
            if (c == 0) {
                cofactor = m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2])
                         - m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1])
                         + m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]);
            }
            else if (c == 1) {
                cofactor = m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2])
                         - m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0])
                         + m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]);
            }
            else if (c == 2) {
                cofactor = m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1])
                         - m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0])
                         + m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]);
            }
            else if (c == 3) {
                cofactor = m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1])
                         - m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0])
                         + m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]);
            }

            // Apply cofactor expansion (sign alternates with each column)
            determinant += ((c % 2 == 0) ? 1 : -1) * m[0][c] * cofactor;
        }
        return determinant;
    }

    return determinant;
}

// TODO
// Solve system of equations
int solveEquations() {

    // Instructions
    {
        printf("(Rewrite your equations into matrix)\n");
        printf("DO NOT include the right side of equation\nWrite it in results separately...\n\n");
        printf("Example:\n---\n");
        printf("x + 2y + 3z = 4\n");
        printf("2x + 4y + 5z = 21\n");
        printf("x + y = 0\n\n");
        printf("==>\n");
        printf("| 1 2 3 |\n");
        printf("| 2 4 5 |\n");
        printf("| 1 1 0 |\n\n");
        printf("Res. line 1: 4\nRes. line 2: 21\nRes. line 3: 0\n---\n");
    }

    // Process
    int dim;
    printf("Enter the left matrix\n");
    printf("Enter dimension (m x n) (m = n): ");
    scanf("%d", &dim);
    
    // Init and print out left side
    int **matrix_left = matrix(dim, dim);
    fillMatrix(matrix_left, dim, dim);
    printf("Left matrix:\n");
    printMatrix(matrix_left, dim, dim);

    // Init and print out right side
    printf("Enter the results on the right side\n");
    int **matrix_right = matrix(dim, 1);
    fillMatrix(matrix_right, dim, 1);
    printf("Right (results) matrix:\n");
    printMatrix(matrix_right, dim, 1);

    // Init array for results ( {x, y, z, ...} )
    double results[dim];

    // Copy of the left side
    int **matrix_copy = copyMatrix(matrix_left, dim, dim);

    // Find determinant of the left side
    int det_total = findDeterminant2(matrix_copy, dim);
    int det_position;
    // printf("### (Determinant of left matrix: %d)\n", det_total);

    if (det_total == 0) {
        printf("Total determinant is 0, operation aborted...\n");
        return 1;
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            matrix_copy[j][i] = matrix_right[j][0];
        }

        det_position = findDeterminant2(matrix_copy, dim);
        printf("Determinant at [%d]: %d\n", i, det_position);
        printf("Determinant total:   %d\n", det_total);
        printMatrix(matrix_copy, dim, dim);
        printf("------------\n");
        results[i] = (double) det_position / (double) det_total;
        matrix_copy = copyMatrix(matrix_left, dim, dim);
    }

    printf("\nResults:\n{ ");
    for (int i = 0; i < dim; i++) {
        printf("%.2f ", results[i]);
    }
    printf(" }\n");

    // !!! Throws segmentation fault

    matrixDtor(matrix_left, dim);
    matrixDtor(matrix_right, dim);
    matrixDtor(matrix_copy, dim);
    

    return 0;
}

int findTransposedMatrix() {
    int rows;
    int cols;
    printf("Enter num. of rows in matrix:");
    scanf("%d", &rows);
    printf("Enter num. of collumns in matrix:");
    scanf("%d", &cols);
    int **m = matrix(rows, cols);
    fillMatrix(m, rows, cols);
    printf("\n (Entered matrix) \n");
    printMatrix(m, rows, cols);

    int **t = matrix(cols, rows);   // Transponed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            t[j][i] = m[i][j];
        }
    }
    printf("\n=== Transponed matrix ===\n");
    printMatrix(t, cols, rows);

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
                clrscr();
                fprintf(stderr, "!!! Please choose a right option\n");  // Wrong option
                break;
            case -2:
                printf("\nLeaving...\n");   // Exit program
                return 0;
            case 11:    // (and below) - Self explanatory
                clrscr();
                printf("\nFIND DETERMINANT OF A MATRIX\n\n");
                int det = findDeterminant();
                if (det == -999999) {
                } 
                else {        
                    printf("\n=== D ===\n");
                    printf("Determinant = %d\n", det);
                }
                break;
            case 12:
                clrscr();
                printf("\nSOLVE SYSTEM OF EQUATIONS\n\n");
                solveEquations();
                break;
            case 13:
                clrscr();
                printf("\nFIND TRANSPOSED MATRIX\n\n");
                findTransposedMatrix();
                break;
            case 21:
                clrscr();
                printf("\nSUM OF MATRIXES (A+B)\n\n");
                sumMatrixes();
                break;
            case 22:
                clrscr();
                printf("\nSUBSTRACTION OF MATRIXES (A-B)\n\n");
                substractMatrixes();
                break;
            case 23:
                clrscr();
                printf("\nMULTIPLICATION OF MATRIXES (A x B)\n\n");
                    multiplyMatrixes();
                break;

        }
    }

    return 0;
}
