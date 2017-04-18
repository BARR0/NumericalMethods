#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void print_mat(int n, int m, double **A){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cout << A[j][i] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void forward_elim(int n, int m, double **A){
    if(n != m + 1) return;

    double c;
    // Forward elimination
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= m; ++j){
            if(A[i][j] == 0.0) continue;
            c = (A[i][i])/(A[i][j]);
            for(int k = i; k <= n; ++k){
                A[k][j] = A[k][i] - (A[k][j])*c;
            }
        }
    }
}

void forward_sub(int n, int m, double **A, double R[]){
    // Forward substitution
    for(int i = 1; i < n; ++i){
        R[n - i] = 0;
        for(int j = 1; j < i; ++j){
            R[n - i] -= A[n - j][n - i]*R[n - j];
        }
        R[n - i] += A[n][n - i];
        R[n - i] /= A[n - i][n - i];
    }
}

void gauss_elim(int n, int m, double **A, double *R){
    forward_elim(n, m, A);
    forward_sub(n, m, A, R);
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
    double *R = new double[m + 1];
    double **eqs = new double*[m + 3];
    for(int i = 1; i <= m + 2; ++i){
        eqs[i] = new double[m + 2];
    }

    cout << "Ecuaciones:" << endl << endl;
    for(int i = 0; i < m + 1; ++i){
        for(int j = i; j < m + i + 1; ++j){
            eqs[j - i + 1][i + 1] = Xm[j];
            cout << Xm[j] << "*a" << j - i << "\t+ ";
        }
        eqs[m + 2][i + 1] = XmY[i];
        cout << "0\t= " << XmY[i] << endl;
    }
    cout << endl;

    gauss_elim(m + 2, m + 1, eqs, R - 1);

    cout << "y = ";
    for(int i = 0; i < m + 1; ++i) cout << R[i] << "*x^" << i << " + ";
    cout << "0" << endl;

    p_filex->clear();// Move back to beginning of the file
    p_filex->seekg (0, ios::beg);
    p_filey->clear();// Move back to beginning of the file
    p_filey->seekg (0, ios::beg);

    errors(p_filex, p_filey, R, m + 1);

    for(int i = 1; i <= m + 1; ++i){
        delete [] eqs[i];
    }
    delete [] eqs;
}

int main(int argc, char *argv[]){
    if(argc == 1) return 0;
    ifstream p_file;
    p_file.open(argv[1]);

    if (p_file.is_open()) {
        regression_m(&p_file, &p_file, 4);
    }
    p_file.close();
    return 0;
}