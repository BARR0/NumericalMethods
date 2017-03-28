#include<iostream>
#include <stdlib.h>
#include<cmath>
#include<vector>
#define EPSILON 0.00001

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

void bairstow_single(double coeficients[], int size, double r, double s){
    double deltaS, deltaR;
    double bn[size],
           cn[size];
    do{
        cout << "Guardando en bn: ";
        bairstowDiv(bn, coeficients, size, r, s);
        cout << "Guardando en cn: ";
        bairstowDiv(cn, bn, size, r, s);
        deltaR = cramerR(bn, cn);
        r += deltaR;
        deltaS = cramerS(bn, cn);
        s += deltaS;
    }while(abs(deltaR/r) >= EPSILON || abs(deltaS/s) >= EPSILON);
    cout << "Error:" << endl << "r: " << deltaR/r << endl << "s: " << deltaS/s << endl;
    // cout << endl << r << endl;
    // cout << endl << s << endl;
    // cout << endl << pow(r, 2) + 4*s << endl;
    double num = pow(r, 2) + 4*s;
    if(abs(num) <= EPSILON) num = 0.0;
    cout << "Nuevo Polinomio:" << endl;
    for(int i = 2; i < size; ++i){
        cout << bn[i] << "(x ^ " << i - 2 << ") + ";
    }
    if(num >= 0.0){
        double x1 = (r + sqrt(num))/2.0,
               x2 = (r - sqrt(num))/2.0;
        cout << " 0 = 0" << endl << "Roots:" << endl << x1 << endl << x2 << endl << endl;
    }
    else{
        cout << " 0 = 0" << endl << "Roots:" << endl << r/2.0 << " + " << sqrt(abs(num))/2.0 << "i" << endl << r/2.0 << " - " << sqrt(abs(num))/2.0 << "i" << endl << endl;
    }
}

void bairstow(double coeficients[], int size, double r, double s){
    int i = 0, osize = size;
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
        }while(abs(deltaR/r) >= EPSILON || abs(deltaS/s) >= EPSILON);
        cout << endl << "Error:" << endl << "r: " << deltaR/r << endl << "s: " << deltaS/s << endl;
        cout << "Nuevo Polinomio:" << endl;
        for(int i = 2; i < size; ++i){
            cout << bn[i] << "(x ^ " << i - 2 << ") + ";
        }

        double num = pow(r, 2) + 4*s;
        if(abs(num) <= EPSILON) num = 0.0;

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
        cout << "==============================================" << endl << "Roots:" <<  roots[i - 1]<< endl;
    }
    cout << endl << "Roots:" << endl;
    --i;
    while(i >= 0){
        cout << roots[i--] << endl;
    }
}

int main(int argc, char *argv[]){
    if(argc == 1){
        // int size;
        // cin >> size;
        // double *arr = new double[size];
        // for(int i = 0; i < size; i++){
        //     cin >> arr[i];
        // }
        // cout << p_bairstow(arr, size) <<  endl;
        // delete [] arr;
        // arr = NULL;

        // x^5 - 3.5*x^4 + 2.75*x^3 + 2.125*x^2 - 3.875*x + 1.25 = 0
        int size = 6;
        double arr[size];
        arr[0] = 1.25;
        arr[1] = -3.875;
        arr[2] = 2.125;
        arr[3] = 2.75;
        arr[4] = -3.5;
        arr[5] = 1.0;

        // int size = 1;
        // double arr[size];
        // arr[0] = 1.25;

        // int size = 3;
        // double arr[size];
        // arr[0] = 2;
        // arr[1] = 2;
        // arr[2] = 1;

        // int size = 4;
        // double arr[size];
        // arr[0] = 1;
        // arr[1] = 3;
        // arr[2] = 3;
        // arr[3] = 1;

        bairstow(arr, size, -1.0, -1.0);
    }
    else{
        int size = argc - 3, i;
        double arr[size];
        for(i = 0; i < size; ++i){
            arr[i] = atof(argv[i + 3]);
        }
        bairstow(arr, size, atof(argv[1]), atof(argv[2]));
    }
}
