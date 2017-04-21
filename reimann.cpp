#include <iostream>
#include <cmath>
#include <string> 

using namespace std;

double f(double x){
    return 0.2 + 25*x - 200*pow(x, 2) + 675*pow(x, 3) - 900*pow(x, 4) + 400*pow(x, 5);
}

double definite_integral_left(double a, double b, int n){
    double h = (b - a)/n;
    double A = 0.0;
    for(double i = a; i < b; i += h){
        A += f(i);
    }
    cout << "h = " << h << endl;
    return A*h;
}

double definite_integral(double a, double b, int n){
    double h = (b - a)/n;
    double A = f(a) + f(b);
    for(double i = a + h; i < b; i += h){
        A += 2.0*f(i);
    }
    cout << "h = " << h << endl;
    return A*h/2.0;
}

int main(int argc, char *argv[]){
    if(argc != 4) return 1;
    cout << definite_integral(stod(argv[1]), stod(argv[2]), stoi(argv[3])) << endl;
}
