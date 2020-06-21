#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

void newton2d(Eigen::Vector2d& x,
			 double tol, 
			 std::function<Eigen::Vector2d(const Eigen::Vector2d&)> F,
			 std::function<Eigen::Matrix2d(const Eigen::Vector2d&)> DF
			 )
{
	Eigen::Vector2d x_prev, s;
	x << 2, 0.25; // initial value

	std::vector<double> errors;
	errors.push_back((F(x)).norm());
	do
	{
		s = DF(x).lu().solve(F(x));
	   	x = x-s; // newton iteration
	//	errors.push_back((x-x_ast).norm());
	}
	while (s.norm() > tol*x.norm());
}
