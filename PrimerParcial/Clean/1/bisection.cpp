#include<iostream>
#include<cmath>
#define EPSILON 0.000001

using namespace std;

double f(double x){
    return pow(exp(1.0), x) - pow(x, 2.0) + 3.0*x - 2.0;
}


// Depende del error con respecto de f(x)
double bisection(double x0, double x1){
    if(f(x0) * f(x1) > 0.0){
        cout << "Invalid range" << endl;
        return NAN;
    }
    double xm = (x0 + x1)/2.0;
    double xm2;
    int n=0;
    while(abs(f(xm)) >= EPSILON){
        cout << x0 << ", " << xm << ", " << x1 << endl;
        if(f(x0) * f(xm) < 0.0){
            x1 = xm;
        }
        else{
            x0 = xm;
        }
        xm2 = xm;
        xm = (x0 + x1)/2.0;
        ++n;
    }
    cout << "Error: " << f(xm) << "\nError it.: " << xm - xm2 << "\nIteraciones: " << n << endl; // error relativo
    return xm;
}

// Depende del error iterativo entre x0 y x1
// double bisection(double x0, double x1){
//     if(f(x0) * f(x1) > 0.0){
//         cout << "Invalid range" << endl;
//         return NAN;
//     }
//     double xm = (x0 + x1)/2.0,
//            xmOld;
//     do{
//         cout << x0 << ", " << xm << ", " << x1 << endl;
//         if(f(x0) * f(xm) < 0.0){
//             x1 = xm;
//         }
//         else{
//             x0 = xm;
//         }
//         xmOld = xm;
//         xm = (x0 + x1)/2.0;
//     }while(abs((xm - xmOld)/xm) >= EPSILON);
//     return xm;
// }

int main(){
    cout << bisection(-1.0, 1.0) << endl;
}
