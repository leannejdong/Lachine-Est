#include <iostream>
#include </usr/include/eigen3/Eigen/Dense>
#include <cmath>
#include <vector>

void newton2d()
{
	// F
	auto F = [](const Eigen::Vector2d &x){ 
   		Eigen::Vector2d res;
		res << pow(x(0),2) -2*x(0)-x(1)+0.5, pow(x(0),2) +4*pow(x(1),2)-x(1)-4;
		return res;
	};

	// jacobian of F
	auto DF= [] (const Eigen::Vector2d &x){
		Eigen::Matrix2d J;
		J << 2*x(0)-2	, -1, 
		  	 2*x(0)		, 8*x(1);
	  	return J;
	};	

	Eigen::Vector2d x, x_ast, s;
	x << 2, 0.25; // initial value
	x_ast << 1.9007, 0.3112; // solution
   	double tol=1E-10;

	std::vector<double> errors;
	errors.push_back((x-x_ast).norm());


	do
	{
		s = DF(x).lu().solve(F(x));
	   	x = x-s; // newton iteration
		errors.push_back((x-x_ast).norm());
	}
	while (s.norm() > tol*x.norm());

	// create eigen vector from std::vector
	unsigned int n = errors.size();
	Eigen::Map<Eigen::VectorXd> err(errors.data(), n);

	std::cout << "solution" << std::endl;
	std::cout << x << std::endl;
	
	std::cout << "Errors:" << std::endl;
	std::cout << err << std::endl;

	// compute the convergence rate of each iteration	
	Eigen::VectorXd logDiff = err.bottomRows(n-1).array().log() - err.topRows(n-1).array().log();
	Eigen::VectorXd rates = logDiff.bottomRows(n-2).cwiseQuotient(logDiff.topRows(n-2));
	
	std::cout << "Rates:" << std::endl;
	std::cout << rates << std::endl;
}
