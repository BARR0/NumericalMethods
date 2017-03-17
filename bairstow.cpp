#include<iostream>
#include<cmath>
#include<vector>
#define EPSILON 0.000001

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
    int i = 0;
    double //s = -1.0, r = -1.0,
           deltaS, deltaR;
    double bn[size],
           cn[size],
           roots[size];
    while(size > 0){
        do{
            cout << "Guardando en bn: ";
            bairstowDiv(bn, coeficients, size, r, s);
            cout << "Guardando en cn: ";
            bairstowDiv(cn, bn, size, r, s);
            deltaR = cramerR(bn, cn);
            r += deltaR;
            deltaS = cramerS(bn, cn);
            s += deltaS;
            // cout << r << " : " << s << endl;
        }while(abs(deltaR/r) >= EPSILON || abs(deltaS/s) >= EPSILON);
        double x1 = (r + sqrt(pow(r, 2) + 4*s))/2.0,
               x2 = (r - sqrt(pow(r, 2) + 4*s))/2.0;
        roots[i++] = x1;
        roots[i++] = x2;
        r = x1;
        s = x2;
        cout << "Roots:" << endl << x1 << endl << x2 << endl << endl;
        size -= 2;
        cout << "Nuevo Polinomio: ";
        for(int j = 0; j < size; ++j){
            coeficients[j] = bn[j + 2];
            cout << coeficients[j] << ", ";
        }
        cout << endl;
    }
    // if(size == 1){
    //     do{
    //         bairstowDiv(bn, coeficients, size, r, s);
    //         bairstowDiv(cn, bn, size, r, s);
    //         deltaR = cramerR(bn, cn);
    //         r += deltaR;
    //         deltaS = cramerS(bn, cn);
    //         s += deltaS;
    //         // cout << r << " : " << s << endl;
    //     }while(abs(deltaR/r) >= EPSILON || abs(deltaS/s) >= EPSILON);
    //     double x1 = -s/r;
    //     roots[i++] = x1;
    //     cout << x1 << endl;
    // }
}

// double oldBairstow(double coeficients[], int size){
//     int i = 0;
//     double s = -1.0, r = -1.0,
//            deltaS, deltaR;
//     double bn[size],
//            cn[size],
//            roots[size-1];
//     while(i < size - 2){
//         do{
//             bairstowDiv(bn, coeficients, size, r, s);
//             bairstowDiv(cn, bn, size, r, s);
//             deltaR = cramerR(bn, cn);
//             r += deltaR;
//             deltaS = cramerS(bn, cn);
//             s += deltaS;
//             cout << r << " : " << s << endl;
//         }while(abs(deltaR/r) >= EPSILON || abs(deltaS/s) >= EPSILON);
//         double x1 = (r + sqrt(pow(r, 2) + 4*s))/2.0,
//                x2 = (r - sqrt(pow(r, 2) + 4*s))/2.0;
//         roots[i++] = x1;
//         roots[i++] = x2;
//         r = x1;
//         s = x2;
//         bairstowDiv(coeficients, coeficients, size, r, s);
//     }
//     for(int i = 0; i < size - 1; ++i){
//         cout << roots[i] << ", ";
//     }
//     cout << endl;
//     return roots[0];
// }

// double p_bairstow(double coeficients[], int size){
//     double s = -1.0, r = -1.0,
//            deltaS, deltaR;
//     double *bn = new double[size],
//            *cn = new double[size];
//     do{
//         bairstowDiv(bn, coeficients, size, r, s);
//         bairstowDiv(cn, bn, size, r, s);
//         deltaR = cramerR(bn, cn);
//         r += deltaR;
//         deltaS = cramerS(bn, cn);
//         s += deltaS;
//         cout << r << " : " << s << endl;
//     }while(abs(deltaR/r) >= EPSILON || abs(deltaS/s) >= EPSILON);
//     delete [] bn;
//     delete [] cn;
//     bn = cn = NULL;
//     double x1 = (r + sqrt(pow(r, 2) + 4*s))/2.0,
//            x2 = (r - sqrt(pow(r, 2) + 4*s))/2.0;
//     cout << "roots: " << x1 << ", " << x2 << endl;
//     return x1;
// }

int main(){
    // int size;
    // cin >> size;
    // double *arr = new double[size];
    // for(int i = 0; i < size; i++){
    //     cin >> arr[i];
    // }
    // cout << p_bairstow(arr, size) <<  endl;
    // delete [] arr;
    // arr = NULL;

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

    bairstow(arr, size, -1.0, -1.0);
}
