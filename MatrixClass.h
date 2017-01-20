#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

class matrix
{
private:
int m, n;
double **mat;
public:

matrix(int row, int col)
{
        m = row;
        n = col;
        mat = new (double *);
        m;
        for (int i = 0; i < m; i++)
                mat[i] = new double[n];
}

~matrix(){
}

void fill()
{
        int i=0, j=0;
        cout << "Enter matrix elements for:\n";
        for ( i; i < m; i++)
        {
                for ( j =0; j < n; j++)
                {
                        cout << "[" << i+1 << "] "
                             << "[" << j+1 << "]: ";
                        cin >> mat[i][j];
                }
        }
}

void display()
{
        cout << "The matrix is:";
        for (int i = 0; i < m; i++)
        {
                cout << endl;
                for (int j = 0; j < n; j++)
                {
                        cout << setw(8) << mat[i][j];
                }
        }
        cout << endl;
}

void pivotize() {

        double *temp;
        for (int i = 0; i < m-1; i++) {
                for (int j = i+1; j < m; j++) {
                        if (mat[i][0] < mat[j][0]) {
                                temp = mat[j];
                                mat[j] = mat[i];
                                mat[i] = temp;
                        }
                }
        }
}
void solve()
{
        double q;

        for (size_t i = 0; i < m; i++) {
                q = 0.0;
                for (size_t j = i+1; j < m; j++) {
                        q = (mat[j][i]) / (mat[i][i]);
                        for (size_t k = i; k < n; k++) {

                                std::cout << "Term Operated " << mat[j][k]
                                          << "\nNum           " << q * mat[i][i]
                                          << "\nDen           " << mat[i][i]
                                          << "\nFactor        " << q
                                          << endl << endl;

                                mat[j][k] = mat[j][k] - (q * mat[i][k]);

                        }
                }


                // CURRENTLY BROKEN
                //
                //   for (size_t i = m; i > 0; i--) {
                //     for (size_t j = i-1; j > 0; j--) {
                //       double p = (mat[j][i]) / (mat[i][i]);
                //       for (size_t k = i; k > 0; k--) {
                // mat[j][k] = mat[j][k] - (p * mat[i][k]);
                //     }
                //   }
                // }
        }
}

void back_solve() {

        double q = 0.0, Sol_Mat;
        for (int k = m-1; k >=0; k--) {
                for (size_t i = k-1; i < n; i++) {
                        q += mat[k][i] * mat[i][n];
                }
                Sol_Mat = mat[k][n-1] /* -q */;
                // cout << mat[m-1][n-1] << '\n';
                q = 0;
        }
        cout << "Solution:\n";
        for (int i = 0; i < m-1; i++)
                cout << Sol_Mat << endl;
}
};
