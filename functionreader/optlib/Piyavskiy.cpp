#include <cstdlib>
#include <vector>
#include <cmath>

#include "fparser.hh"

double get_m_p(double M, double r){
	if (M < 0.0000001)
		return 1;
	else
		return r*M;
}

double R_p(double m, double a, double b, double c, double d){
	return 0.5 * m * (b - a) - 0.5 * (c + d);
}

double piyavskiy(FunctionParser f, double a, double b, double r, double epsilon, int &n){
	std::vector<double> x(2), z(2);
	x[0] = a;
	x[1] = b;
	double *tmp = new double;
	*tmp = a;
	z[0] = f.Eval(tmp);
	*tmp = b;
	z[1] = f.Eval(tmp);
	int t = 1, k = 2;
	double M = fabs((z[1] - z[0]) / (x[1] - x[0]));
	double x_new = 0;
	while (x[t] - x[t - 1] > epsilon){
		for (int i = 1; i < k; i++){
			double M_buf = fabs((z[i] - z[i - 1]) / (x[i] - x[i - 1]));
			if (M_buf > M)
				M = M_buf;
		}
		double m = get_m_p(M, r);
		double R_max = R_p(m, x[0], x[1], z[0], z[1]);
		t = 1;
		for (int i = 2; i < k; i++){
			double R_buf = R_p(m, x[i - 1], x[i], z[i - 1], z[i]);
			if (R_buf > R_max){
				R_max = R_buf;
				t = i;
			}
		}
		x_new = (x[t] + x[t - 1]) / 2 - (z[t] - z[t - 1]) / 2 / m;
		*tmp = x_new;
		double z_new = f.Eval(tmp);
		if (x_new >= x[k - 1]){
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
