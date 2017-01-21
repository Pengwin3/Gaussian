#include "iostream"
#include "MatrixClass.h"

using namespace std;

int main(void) {
    int rows;
    // cout << "Please input size:\nRows= ";
    cin >> rows;
    // cout << "Cols= ";
    matrix m(rows, rows+1);
    m.fill();
    m.display();
    std::cout << '\n';
    m.pivotize();
    // m.display();
    m.solve();
    std::cout << '\n';
    // m.display();
    m.back_solve();
    // m.display();
    return 0;
   }
