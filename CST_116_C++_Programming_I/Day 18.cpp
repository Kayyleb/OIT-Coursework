// Day 18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void inputMatrix(int matrix[3][3]);
void printMatrix(int print[3][3]);
int addMatrices(int matrixA[3][3], int matrixB[3][3]);
int multiplyMatrices(int matrixA[3][3], int matrixB[3][3]);

int main()
{
    int matrixA[3][3];
    int matrixB[3][3];

    int choice = 7;
    do {
        cout << "Option 1: Input Matrix A" << endl;
        cout << "Option 2: Input Matrix B" << endl;
        cout << "Option 3: Print Matrix A" << endl;
        cout << "Option 4: Print Matrix B" << endl;
        cout << "Option 5: Add both Matrices Together" << endl;
        cout << "Option 6: Multiply both Matrices Together" << endl;
        cout << "Option 7: Hit 7 to Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            inputMatrix(matrixA);
            break;
        case 2:
            inputMatrix(matrixB);
            break;
        case 3:
            printMatrix(matrixA);
            break;
        case 4:
            printMatrix(matrixB);
            break;
        case 5:
            addMatrices(matrixA, matrixB);
            break;
        case 6:
            multiplyMatrices(matrixA, matrixB);
            break;
        }
    } while (choice != 7);
}

void inputMatrix(int matrix[3][3]) {
    for (int r = 0; r < 3; r++) {
        cout << "Input your numbers for your matrix." << endl;
        for (int c = 0; c < 3; c++)
            cin >> matrix[r][c];
    }
}

void printMatrix(int print[3][3]) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cout << print[r][c] << "\t";
        }
        cout << endl;
    }
}

int multiplyMatrices(int matrixA[3][3], int matrixB[3][3]) {
    int product[3][3] = { 0 };
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            for (int i = 0; i < 3; i++) {
                product[r][c] += (matrixA[r][i] * matrixB[i][c]);
            }

        }
    }
    printMatrix(product);
    return 0;
}

int addMatrices(int matrixA[3][3], int matrixB[3][3]) {
    int sum[3][3] = { 0 };
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            sum[r][c] += matrixA[r][c] + matrixB[r][c];
        }
    }
    printMatrix(sum);
    return 0;
}



