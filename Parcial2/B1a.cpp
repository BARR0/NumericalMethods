#include<iostream>
#include<cmath>
#define EPSILON 0.00001

using namespace std;

double f(double x){
    return pow(x, 3) + 10*x + 5;
}

// Depende del error absoluto evaluado en la funcion
double secant(double x0, double x1){
    double x2;
    int n=0;
    do{
        x2 = x1 - (f(x1)*(x0 - x1))/(f(x0) - f(x1));
        x0 = x1;
        x1 = x2;
        cout << x1 << " : " << f(x1) << endl;
        ++n;
    }while(abs(f(x1)) >= EPSILON);// ERROR PARCIAL2
    cout << "Error: " << f(x1) << endl << "Iteraciones: " << n << endl;
    return x1;
}

int main(){
    cout << secant(0.0, -1.0) <<  endl;
}
