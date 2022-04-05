#include <iostream>
#include <complex>
#include <valarray>
#include <cmath>
#include <fstream>
#include "utils.hpp"
#include "math.hpp"

using complex = std::complex<double>;
using c_array = std::valarray<complex>;
using d_array = std::valarray<double>;

complex complex_cast (double d)
{
	return complex{d};
}

void recursive_fft (c_array& X, const c_array& omega)
{
	const size_t n = X.size();
	if (n <= 1) return;

	c_array even = X[std::slice(0,n/2,2)];
	c_array odd  = X[std::slice(1,n/2,2)];

	recursive_fft(even,omega[std::slice(0,n/2,2)]);
	recursive_fft(odd ,omega[std::slice(0,n/2,2)]);
	
	for (int k{0}; k < n/2; ++k)
	{
		complex t = omega[k] * odd[k];
		X[k    ] = even[k] + t;
		X[k+n/2] = even[k] - t;
	}
}

d_array fft (d_array X)
{
	c_array Y{transform<complex>(X,complex_cast)};
	recursive_fft(Y,omega(Y.size()));
	return transform<double>(Y,r);
}

// c_array ifft (const c_array& X)
// {
//	return fft(X.apply(std::conj)).apply(std::conj);// * X.size();
// }

int main (int argc, char* argv[])
{
	d_array data(load_args(argc,argv));
	std::ofstream file("data.txt");
	print(fft(data),"\n",file);
	print(fft(data));
}