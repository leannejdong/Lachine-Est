#include <iostream>
#include <Eigen/Dense>
 
using namespace std;
using namespace Eigen;
 
int main()
{
   Matrix3f A;
   Vector3f b;
   A << 0.2,-0.2,0,  -0.2,0.5,-0.2,  0,-0.2,0.3;
   b << 3, 0, 0;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;
   Vector3f x = A.colPivHouseholderQr().solve(b);
   cout << "The solution is:\n" << x << endl;
}