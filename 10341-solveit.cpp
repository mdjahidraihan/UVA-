#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

#define eps .0000001
double p,q,r,s,t,u;

double f(double x)
{
	double d = p*exp((-1)*x)+q*sin(x)+ r*cos(x) + s*tan(x) +( t*x*x) + u ;
	return d;
}
int main()
{
	int T;
	while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6)
	{
		double low=0,high=1.0;

		if(f(low)*f(high)>0||f(high)>eps)
		{
			printf("No solution\n");
		}
		else
		{
			while(true)
			{
				double mid = (high+low)/2.0;
				double d = f(mid);
				if(fabs(d)<eps)
				{
					printf("%.4lf\n",mid);
					break;
				}
				else if(d>0)
					low=mid;
				else high = mid;
			}
		}
			
	}
	return 0;
}