#include<iostream>

using namespace std;

double interpolate(double x1, double y1, double x2, double y2, double x){
    return y1 + (y2 - y1)/(x2 - x1)*(x - x1);
}

double reverse_interpolate(double x1, double y1, double x2, double y2, double y){
    return interpolation(y1, x1, y2, x2, y);
}

double cuadratic_interpolate(double x1, double y1, double x2, double y2, double x3, double y3, double x){
    double b1 = y1,
           b2 = (y2 - y1)/(x2 - x1),
           b3 = ((y3 - y2)/(x3 - x2) - (y2 - y1)/(x2 - x1))/(x3 - x1);
    double a1 = b1 - b2*x1 + b3*x1*x2,
           a2 = b2 - b3*x1 - b3*x2,
           a3 = b3;
    return a1 + a2*x + a3*x*x;
}

int main(){
    cout << "0.3, " << interpolate(0.0, 72.5, 0.5, 78.1, 0.3) << endl;
}
