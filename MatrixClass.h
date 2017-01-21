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
        // cout << "Enter matrix elements for:\n";
        for ( i; i < m; i++)
        {
                for ( j =0; j < n; j++)
                {
                        // cout << "[" << i+1 << "] "
                        //      << "[" << j+1 << "]: ";
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

                                // Diagnostic
                                // std::cout << "Term Operated " << mat[j][k]
                                //           << "\nNum           " << q * mat[i][i]
                                //           << "\nDen           " << mat[i][i]
                                //           << "\nFactor        " << q
                                //           << endl << endl;

                                mat[j][k] = mat[j][k] - (q * mat[i][k]);

                        }
                }
        }
        for (size_t i = 0; i < m; i++) {
                if (mat[i][i] < 1) {
                        q = mat[i][i];
                        for (size_t j = i; j < n; ++j) {
                                mat[i][j] = mat[i][j] / q;

                        }
                }
        }
}

void back_solve() {

        double p = 0.0, Sol_Mat[n-1];
        for (int k = m-1; k >= 0; --k) {
                if (k == m-1) {
                        Sol_Mat[k] = mat[k][n-1] / mat[k][k];
                }
                else {
                        for (size_t i = k+1; i < m; i++) {
                                p += mat[k][i] * Sol_Mat[i];
                        }
                        Sol_Mat[k] = (mat[k][n-1] - p) / mat[k][k];
                        p = 0.0;
                }
        }
        cout << "Solution:\n";
        for (size_t i = 0; i < m; i++)
                cout << "X" << i << "= " << Sol_Mat[i] << endl;
}
};
