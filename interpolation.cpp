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

double f(double *X, double *Y, int n){
    if(n <= 1)
        return Y[0];
    return (f(X + 1, Y + 1, n - 1) - f(X, Y, n - 1))/(X[n-1] - X[0]);
}

double newton_interpolate(double *X, double *Y, int n){
    double B[n];
    for(int i = 1; i <= n; ++i){
        B[i] = f(X, Y, i);
        cout << B[i] << "*(x^"<< i - 1 <<") + ";
    }
}

int main(){
    int n = 5;
    double X[n] = {0, 1, 2, 3, 4, 5};
    double Y[n] = {0, 1, 4, 9, 16, 25};
    cout << newton_interpolate(X, Y, n) << endl;
}
