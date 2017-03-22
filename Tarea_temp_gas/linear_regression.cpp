#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

void linear_regression(ifstream *p_file){
    double XY = 0.0, X = 0.0, Y = 0.0, X2 = 0.0,
           x, y, n = 0.0;

    while (!p_file->eof()) {
        *p_file >> x;
        if(p_file->eof()) break;
        *p_file >> y;
        cout << x << ", " << y << endl;
        X += x;
        Y += y;
        XY += x*y;
        X2 += x*x;
        n += 1.0;
    }
    double a0, a1;
    a1 = (n*XY - X*Y)/(n*X2 - X*X);
    a0 = Y/n - a1*X/n;
    cout << "y = (" << a0 << ") + (" << a1 << ")x" << endl;
    p_file->clear();// Move back to beginning of the file
    p_file->seekg (0, ios::beg);
    double c_error = 0.0, avg_error = 0.0, avg = Y/n;
    cout << "Average: " << avg << endl;
    while(!p_file->eof()){
        *p_file >> x;
        if(p_file->eof()) break;
        *p_file >> y;
        avg_error += pow(avg - y, 2);
        c_error += pow((y - a0 - a1*x), 2);
    }
    cout << avg_error << ":" << c_error << endl;
    double std_error = sqrt(c_error/(n - 2));
    cout << "Error estandar: " << std_error << endl;
    cout << "Coeficiente de correlacion: " << sqrt((avg_error - c_error)/avg_error) << endl;
}

int main(int argc, char *argv[]){
    if(argc == 1) return 0;
    ifstream p_file;
    p_file.open(argv[1]);

    if (p_file.is_open()) {
        linear_regression(&p_file);
    }
    p_file.close();
    return 0;
}
