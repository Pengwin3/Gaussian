#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

using namespace std;

class matrix
{
private:
int m, n;
double **mat,
**Original_Mat,
*Sol_Mat,
*RHS,
*LHS;

public:

matrix(int row, int col)
{
        m = row;
        n = col;
        mat = new (double *);
        Sol_Mat = new (double);
        RHS = new (double);
        LHS = new (double);
        Original_Mat = new (double *);

        for (int i = 0; i < m; i++) {
                mat[i] = new double[n];
                Original_Mat[i] = new double[n];
        }
}

~matrix(){
}

void fill()
{
        int i=0, j=0;

        for ( i; i < m; i++)
                for ( j = 0; j < m; j++)
                        cin >> mat[i][j];

        for ( i = 0; i < n; i++)
                cin >> mat[i][n-1];

        for ( i = 0; i < m; i++)
                for ( j = 0; j < n; j++)
                        Original_Mat[i][j] = mat[i][j];

        for ( i = 0; i < m; i++)
                LHS[i] = mat[i][n-1];
}

void display()
{
        cout << "The matrix is: \n";
        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        formatTable(i,j);
                        cout << setw(8) << mat[i][j];
                }

                cout << endl;
        }
        cout << endl;
}

void formatTable(int i, int j) {
        if (i==0 & j==0)
                cout << "「";
        if (i==0 && j==n-1)
                cout << "˥ ";
        if (i==m-1 && j==n-1)
                cout << "」";
        if (i==m-1 && j==0)
                cout << " ˪";
}

void pivotize() {

        double *temp;
        for (int i = 0; i < m-1; i++)
                for (int j = i+1; j < m; j++)
                        if (mat[i][0] < mat[j][0])
                        {
                                temp = mat[j];
                                mat[j] = mat[i];
                                mat[i] = temp;
                        }
}
void solve()
{
        double q;

        for (size_t i = 0; i < m; i++) {
                q = 0.0;
                for (size_t j = i+1; j < m; j++) {
                        q = (mat[j][i]) / (mat[i][i]);
                        for (size_t k = i; k < n; k++)
                                mat[j][k] = mat[j][k] - (q * mat[i][k]);
                }
        }
        for (size_t i = 0; i < m; i++)
                if (mat[i][i] < 1) {
                        q = mat[i][i];
                        for (size_t j = i; j < n; ++j)
                                mat[i][j] = mat[i][j] / q;
                }
}


void back_solve() {

        double p = 0.0;
        for (int k = m-1; k >= 0; --k) {
                if (k == m-1)
                        Sol_Mat[k] = mat[k][n-1] / mat[k][k];

                else {
                        for (size_t i = k+1; i < m; i++)
                                p += mat[k][i] * Sol_Mat[i];

                        Sol_Mat[k] = (mat[k][n-1] - p) / mat[k][k];
                        p = 0.0;
                }
        }
        cout << "Solution:\n";
        for (size_t i = 0; i < m; i++)
                cout << "X" << i << " = " << Sol_Mat[i] << endl;
}

void errorCheck()
{
        double q;

        for (int i = 0; i < n-1; i++) {
                q = 0.0;
                for(int j = 0; j < n-1; j++)
                        q += Original_Mat[i][j] * Sol_Mat[j];

                RHS[i] = q;
        }
        cout << endl
             << "Calculated Solutions"
             << endl;
        for (size_t i = 0; i < n-1; i++)
                cout << RHS[i] << endl;

        q = 0.0;
        for ( int i = 0; i < n-1; i++)
                q += (LHS[i]-RHS[i]) * (LHS[i]-RHS[i]);
                
        cout << sqrt(q) / n;
}
};
