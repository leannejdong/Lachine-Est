#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include <cmath>

#include <eigen3/Eigen/Dense>


template<class VectorT, class Fn1T, class Fn2T>
void newton3d(VectorT& V,
              double tolerance,
              Fn1T F,
              Fn2T DF
              )

{
	VectorT V_prev, h;
	V << 7, 14, 20; // initial value
	
    std::vector<double> errors;
	errors.push_back((F(V)).norm());
	do	{
        V_prev = V;
		h = DF(V).lu().solve(F(V));
	  	V = V-h; // newton iteration
	} while (h.norm() > tolerance*V.norm());
}