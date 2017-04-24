#include<iostream>
#include<cmath>

using namespace std;

double interpolate(double x1, double y1, double x2, double y2, double x){
    return y1 + (y2 - y1)/(x2 - x1)*(x - x1);
}

double reverse_interpolate(double x1, double y1, double x2, double y2, double y){
    return interpolate(y1, x1, y2, x2, y);
}

double cuadratic_interpolate(double x1, double y1, double x2, double y2, double x3, double y3, double x){
    double b1 = y1,
           b2 = (y2 - y1)/(x2 - x1),
           b3 = ((y3 - y2)/(x3 - x2) - (y2 - y1)/(x2 - x1))/(x3 - x1);
    double a1 = b1 - b2*x1 + b3*x1*x2,
           a2 = b2 - b3*x1 - b3*x2,
           a3 = b3;
    cout << (a1 + a2*x + a3*x*x) << " = " << a1 << " + " << a2 << "*" << x << " + " << a3 << "*" << x << "^2" << endl;
    return a1 + a2*x + a3*x*x;
}

double reverse_cuadratic_interpolate(double x1, double y1, double x2, double y2, double x3, double y3, double fx){
    double b1 = y1,
           b2 = (y2 - y1)/(x2 - x1),
           b3 = ((y3 - y2)/(x3 - x2) - (y2 - y1)/(x2 - x1))/(x3 - x1);
    double a1 = b1 - b2*x1 + b3*x1*x2,
           a2 = b2 - b3*x1 - b3*x2,
           a3 = b3;
    double xp = (-a2 + sqrt(a2*a2 - 4*a3*a1))/2*a3,
           xm = (-a2 - sqrt(a2*a2 - 4*a3*a1))/2*a3;
    if(xp == NAN || xp == -NAN)
        return xm;
    return xp;
}

void newton_interpolate_d(double *X, double *Y, int n){
    double **f = new double*[n];
    for(int i = 0; i < n; ++i){
        f[i] = new double[n];
        f[i][i] = Y[i];
    }
    for(int gap = 1; gap < n; ++ gap){
        for(int i = 0; i + gap < n; ++i){
            f[i][i + gap] = (f[i + 1][i + gap] - f[i][i + gap - 1])/(X[i + gap] - X[i]);
        }
    }
    cout << "fn(x) = ";
    for(int i = 0; i < n; ++i){
        cout << f[0][i];
        for(int j = 0; j < i; ++j){
            cout << "(x - " << X[j] << ")";
        }
        cout << " + ";
    }
    cout << "0" << endl;
    for(int i = 0; i < n; ++i){
        delete [] f[i];
    }
    delete [] f;
}

void newton_interpolate(double *X, double *Y, int n){
    double f[n];
    double R[n];
    for(int i = 0; i < n; ++i){
        f[i] = Y[i];
    }
    R[0] = f[0];
    for(int step = 1; step < n; ++step){
        for(int i = 0; i < n - step; ++i){
            f[i] = (f[i + 1] - f[i])/(X[i + step] - X[i]);
        }
        R[step] = f[0];
    }
    cout << "fn(x) = ";
    for(int i = 0; i < n; ++i){
        cout << R[i];
        for(int j = 0; j < i; ++j){
            cout << "(x - " << X[j] << ")";
        }
        cout << " + ";
    }
    cout << "0" << endl;
}

// void newton_interpolate(double *X, double *Y, int n){
//     double f[n];
//     double R[n];
//     for(int i = 0; i < n; ++i){
//         f[i] = Y[i];
//     }
//     R[0] = f[0];
//     for(int step = 1; step < n; ++step){
//         for(int i = 0; i < n - step; ++i){
//             f[i] = (f[i + 1] - f[i])/(X[i + step] - X[i]);
//         }
//         R[step] = f[0];
//     }
//     cout << "fn(x) = ";
//     for(int i = 0; i < n; ++i){
//         cout << R[i];
//         for(int j = 0; j < i; ++j){
//             cout << "(x - " << X[j] << ")";
//         }
//         cout << " + ";
//     }
//     cout << "0" << endl;
// }

double lagrange_interpolate_L(double *X, int n, int i, double x){
    double L = 1.0;
    for(int j = 0; j < n; ++j){
        if(j == i) continue;
        L *= (x - X[j])/(X[i] - X[j]);
    }
    return L;
}

double lagrange_interpolate(double *X, double *Y, int n, double x){
    double y = 0.0;
    for(int i = 0; i < n; ++i){
        y += lagrange_interpolate_L(X, n, i, x)*Y[i];
    }
    return y;
}

int main(){
    // int n = 5;
    // double X[n] = {0, 1, 2, 3, 4, 5};
    // double Y[n] = {0, 1, 4, 9, 16, 25};
    int n = 3;
    double X[n] = {1, 4, 6};
    double Y[n] = {0, 1.386294, 1.791760};

    cout << lagrange_interpolate(X, Y, n, 5) << endl;
    newton_interpolate(X, Y, n);
    newton_interpolate_d(X, Y, n);
}
