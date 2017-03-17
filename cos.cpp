#include<iostream>
#include<cmath>
#define MAX_ERROR 1E-12

using namespace std;

double factorial(double number);

int main(){
    double x, cosine = 0, aerr, rerr, i=0;
    cout << "Angulo: ";
    cin >> x;
    do{
        cosine += pow(-1, i)*pow(x, 2*i)/factorial(2*i);
        aerr = cos(x) - cosine;
        rerr = abs(aerr/cos(x));
        ++i;
    }while(rerr > MAX_ERROR);
    cout << "Cosine approx.: " << cosine << endl;
    cout << "Standard function: " << cos(x) << endl;
    cout << "Iterations: " << i << endl;
    cout << "Absolute Error: " << cos(x) - cosine << endl;
    cout << "Relative Error: " << (cos(x) - cosine)/cos(x) << endl;

    return(0);
}

double factorial(double n){
    double f = 1;
    for(int c = 2; c <= n; c++){
        f *= c;
    }
    return f;
}