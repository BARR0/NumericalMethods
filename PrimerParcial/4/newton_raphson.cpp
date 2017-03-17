#include<iostream>
#include<cmath>
#define EPSILON 0.000001

using namespace std;

double f(double x){
    return atan(x) - 0.3;
}

double fp(double x){
    return 1/(pow(x, 2) + 1);
}

// Depende del valor absoluto de f(x)
// double n_r(double x){
//     double fx = f(x);
//     while(
//         abs(
//             fx = f(
//                 x = (x - (fx / fp(x))
//             )
//         )
//     ) >= EPSILON) cout << x << endl;
//     cout << "Error: " << (((x - (f(x) / fp(x))) - x)/(x - (f(x) / fp(x)))) << endl; // error relativo
//     return x;
// }


// Depende del error iterativo absoluto de x0 y x1
double n_r(double x0){
    double x1 = x0;
    int n=0;
    do{
        x0 = x1;
        x1 = x0 - f(x0)/fp(x0);
        cout << x1 << " : " << abs((x1 - x0)/x1) << endl;
        ++n;
    }while(abs((x1 - x0)) >= EPSILON);
    cout << "Error: " << ((x1 - x0)) << "\nIteraciones: " << n << endl;
    return x0;
}

int main(){
    cout << n_r(3.0) <<  endl;
}
