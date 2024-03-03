#include <iostream>
using namespace std;

int main(){
    int matrixA[2][2];
    int matrixB[2][2];

    for (int i = 0;i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << "Masukkan nilai dari matrix A = [" << i << "] [" << j << "] : ";
            cin >> matrixA[i][j];
        }
    }

    cout << "Matrix A : " << endl;

    for (int i = 0;i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0;i < 2; i++){
        for(int j = 0;j < 2; j++){
            cout << "Masukkan nilai dari matrix B = [" << i << "][" << j << "] : ";
            cin >> matrixB[i][j];
        }
    }

    cout << "Matrix B : " << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

   int matrixC[2][2];
    cout << "Matrix C = matrix A * matrix B = " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    cout << "==================================================================\n";
    cout << "Program ini dibuat oleh : Faishal Muhammad Farhan (2310631170135)" <<endl;
    cout << "==================================================================\n";

    return 0;
}