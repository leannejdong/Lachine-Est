#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include <cmath>

#include </usr/include/eigen3/Eigen/Dense>



void newton3d(Eigen::VectorXd& V,
              double tolerance,
              std::function<Eigen::VectorXd(const Eigen::VectorXd&)> F,
              std::function<Eigen::MatrixXd(const Eigen::VectorXd&)> DF
              )

{
	Eigen::Vector3d V_prev, h;
	V << 7, 14, 20; // initial value
	
    std::vector<double> errors;
	errors.push_back((F(V)).norm());
	do	{
        V_prev = V;
		h = DF(V).lu().solve(F(V));
	  	V = V-h; // newton iteration
	} while (h.norm() > tolerance*V.norm());
}