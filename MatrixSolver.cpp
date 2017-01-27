#include "MatrixClass.h"

using namespace std;

int main(void) {
    int rows;
    cin >> rows;
    matrix m(rows, rows+1);
    m.fill();
    m.display();
    // Excluded because input is expected to be diagonally dominant
    // m.pivotize();
    m.solve();
    m.back_solve();
    m.errorCheck();
    return 0;
   }
