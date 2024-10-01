// Лабораторна робота № 5.2
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;

    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(18) << "ln((1+x)/(1-x))" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(18) << setprecision(10) << log((1 + x) / (1 - x)) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}


void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = 2 * x;
    s = a;
    do {
        n++;
        A(x, n, a);
        s += 2;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    double R =  (2 * n - 1) * pow(x, 2) / (2 * n + 1);
    a *= R;
}


