#include <iostream>
#include <cmath>
#include <string> 

using namespace std;

const double EPSILON = 0.0001;

double f(double x){
    // return 0.2 + 25*x - 200*pow(x, 2) + 675*pow(x, 3) - 900*pow(x, 4) + 400*pow(x, 5);
    // return 9.8*68.1/12.5*(1 - exp(-(12.5/68.1)*x));
    // return exp(pow(x, 2));
    // return 5;
    // return 1.0/x;
    return 2*x;
}

double definite_integral_left(double a, double b, int n){
    double h = (b - a)/n;
    double A = 0.0;
    for(double i = a; n > 0 /*i < b - h/2.0*/; i += h, --n){ // - h/2.0 is used to fix rounding errors for even numbers
        A += f(i);
    }
    cout << "h = " << h << endl;
    return A*h;
}

double definite_integral_right(double a, double b, int n){
    double h = (b - a)/n;
    double A = 0.0;
    for(double i = a + h; n > 0 /*i < b - h/2.0*/; i += h, --n){ // - h/2.0 is used to fix rounding errors for even numbers
        A += f(i);
    }
    cout << "h = " << h << endl;
    return A*h;
}

double definite_integral(double a, double b, int n){
    double h = (b - a)/n;
    double A = f(a) + f(b);
    for(double i = a + h; n > 1 /*i < b - h/2.0*/; i += h, --n){ // - h/2.0 is used to fix rounding errors for even numbers
        A += 2.0*f(i);
    }
    cout << "h = " << h << endl;
    return A*h/2.0;
}

double definite_integral(double *X, double *Y, int n){
    double A = 0.0;
    for(int i = 0; i < n - 1; ++i){
        A += (Y[0] + Y[i + 1])*(X[i + 1] - X[i])/2.0;
    }
    return A;
}

double simpson_1_3(double a, double b){
    return (b - a)*(f(a) + 4.0*f((a + b)/2.0) + f(b))/6.0;
}

double simpson_1_3_n(double *X, double *Y, int n){
    double R = Y[0] + Y[n - 1];
    for(int i = 1; i < n; i += 2)
        R += 4.0*Y[i];
    for(int j = 2; j < n - 1; j += 2)
        R += 2.0*Y[j];
    return ((X[n - 1] - X[0])*R)/(3.0*(n - 1.0));
}

double simpson_3_8(double a, double b, double fx0, double fx1, double fx2, double fx3){
    return ((b - a)*(fx0 + 3.0*fx1 + 3.0*fx2 + fx3))/8.0;
}

double romberg(double a, double b){
    int A = 10;
    double **I = new double*[A + 1];
    for(int i = 0; i < A + 1; ++i)
        I[i] = new double[A + 1];
    int n = 1;
    I[1][1] = definite_integral(a, b, n);
    int it = 0;
    double ea = -1.0;
    do{
        ++it;
        n = pow(2.0, it);
        I[it + 1][1] = definite_integral(a, b, n);
        for(int k = 2; k <= it + 1; ++k){
            double j = 2.0 + it - k;
            I[(int)j][k] = (pow(4.0, k - 1)*I[(int)j + 1][k - 1] - I[(int)j][k - 1])/(pow(4.0, k - 1) - 1);
        }
        ea = abs((I[1][it + 1] - I[2][it])/I[1][it + 1]); // Relative Iterative Error
    }while(ea > EPSILON);
    cout << "Final Error: " << ea << endl;
    return I[1][it + 1];
}

int main(int argc, char *argv[]){
    if(argc == 4){
        double a = stod(argv[1]), b =  stod(argv[2]);
        int n = stoi(argv[3]);
        cout << "=======================================" << endl;
        cout << "Rect Left: " << definite_integral_left(a, b, n) << endl;
        cout << "=======================================" << endl;
        cout << "Rect Right: " << definite_integral_right(a, b, n) << endl;
        cout << "=======================================" << endl;
        cout << "Trap: " << definite_integral(a, b, n) << endl;
        cout << "=======================================" << endl;
        cout << "Simpson 1/3: " << simpson_1_3(a, b) << endl;
        cout << "=======================================" << endl;
        cout << "Simpson 3/8: " << simpson_3_8(a, b, f(a), f(a + (b - a)/4.0), f(b - (b - a)/4.0), f(b)) << endl;
        cout << "=======================================" << endl;
        cout << "Romberg: " << romberg(a, b) << endl;
        cout << "=======================================" << endl;
    }
}
