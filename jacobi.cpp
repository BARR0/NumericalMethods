#include<iostream>
#include<cmath>

using namespace std;
// indexes always start from 1.

const double EPSILON = 0.001;

const int M = 4;

void print_mat(int n, int m, double A[][M + 1]){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cout << A[j][i] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

// Ultima columna son las constantes, la constante se toma como el ultimo elemento de las filas.
void jacobi(int n, int m, double A[][M + 1]){
    double r0[n + 1], r1[n + 1];
    bool check = true;
    for(int i = 1; i <= n - 1; ++i){
        r0[i] = 0.0;
    }
    r1[n] = r0[n] = -1.0;
    print_mat(n, m, A);
    while(check){
        check = false;
        for(int i = 1; i <= m; ++i){
            r1[i] = r0[i];
            r0[i] = 0.0;
            for(int j = 1; j <= n; ++j){
                if(j != i)
                    r0[i] -= (A[j][i] * r1[j])/A[i][i];
            }
            cout << r0[i] << ", ";
            check = check || abs((r1[i] - r0[i])/r0[i]) >= EPSILON;
        }
        cout << endl;
    }
    cout << endl << "Valores:" << endl;
    for(int i = 1; i < n; ++i){
        cout << r0[i] << ", ";
    }
    cout << endl;
}

int main(){
    int n = M + 1, m = M;
    double A[n + 1][M + 1];

    // A[1][1] = 2;
    // A[2][1] = -1;
    // A[3][1] = 1;
    // A[4][1] = 7;

    // A[1][2] = 1;
    // A[2][2] = 2;
    // A[3][2] = -1;
    // A[4][2] = 6;

    // A[1][3] = 1;
    // A[2][3] = 1;
    // A[3][3] = 1;
    // A[4][3] = 12;


    // A[1][1] = 2;
    // A[2][1] = -1;
    // A[3][1] = 1;
    // A[4][1] = 1;

    // A[1][2] = 1;
    // A[2][2] = 2;
    // A[3][2] = -1;
    // A[4][2] = 26;

    // A[1][3] = 1;
    // A[2][3] = 1;
    // A[3][3] = 1;
    // A[4][3] = 30;


    A[1][1] = 6;
    A[2][1] = -3;
    A[3][1] = 1;
    A[4][1] = 1;
    A[5][1] = -10;

    A[1][2] = 0;
    A[2][2] = -3;
    A[3][2] = 1;
    A[4][2] = -1;
    A[5][1] = 14;

    A[1][3] = 2;
    A[2][3] = 1;
    A[3][3] = -4;
    A[4][3] = 1;
    A[5][3] = 1;

    A[1][4] = 1;
    A[2][4] = 1;
    A[3][4] = 1;
    A[4][4] = -2;
    A[5][4] = -13;


    // A[1][1] = 1;
    // A[2][1] = 2;
    // A[3][1] = 3;

    // A[1][2] = 3;
    // A[2][2] = 2;
    // A[3][2] = 1;

    jacobi(n, m, A);
}
