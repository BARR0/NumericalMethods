#include<iostream>
#include<cmath>
#define EPSILON 0.000001

using namespace std;

double f(double x){
    return sin(x);
}

// Depende del error iterativo absoluto de x0 y x1
double secant(double x0, double x1){
    double x2;
    int n=0;
    do{
        x2 = x1 - (f(x1)*(x0 - x1))/(f(x0) - f(x1));
        x0 = x1;
        x1 = x2;
        cout << x1 << " : " << abs((x1 - x0)) << endl;
        ++n;
    }while(abs(x1 - x0) >= EPSILON || abs(f(x1)) >= EPSILON);
    cout << "Error: " << ((x1 - x0)) << endl << "Iteraciones: " << n << endl;
    return x1;
}

int main(){
    cout << secant(1.5707, 1.5708) <<  endl;
}
