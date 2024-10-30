#include <iostream>
#include <cmath>

using namespace std;

double eq1(double x) 
{
    return pow(x, 3) + 1.6 * x - 7.2;
}

double eq2(double x)
{
    return pow(x, 2) - (x * M_PI / (3 * tan(x)));
}

void dichotomy1(double &a, double &b, double eps) 
{
    double c;
    int itr = 0; 
    while (abs(b - a) > eps) 
    {
        c = (a + b) / 2;
        if ((eq1(a)) * (eq1(c)) < 0) 
        {
            b = c;
        } 

        else 
        {
            a = c;
        }
        itr++;
    } 

    cout << endl << "c = " << (a + b) / 2 << endl;
    cout << "dx = " << (b - a) / 2 << endl;
    cout << "F(c) = " << eq1((a+b)/2) << endl;
    cout << "Amount of iterations: " << itr << endl;
}

void dichotomy2(double &a, double &b, double eps) 
{
    double c;
    int itr = 0; 
    while (abs(b - a) > eps) 
    {
        c = (a + b) / 2;
        if ((eq2(a)) * (eq2(c)) < 0) 
        {
            b = c;
        } 

        else 
        {
            a = c;
        }
        itr++;
    } 

    cout << "c = " << (a + b) / 2 << endl;
    cout << "dx = " << (b - a) / 2 << endl;
    cout << "F(c) = " << eq2((a+b)/2) << endl;
    cout << "Amount of iterations: " << itr << endl;
}

void simpleiterations1 (double &x, double eps)
{
    double xnext;
    int itr = 0;
    xnext = pow((7.2 - 1.6 * x), 1.0/3.0);
    while (abs(x - xnext) > eps)
    {
        x = xnext;
        xnext = pow((7.2 - 1.6 * x), 1.0/3.0);
        itr++;
    }
    
    cout << "x = " << xnext << endl;
    cout << "Amount of iterations: " << itr;
}

void simpleiterations2 (double &x, double eps)
{
    double xnext;
    int itr = 0;
    xnext = pow(((M_PI * x) / (3 * tan(x))), 1.0/2.0);
    while (abs(x - xnext) > eps)
    {
        x = xnext;
        xnext = pow(((M_PI * x) / (3 * tan(x))), 1.0/2.0);
        itr++;
    }
    
    cout << "x = " << xnext << endl;
    cout << "Amount of iterations: " << itr;
}

void newton1 (double &x, double eps)
{
    double xnext;
    int itr = 0;
    xnext = x - (pow(x, 3) + 1.6 * x - 7.2) / (3 * pow(x, 2) + 1.6);
    while (abs(x - xnext) > eps)
    {
        x = xnext;
        xnext = x - (pow(x, 3) + 1.6 * x - 7.2) / (3 * pow(x, 2) + 1.6);
        itr++;
    }

    cout << "x = " << xnext << endl;
    cout << "Amount of iterations: " << itr;
}

void newton2 (double &x, double eps)
{
    double xnext;
    int itr = 0;
    xnext = x - (pow(x, 2) - (M_PI * x) / (3 * tan(x))) / ((12 * x * sin(x) * sin (x) - M_PI * sin (2 * x) + 2 * M_PI * x) / 6 * sin(x) * sin (x));
    while (abs(x - xnext) > eps)
    {
        x = xnext;
        xnext = x - (pow(x, 2) - (M_PI * x) / (3 * tan(x))) / ((12 * x * sin(x) * sin (x) - M_PI * sin (2 * x) + 2 * M_PI * x) / 6 * sin(x) * sin (x));
        itr++;
    }

    cout << "x = " << xnext << endl;
    cout << "Amount of iterations: " << itr;
}

void chord1 (double &a, double &b, double eps)
{
    double fa;
    double fb;
    double c;
    fa = eq1(a);
    fb = eq1(b);
    int itr = 0;
    if ((fa * fb) > 0)
    {
        cout << "Error!";
    }

    else 
    {
        while (abs(b - a) > eps)
        {
            c = a - (b - a) * fa / (fb - fa);
            double fc;
            fc = eq1(c);
            if ((fa * fc) > 0)
            {
                a = c;
                fa = fc;
            }
            else 
            {
                b = c;
                fb = fc;
            }
            itr++;
        }
    }
    cout << endl << "c = " << c << endl;
    cout << "dx = " << (b - a) / 2 << endl;
    cout << "F(c) = " << eq1(c) << endl;
    cout << "Amount of iterations: " << itr << endl;
}

void chord2 (double &a, double &b, double eps)
{
    double fa;
    double fb;
    double c;
    fa = eq2(a);
    fb = eq2(b);
    int itr = 0;
    if ((fa * fb) > 0)
    {
        cout << "Error!";
    }

    else 
    {
        while (abs(b - a) > eps)
        {
            c = a - (b - a) * fa / (fb - fa);
            double fc;
            fc = eq2(c);
            if ((fa * fc) > 0)
            {
                a = c;
                fa = fc;
            }
            else 
            {
                b = c;
                fb = fc;
            }
            itr++;
        }
    }
    cout << endl << "c = " << c << endl;
    cout << "dx = " << (b - a) / 2 << endl;
    cout << "F(c) = " << eq2(c) << endl;
    cout << "Amount of iterations: " << itr << endl;
}

int main()
{
    int choice;
    double eps = 0.0005;
    cout << "---Equations---" << endl;
    cout << "1: x^3 + 1,6x - 7,2 = 0" << endl;
    cout << "2: x^2 - ctg(x) * 1/3 * pi * x = 0" << endl;
    cout << "Choose equation to solve: ";
    cin >> choice;


    int choice1;
    cout << endl << "---Methods---" << endl;
    cout << "1 - The dichotomy method" << endl;
    cout << "2 - The simple iteration method" << endl;
    cout << "3 - The Newton's method" << endl;
    cout << "4 - The chord method" << endl;
    cout << "Choose method you would like to use: ";
    cin >> choice1;

    if (choice == 1)
    {
        if (choice1 == 1)
        {
            double a, b;
            cout << endl << "Enter a: ";
            cin >> a;
            cout << "Enter b: ";
            cin >> b;

            dichotomy1(a, b, eps);
        }

        else if (choice1 == 2)
        {
            double x;
            cout << endl << "Enter initial approximation: ";
            cin >> x;

            simpleiterations1(x, eps);
        }

        else if (choice1 == 3)
        {
            double x;
            cout << endl << "Enter initial approximation: ";
            cin >> x;

            newton1(x, eps);
        }

        else if (choice1 == 4)
        {
            double a, b;
            cout << endl << "Enter a: ";
            cin >> a;
            cout << "Enter b: ";
            cin >> b;

            chord1(a, b, eps);
        }
    }

    if (choice == 2)
    {
         if (choice1 == 1)
        {
            double a, b;
            cout << endl << "Enter a: ";
            cin >> a;
            cout << "Enter b: ";
            cin >> b;

            dichotomy2(a, b, eps);
        }

        else if (choice1 == 2)
        {
            double x;
            cout << endl << "Enter initial approximation: ";
            cin >> x;

            simpleiterations2(x, eps);
        }

        else if (choice1 == 3)
        {
            double x;
            cout << endl << "Enter initial approximation: ";
            cin >> x;

            newton2(x, eps);
        }

        else if (choice1 == 4)
        {
            double a, b;
            cout << endl << "Enter a: ";
            cin >> a;
            cout << "Enter b: ";
            cin >> b;

            chord2(a, b, eps);
        }
    }
    return 0;
}