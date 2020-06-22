#include <iostream>
#include </usr/include/eigen3/Eigen/Dense>
 
using namespace std;
using namespace Eigen;
 
int main()
{
   Matrix4f A;
   Vector4f b;
   A << 310,-200,-100,0, -200,320,0,-100,-100,0,310,-210, 0,-100,-210,330;
   b << 0, 0, 10,0;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;
   Vector4f x = A.colPivHouseholderQr().solve(b);
   cout << "The solution is:\n" << x << endl;
}