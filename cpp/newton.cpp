#include <iostream>
#include <cmath>

double f1(double);
double f2(double,double);

using namespace std;

int main()
{
        double dx, dy,x=1.0, y=1.0,xnew,ynew,eps=0.0000001,err=1.0,m=1;
        if ( fabs(err) > eps ) //changed to an if statement so there isn't an infinite loop
        {
    dx= -f1(x)/(3.0*sin(x)+cos(x));
        dy= (f1(x)*sin(x)+f2(x,y)*(cos(x)-3*sin(x)))/3*sin(x)*(cos(y)+cos(x)*cos(y));

        xnew= x+dx;
        ynew= y+dy;

        m = (xnew-x)*(xnew-x)+(ynew-y)*(ynew-y);
        err=sqrt(m);
        }
        if ( fabs(err) < eps )
                cout<< "dx= " <<dx<<endl; //since fabs(err} > eps, this line doesn't print
            cout<< "dy= "<<dy<<endl;      //<-- this line still prints, since not part of the preceding if statement

return 0;
}

double f1(double x)
{
        return sin(x)+3.0*cos(x)-2.0;
}

double f2(double x, double y)
{
        return cos(x)-sin(y)+0.2;
}