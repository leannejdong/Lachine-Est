#include </usr/include/eigen3/Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

//! \brief Compute F(u), where F is the map associated with the nonlinear circuit
//! \param[in] U VectorXd of size 3
//! \param[in] double alpha, q parameters
//! \param[in] double Uin, input voltage
//! \param[out] VectorXd, F(V)

VectorXd F(VectorXd V, double alpha, double q, double Vin)
{
    VectorXd f(3);
    double Vt=.025; // This is nkT
 //   f << 3*U(0)-U(1)-U(2), 3*U(1)-U(0)-U(2)-Uin, 3*U(2)-U(0)-U(1) + alpha*(exp(beta*(U(2)-Uin)/Ut)-1);
    f << 0.2*V(0)-0.2*V(1)-Vin, 0.4*V(1)-0.2*V(0)-0.3*V(2)+alpha*(exp(q*(V(1))/Vt)-1), -0.2*V(1)+0.3*V(2);
    return f;
}

//! \brief Compute the solution to the nonlinear system by using Newton's iteration
//! \param[in] double alpha, q parameters
//! \param[in] double Vin, input voltages
//! \param[out] VectorXd Vout, output voltages

void circuit(const double & alpha, const double & q, const VectorXd & Vin, VectorXd & Vout)
{
    double Vt=.025;
    int n=Vin.size();
    cout << "Input vol size are " << endl << n <<endl;
    MatrixXd J(3,3);
    VectorXd f(3);
    for (int i=0;i<n;i++){
        srand((unsigned int) time(0));
        VectorXd V=VectorXd::Random(3);
        VectorXd h=VectorXd::Ones(3);
        while (h.cwiseAbs().maxCoeff()>1e-6*V.norm()){
            J << 0.2, -0.2, 0, -0.2, 0.4+(alpha*q)/Vt*exp(q*(V(1))/Vt), -0.3, 0, -0.2, 0.3;
            f=F(V,alpha,q,Vin(i));
            h=J.partialPivLu().solve(f);
            V=V-h;
        }
        Vout(i)=V(0);
            // Check correctedness
        cout<<"Error: "<<F(V,alpha,q,Vin(i)).norm()<<endl;
    }
}


int main(){
    //Test the above function with the input Vin
    int n=4;
    double alpha,q;
    alpha=1.0;
    q=1.0;
    
    VectorXd Vin=VectorXd::LinSpaced(n,0,4);
    cout << "The voltage inputs are " << endl << Vin <<endl;
    VectorXd Vout(n);
    circuit(alpha,q,Vin,Vout);
    
    //Display the solutions
    cout<<"The solutions are"<<endl<<Vout<<endl;
    
    // Display the differences of the solutions: the nonlinear effect can be seen from the fact that the vector is not constant.
    VectorXd diff(n-1);
    for (int i=0; i<n-1;i++) {
        diff(i)=Vout(i+1)-Vout(i);
    }
    cout<<"The differences are"<<endl<<diff<<endl;
}
