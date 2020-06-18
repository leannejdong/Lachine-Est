#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include <cmath>

#include </usr/include/eigen3/Eigen/Dense>

void newton3d(Eigen::VectorXd& x,
              double tolerance,
              std::function<Eigen::VectorXd(const Eigen::VectorXd&)> F,
              std::function<Eigen::MatrixXd(const Eigen::VectorXd&)> DF
              )

{
	Eigen::VectorXd x_prev, s;
	
    std::vector<double> errors;
	errors.push_back((F(x)).norm());
	do	{
        x_prev = x;
		s = DF(x).lu().solve(F(x));
	  	x = x-s; // newton iteration
	} while (s.norm() > tolerance*x.norm());
}

int main()
{
    // F
    auto F = [](const Eigen::VectorXd &x){ 
   		Eigen::VectorXd res(3);
        res << 0.2*x(0)-0.2*x(1)-3, 
        0.4*x(1)-0.2*x(0)-0.3*x(2)+3e-9*(exp(4*x(1)-1)), 
        -0.2*x(1)+0.3*x(2);
        return res;
	};
	// jacobian of F
	auto DF= [] (const Eigen::VectorXd &x){
    	Eigen::MatrixXd J(3,3);
		J << 0.2, -0.2, 0,
		  	 -0.2, 0.4 + 4*3e-9*exp(4*x(1)), -0.3,
               0, -0.2, 0.3;
	  	return J;
	};	

    Eigen::VectorXd x(3);
	x << 15.0, 6.0, 5.0; // initial value
    double tolerance = 1e-14;
	newton3d(x, tolerance, F, DF);
    
    std::cout << std::setprecision(17) << "solution = " << x << std::endl;
    std::cout << std::setprecision(17) << "error norm = " << F(x).norm() << std::endl;
}
