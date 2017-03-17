#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

int main(int argc, char *argv[]){
    if(argc == 1) return 0;
    ifstream p_file;
    p_file.open(argv[1]);

    double XY = 0.0, X = 0.0, Y = 0.0, X2 = 0.0,
           x, y, n = 0.0;

    if (p_file.is_open()) {
        while (!p_file.eof()) {
            p_file >> x;
            if(p_file.eof()) break;
            p_file >> y;
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
        p_file.clear();// Move back to beginning of the file
        p_file.seekg (0, ios::beg);
        double c_error = 0.0, avg_error = 0.0, avg = X/n;
        while(!p_file.eof()){
            p_file >> x;
            if(p_file.eof()) break;
            p_file >> y;
            avg_error = pow(avg - a0 - a1*x, 2);
            c_error = pow((y - a0 - a1*x), 2);
        }
        c_error = sqrt(c_error/(n - 2));
        cout << "Error estandar: " << sqrt(c_error/(n - 2.0)) << endl;
        cout << "Coeficiente de correlacion: " << sqrt((avg_error - c_error)/avg_error) << endl;
    }
    p_file.close();
    return 0;
}
