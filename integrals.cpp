#include <iostream>
#include <cmath>
#include <string> 

using namespace std;

double f(double x){
    // return 0.2 + 25*x - 200*pow(x, 2) + 675*pow(x, 3) - 900*pow(x, 4) + 400*pow(x, 5);
    // return 9.8*68.1/12.5*(1 - exp(-(12.5/68.1)*x));
    return exp(pow(x, 2));
}

double definite_integral_left(double a, double b, int n){
    double h = (b - a)/n;
    double A = 0.0;
    for(double i = a; i < b - h/2.0; i += h){ // - h/2.0 is used to fix rounding errors for even numbers
        A += f(i);
    }
    cout << "h = " << h << endl;
    return A*h;
}

double definite_integral(double a, double b, int n){
    double h = (b - a)/n;
    double A = f(a) + f(b);
    for(double i = a + h; i < b - h/2.0; i += h){ // - h/2.0 is used to fix rounding errors for even numbers
        A += 2.0*f(i);
    }
    cout << "h = " << h << endl;
    return A*h/2.0;
}

double simpson_1_3(double a, double b, int n/*Not used, prevents changing main method.*/){
    return (b - a)*(f(a) + 4.0*f((a + b)/2.0) + f(b))/6.0;
}

double simpson_1_3_n(double *Y, double *Y, int n){
    return (b - a)*(f(a) + 4.0*f((a + b)/2.0) + f(b))/6.0;
}

double romberg(double *X, int n){
    
}

int main(int argc, char *argv[]){
    if(argc != 4) return 1;
    cout << definite_integral_left(stod(argv[1]), stod(argv[2]), stoi(argv[3])) << endl;
}
