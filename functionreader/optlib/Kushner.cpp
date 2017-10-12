#include <cstdlib>
#include <vector>
#include <cmath>
#include <time.h>

#include "../fparser452/fparser.hh"

double R_k(double r, double z_min, double a, double b, double c, double d){
	return -4 * (z_min - r - c) * (z_min - r - d) / (b - a);
}

double kushner(FunctionParser f, double a, double b, double epsilon, int &n){
	std::vector<double> x(2), z(2);
	double r = 0.5; // parametr?
	x[0] = a;
	x[1] = b;
	double *tmp = new double;
	*tmp = a;
	z[0] = f.Eval(tmp);
	*tmp = b;
	z[1] = f.Eval(tmp);
	double z_min = z[1];
	if (z[0] < z[1])
		z_min = z[0];
	int t = 1, k = 2;
	double x_new = 0;
	while (x[t] - x[t - 1] > epsilon){
		double R_max = R_k(r, z_min, x[0], x[1], z[0], z[1]);
		t = 1;
		for (int i = 2; i < k; i++){
			double R_buf = R_k(r, z_min, x[i - 1], x[i], z[i - 1], z[i]);
			if (R_buf > R_max){
				R_max = R_buf;
				t = i;
			}
		}
		x_new = x[t-1] + (x[t] - x[t-1])*(z_min - r  - z[t-1])/
							(2 * (z_min - r) - z[t] - z[t-1]);
		*tmp = x_new;
		double z_new = f.Eval(tmp);
		if (z_new < z_min)
			z_min = z_new;
		if (x_new > x[k - 1]){
			x.push_back(x_new);
			z.push_back(z_new);
		}
		else{
			std::vector <double>::iterator it_x, it_z;
			it_x = x.begin();
			it_z = z.begin();
			for (int i = 0; i < k; i++){
				if (x_new < x[i]){
					x.insert(it_x, x_new);
					z.insert(it_z, z_new);
					break;
				}
				else{
					it_x++;
					it_z++;
				}
			}
		}
		k = k + 1;
	}
	n = k;
	return x_new;
}
