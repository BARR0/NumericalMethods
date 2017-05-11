#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y){
    // return 3*x + y;
    return (-2*pow(x, 3)) + 12*pow(x, 2) - 20*x + 8.5;
}


// Para tamano de paso:
// double dx; <-- Tamano de paso
// n = (xfinal - x)/dx; <-- # de iteraciones

double euler(double x, double y, double xfinal, int n){
    double yi = y,
           h = (xfinal - x)/(double)n;
    for(double i = x; n > 0; --n){
        yi = yi + f(i, yi)*h;
        i += h;
        cout << i << ", " << yi << endl;
    }
    return yi;
}

double heun(double x, double y, double xfinal, int n){
    double yi = y,
           yi0 = 0,
           h = (xfinal - x)/(double)n;
    for(double i = x + h; n > 0; --n){
        yi0 = yi + f(x, yi)*h;
        yi = yi + (f(i, yi) + f(i + h, yi0))*h/2.0;
        i += h;
        cout << i << ", " << yi << endl;
    }
    return yi;
}

double mid_point(double x, double y, double xfinal, int n){
    double yi = y,
           yihalf = 0,
           h = (xfinal - x)/(double)n;
    for(double i = x; n > 0; --n){
        yihalf = yi + f(i, yi)*h/2;
        yi = yi + f(i + h/2.0, yihalf)*h;
        i += h;
        cout << i << ", " << yi << endl;
    }
    return yi;
}

double euler(double x, double y, double xfinal, double dx){
    double yi = y,
           n = (xfinal - x)/dx;
    for(double i = x; n > 0; --n){
        yi = yi + f(i, yi)*dx;
        i += dx;
        cout << i << ", " << yi << endl;
    }
    return yi;
}

double heun(double x, double y, double xfinal, double dx){
    double yi = y,
           yi0 = 0,
           n = (xfinal - x)/dx;
    for(double i = x + dx; n > 0; --n){
        yi0 = yi + f(x, yi)*dx;
        yi = yi + (f(i, yi) + f(i + dx, yi0))*dx/2.0;
        i += dx;
        cout << i << ", " << yi << endl;
    }
    return yi;
}

double mid_point(double x, double y, double xfinal, double dx){
    double yi = y,
           yihalf = 0,
           n = (xfinal - x)/dx;
    for(double i = x; n > 0; --n){
        yihalf = yi + f(i, yi)*dx/2;
        yi = yi + f(i + dx/2.0, yihalf)*dx;
        i += dx;
        cout << i << ", " << yi << endl;
    }
    return yi;
}

int main(){
    double x = 0, y = 1, x2 = 4;
    int n = 10;
    cout << euler(x, y, x2, n) << endl;
    cout << heun(x, y, x2, n) << endl;
    cout << mid_point(x, y, x2, n) << endl;
    double dx = 0.5;
    cout << endl;
    cout << euler(x, y, x2, dx) << endl;
    cout << heun(x, y, x2, dx) << endl;
    cout << mid_point(x, y, x2, dx) << endl;
}
