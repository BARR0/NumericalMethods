#include<iostream>
#include <stdlib.h>
#include<cmath>
#include<vector>
#define EPSILON 1.0

using namespace std;

double cramerR(double b[], double c[]){
    return (c[3]*b[0] - b[1]*c[2])/(c[2]*c[2] - c[1]*c[3]);
}

double cramerS(double b[], double c[]){
    return (c[1]*b[1] - b[0]*c[2])/(c[2]*c[2] - c[1]*c[3]);
}

void bairstowDiv(double a[], double b[], int size, double r, double s){
    for(int i = size - 1; i >= 0; --i){
        a[i] = b[i];
        if(i + 1 < size){
            a[i] += a[i + 1] * r;
        }
        if(i + 2 < size){
            a[i] += a[i + 2] * s;
        }
        cout << a[i] << ", ";
    }
    cout << endl;
}

void synDiv(double a[], int size, double r){
    for(int i = size - 2; i > 0; --i){
        a[i] += a[i + 1] * r;
        cout << a[i] << ", ";
    }
    cout << endl;
    for(int i = 0; i < size - 1; ++i){
        a[i] = a[i + 1];
    }
}

void bairstow(double coeficients[], int size, double r, double s){
    int i = 0, osize = size, iteraciones = 0;
    double //s = -1.0, r = -1.0,
           deltaS, deltaR;
    double bn[size],
           cn[size],
           roots[size];
    while(size > 2){
        do{
            cout << "Guardando en bn: ";
            bairstowDiv(bn, coeficients, size, r, s);
            cout << "Guardando en cn: ";
            bairstowDiv(cn, bn, size, r, s);
            deltaR = cramerR(bn, cn);
            r += deltaR;
            deltaS = cramerS(bn, cn);
            s += deltaS;
            ++iteraciones;
        }while(abs(deltaR/r)*100.0 >= EPSILON || abs(deltaS/s)*100.0 >= EPSILON);// ERROR PARCIAL2
        cout << endl << "Error:" << endl << "r: " << (deltaR/r)*100.0 << "%" << endl << "s: " << (deltaS/s)*100.0 << "%" << endl;
        cout << "Iteraciones: " << iteraciones << endl;
        cout << "Nuevo Polinomio:" << endl;
        for(int i = 2; i < size; ++i){
            cout << bn[i] << "(x ^ " << i - 2 << ") + ";
        }

        double num = pow(r, 2) + 4*s;
        if(abs(num)*100 <= EPSILON) num = 0.0;

        double x1 = (r + sqrt(num))/2.0,
               x2 = (r - sqrt(num))/2.0;

        if(num >= 0.0){
            cout << " 0 = 0" << endl << "==============================================" << endl << "Roots:" << endl << x1 << endl << x2 << endl << endl;
            r = x1;
            s = x2;
        }
        else{
            cout << " 0 = 0" << endl << "==============================================" << endl << "Roots:" << endl << r/2.0 << " + " << sqrt(abs(num))/2.0 << "i" << endl << r/2.0 << " - " << sqrt(abs(num))/2.0 << "i" << endl << endl;
            s = r = -1.0;
        }

        roots[i++] = x1;
        roots[i++] = x2;
        size -= 2;
        for(int j = 0; j < size; ++j){
            coeficients[j] = bn[j + 2];
        }
    }
    if(size == 2){
        roots[i++] = -coeficients[0]/coeficients[1];
        cout << "==============================================" << endl << "Roots:" << endl <<  roots[i - 1]<< endl;
    }
    cout << endl << "All Roots:" << endl;
    --i;
    while(i >= 0){
        cout << roots[i--] << endl;
    }
    cout << endl << "nan o -nan significa raiz imaginaria, estas solo se imprimen en el momento que son calculadas." << endl;
    cout << "Iteraciones: " << iteraciones << endl;
}

int main(int argc, char *argv[]){
    int size = 4;
    double arr[size];
    arr[0] = -2.5;
    arr[1] = 5.25;
    arr[2] = -4;
    arr[3] = 1;

    bairstow(arr, size, -0.5, 0.5);
}
