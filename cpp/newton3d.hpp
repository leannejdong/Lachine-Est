#include <iostream>
#include </usr/include/eigen3/Eigen/Dense>
#include <cmath>
#include <vector>

void newton3d()
{
	// F
	auto F = [](const Eigen::VectorXd &x){ 
   		Eigen::VectorXd res;
		res << 1.02*15.81*x(2)*cos(108.43-x(0))+68.01*pow(x(2),2)*cos(-72.90)+1.03*52.20*x(2)*cos(106.7-x(0)+x(1)),
		1.03*1.02*41.23*cos(104.04-x(1))+1.03*52.20*x(2)*cos(106.70-x(1)+x(0)),
		-1.03*15.81*x(2)*sin(108.43-x(0))-68.01*pow(x(2),2)*sin(-72.90)-1.03*52.20*x(2)*cos(106.7-x(0)+x(1));
		return res;
	};

	// jacobian of F
	auto DF= [] (const Eigen::VectorXd &x){
		Eigen::MatrixXd J;
		J << 1.02*15.81*x(2)*sin(108.43-x(0))+1.03*52.20*x(2)*sin(106.7-x(0)+x(1)), 
		-1.03*52.20*x(2)*sin(106.7-x(0)+x(1)), 
		1.02*15.81*cos(108.43-x(0))+2*68.01*x(2)*cos(-72.90)+1.03*52.2*cos(106.7-x(0)+x(1)),
		 -1.03*52.20*x(2)*sin(106.7-x(0)+x(1)),1.03*1.02*41.23*sin(104.04-x(1))+1.03*52.20*x(2)*sin(106.7-x(1)+x(0)),
		 1.03*1.02*41.23*sin(104.04-x(1))+1.03*52.20*x(2)*sin(106.7-x(1)+x(0)),1.03*52.20*cos(106.70-x(1)+x(0)),
		 1.02*15.81*x(2)*cos(108.43-x(0))+1.03*52.20*x(2)*cos(106.70-x(0)+x(1)), -1.03*52.20*x(2)*cos(106.70-x(0)+x(1)), 
		 -1.02*15.81*sin(108.43-x(0))-2*68.01*x(2)*sin(-72.90)-1.03*52.20*sin(106.7-x(0)+x(1));d
	  	return J;
	};	

	Eigen::VectorXd x, x_ast, s;
	x << 0, 0,1; // initial value
	x_ast << -1.6, -0.21, 1.02; // solution
   	double tol=1E-10;

	std::vector<double> errors;
	errors.push_back((x-x_ast).norm());

	/*this does not work*/
	// while (s.norm() > tol*x.norm())
	// 
	// 	s = DF(x).lu().solve(F(x));
	//    	x = x-s; // newton iteration
	// 	errors.push_back((x-x_ast).norm());
	// }


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
	
	std::cout << "Errors:" << std::endl;
	std::cout << err << std::endl;

	// compute the convergence rate of each iteration	
	Eigen::VectorXd logDiff = err.bottomRows(n-1).array().log() - err.topRows(n-1).array().log();
	Eigen::VectorXd rates = logDiff.bottomRows(n-2).cwiseQuotient(logDiff.topRows(n-2));
	
	std::cout << "Rates:" << std::endl;
	std::cout << rates << std::endl;
}
