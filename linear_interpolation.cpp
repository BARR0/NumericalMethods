#include<iostream>

using namespace std;

double interpolate(double x1, double y1, double x2, double y2, double x){
    return y1 + (y2 - y1)/(x2 - x1)*(x - x1);
}

double reverse_interpolate(double x1, double y1, double x2, double y2, double y){
    return interpolation(y1, x1, y2, x2, y);
}

int main(){
    cout << "0.3, " << interpolate(0.0, 72.5, 0.5, 78.1, 0.3) << endl;
}
