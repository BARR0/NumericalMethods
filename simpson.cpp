#include <iostream>

using namespace std;

// double f(double x){
//     return 0;
// }

// double simpson_1_3(double a, double b, int n/*Not used, prevents changing main method.*/){
//     return (b - a)*(f(a) + 4.0*f((a + b)/2.0) + f(b))/6.0;
// }

double simpson_1_3_n(double *X, double *Y, int n){
    double A = Y[0] + Y[n - 1];
    for(int i = 1; i < n; i += 2){
        A += 4.0*Y[i];
    }
    for(int i = 2; i < n - 1; i += 2){
        A += 2.0*Y[i];
    }
    return A*(X[n - 1] - X[0])/(3.0*(n - 1));
}

double simpson_3_8(double *X, double *Y){
    return (X[3] - X[0])*(Y[0] + 3.0*Y[1] + 3.0*Y[2] + Y[3])/8.0;
}

double simpson_3_8_n(double *X, double *Y, int n){
    double A = Y[0] + Y[n - 1];
    for(int i = 1; i < n; i += 2){
        A += 4.0*Y[i];
    }
    for(int i = 2; i < n - 1; i += 2){
        A += 2.0*Y[i];
    }
    return A*(X[n - 1] - X[0])/(3.0*(n - 1));
}

int main(){
    int n = 5;
    double X[n] = {0, 0.2, 0.4, 0.6, 0.8};
    double Y[n] = {0.2, 1.288, 2.456, 3.464, 0.232};
    cout << simpson_1_3_n(X, Y, n) << endl;
}
