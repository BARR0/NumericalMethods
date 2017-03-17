#include<iostream>

using namespace std;
// indexes always start from 1.

// const int M = 2;
const int M = 5;

void print_mat(int n, int m, double A[][M + 1]){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cout << A[j][i] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void forward_elim(int n, int m, double A[][M + 1]){
    if(n != m + 1) return;

    double c;
    // Forward elimination
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= m; ++j){
            if(A[i][j] == 0.0) continue;
            c = (A[i][i])/(A[i][j]);
            for(int k = i; k <= n; ++k){
                A[k][j] = A[k][i] - (A[k][j])*c;
            }
        }
    }
}

void forward_sub(int n, int m, double A[][M + 1], double R[]){
    // Forward substitution
    for(int i = 1; i < n; ++i){
        R[n - i] = 0;
        for(int j = 1; j < i; ++j){
            R[n - i] -= A[n - j][n - i]*R[n - j];
        }
        R[n - i] += A[n][n - i];
        R[n - i] /= A[n - i][n - i];
    }
}

void gauss_elim(int n, int m, double A[][M + 1]){
    print_mat(n, m, A);

    forward_elim(n, m, A);
    double R[n];
    forward_sub(n, m, A, R);

    print_mat(n, m, A);

    //print
    for(int i = 1; i < n; ++i){
        cout << R[i] << ", ";
    }
    cout << endl;
}

int main(){
    // int n = 3, m = M;
    // double A[n + 1][M + 1];

    // A[1][1] = 2;
    // A[2][1] = 3;
    // A[3][1] = 7;

    // A[1][2] = 3;
    // A[2][2] = -5;
    // A[3][2] = 1;

    int n = 6, m = M;
    double A[n + 1][M + 1];

    A[1][1] = 4;
    A[2][1] = 12;
    A[3][1] = 6;
    A[4][1] = 8;
    A[5][1] = 1;
    A[6][1] = 6;

    A[1][2] = -8;
    A[2][2] = -6;
    A[3][2] = -9;
    A[4][2] = 6;
    A[5][2] = 2;
    A[6][2] = -23;

    A[1][3] = 6;
    A[2][3] = 5;
    A[3][3] = -4;
    A[4][3] = 5;
    A[5][3] = 3;
    A[6][3] = 10;

    A[1][4] = -5;
    A[2][4] = 4;
    A[3][4] = 2;
    A[4][4] = -1;
    A[5][4] = 4;
    A[6][4] = 3;

    A[1][5] = -10;
    A[2][5] = 5;
    A[3][5] = 3;
    A[4][5] = 6;
    A[5][5] = 3;
    A[6][5] = -15;


    gauss_elim(n, m, A);
}
