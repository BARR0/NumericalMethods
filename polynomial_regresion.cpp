#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void regression(ifstream *p_filex, ifstream *p_filey){
    double n = 0, x, y,
           Y = 0.0, XY = 0.0, X2Y = 0.0,
           X = 0.0, X2 = 0.0, X3 = 0.0, X4 = 0.0;

    while(!p_filex->eof()){
        *p_filex >> x;
        if(p_filey->eof()) break;
        *p_filey >> y;

        cout << x << ", " << y << endl;

        X += x;
        X2 += x*x;
        X3 += pow (x, 3);
        X4 += pow (x, 4);

        Y += y;
        XY += x*y;
        X2Y += x*x*y;

        n += 1.0;
    }
    
    cout << "Ecuaciones:" << endl;
    cout << n << "*a0 + " << X << "*a1 + " << X2 << "*a2 = " << Y << endl;
    cout << X << "*a0 + " << X2 << "*a1 + " << X3 << "*a2 = " << XY << endl;
    cout << X2 << "*a0 + " << X3 << "*a1 + " << X4 << "*a2 = " << X2Y << endl;
}

void regression_m(ifstream *p_filex, ifstream *p_filey, int m){
    double n = 0.0, x, y;
    double XmY[m + 1], Xm[2*m + 1];
    for(int i = 0; i < m + 1; ++i) XmY[i] = 0.0;
    for(int i = 0; i < m + 2; ++i) Xm[i] = 0.0;

    while(!p_filex->eof()){
        *p_filex >> x;
        if(p_filey->eof()) break;
        *p_filey >> y;

        cout << x << ", " << y << endl;

        for(int i = 0; i < m + 1; ++i) XmY[i] += pow(x, i)*y;
        for(int i = 0; i < 2*m + 1; ++i) Xm[i] += pow(x, i);

        n += 1.0;
    }
    // double eqs[][];
    cout << "Ecuaciones:" << endl << endl;
    for(int i = 0; i < m + 1; ++i){
        for(int j = i; j < m + i + 1; ++j){
            cout << Xm[j] << "*a" << j - i << "\t+ ";
        }
        cout << "0\t= " << XmY[i] << endl;
    }
    cout << endl;
}

// Error Estandar (Grado m): sqrt(Sr/(n - (m + 1)));

int main(int argc, char *argv[]){
    if(argc == 1) return 0;
    ifstream p_file;
    p_file.open(argv[1]);

    if (p_file.is_open()) {
        regression_m(&p_file, &p_file, 2);
    }
    p_file.close();
    return 0;
}