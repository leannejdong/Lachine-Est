#include "newton3d.hpp"

int main()
{

	// F
	auto F = [](const Eigen::VectorXd &V){ 
   		Eigen::VectorXd res; 
   		int n=4;
	    double alpha,q,kappa,T;
	    alpha=3e-9;
	    q=1.0;
	    kappa=1/16;
	    T=1.0;
		res << 0.2*V(0)-0.2*V(1)-3, 
			-0.2*V(0)+0.4*V(1)+alpha*(exp(q*V(1)/(n*kappa*T))-1)-0.2*V(2),
		    -0.2*V(1)+0.3*V(2);
		return res;
	};

	// jacobian of F
	auto DF= [] (const Eigen::VectorXd &V){
		Eigen::MatrixXd J;
		int n=4;
	    double alpha,q,kappa,T;
	    alpha=3e-9;
	    q=1.0;
	    kappa=1/16;
	    T=1.0;
		J << 0.2, -0.2, 0, 
		  	 -0.2, 0.4+(alpha*q)/(n*kappa*T)*exp(q*(V(1))/(n*kappa*T)), -0.2,
		  	 0, -0.2, 0.3;
	  	return J;
	};

	Eigen::Vector3d	V = {7.0, 14.0, 20.0}; // initial value
	double tol=1E-14;
	newton3d(V, tol, F, DF);

	std::cout << std::setprecision(17) << "solution = " << V << std::endl;
    std::cout << std::setprecision(17) << "error norm = " << F(V).norm() << std::endl;
}