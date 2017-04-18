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

// Error Estandar (Grado m): sqrt(Sr/(n - (m + 1)));
void errors(ifstream *p_filex, ifstream *p_filey, double am[], int m){
    double c_error = 0.0, x, y, n = 0.0, Y = 0.0;
    while(!p_filex->eof()){
        *p_filex >> x;
        if(p_filey->eof()) break;
        *p_filey >> y;
        Y += y;
        double tmp = y;
        for(int i = 0; i < m + 1; ++i) tmp -= am[i]*pow(x, i);
        c_error += pow(tmp, 2);
        n += 1.0;
    }
    double std_error = sqrt(c_error/(n - (m + 1)));
    cout << "Error estandar: " << std_error << endl;

    p_filex->clear();// Move back to beginning of the file
    p_filex->seekg (0, ios::beg);
    p_filey->clear();// Move back to beginning of the file
    p_filey->seekg (0, ios::beg);

    double avg = Y/n, avg_error = 0.0;
    while(!p_filex->eof()){
        *p_filex >> x;
        if(p_filey->eof()) break;
        *p_filey >> y;
        avg_error += pow(avg - y, 2);
    }
    cout << "Coeficiente de correlacion: " << sqrt((avg_error - c_error)/avg_error) << endl;
}

int main(int argc, char *argv[]){
    if(argc > 1){
        int size = argc - 2;
        double arr[size];
        for(int i = 0; i < size; ++i){
            arr[i] = atof(argv[i + 2]);
        }
        ifstream p_file;
        p_file.open(argv[1]);

        if (p_file.is_open()) {
            errors(&p_file, &p_file, arr, size);
        }
        p_file.close();
        return 0;
    }
}