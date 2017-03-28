#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

void linealization(ifstream *p_filex, ifstream *p_filey){
    double XY = 0.0, X = 0.0, Y = 0.0, X2 = 0.0, YA = 0.0,
           x, y, n = 0.0;

    while (!p_filex->eof()) {
        *p_filex >> x;
        if(p_filey->eof()) break;
        *p_filey >> y;
        cout << x << ", " << y << endl;
        X += x;
        Y += log(y);
        XY += x*log(y);
        X2 += x*x;
        n += 1.0;

        YA += y;
    }
    double a0, beta, alpha;
    beta = (n*XY - X*Y)/(n*X2 - X*X);
    a0 = Y/n - beta*X/n;
    alpha = exp(a0);

    cout << "Ln(y) = " << a0 << " + (" << beta << ")x" << endl;
    cout << "Ln(y) = Ln(" << alpha << ") + (" << beta << ")x" << endl;
    cout << "y = " << alpha << " * e^(" << beta << "x)" << endl;

    p_filex->clear();// Move back to beginning of the file
    p_filex->seekg (0, ios::beg);
    p_filey->clear();// Move back to beginning of the file
    p_filey->seekg (0, ios::beg);

    double c_error = 0.0, avg_error = 0.0, avg = YA/n;
    while(!p_filex->eof()){
        *p_filex >> x;
        if(p_filey->eof()) break;
        *p_filey >> y;
        avg_error += pow(avg - y, 2);
        c_error += pow((y - alpha*exp(beta*x)), 2);
    }
    double std_error = sqrt(c_error/(n - 2));
    cout << "Error estandar: " << std_error << endl;
    cout << "Coeficiente de correlacion: " << sqrt((avg_error - c_error)/avg_error) << endl;
}

int main(int argc, char *argv[]){
    if(argc == 1) return 0;
    ifstream p_file;
    p_file.open(argv[1]);

    if (p_file.is_open()) {
        linealization(&p_file, &p_file);
    }
    p_file.close();
    return 0;
}
