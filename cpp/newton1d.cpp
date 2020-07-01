/**
 *@newton1d.cpp
 * Pre: eps>=0
 * Return v such that |v^2-a|<eps
 */

#include <cmath>
#include <iostream>

double square_root(double a)
{
    double v = 1.0; // makes an initial guess
    double eps;

    // Iterates using Newton-Raphson recurrence
    while (std::abs(v*v - a)>= eps)
    {
       v = 0.5*(v+a/v);
    }
    //std::cout << v << std::endl;
    return v;
}

int main()
{
    auto v = square_root(1024);
    std::cout << v << std::endl;
}


