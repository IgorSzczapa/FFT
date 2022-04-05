#pragma once

using complex = std::complex<double>;
using c_array = std::valarray<complex>;
using d_array = std::valarray<double>;

template < typename res_type, typename arg_type, typename fn >
std::valarray<res_type> transform (const std::valarray<arg_type>& X, fn f)
{
	std::valarray<res_type> Y(X.size());
	for (int k{0}; k < X.size(); ++k)
	{
		Y[k] = f(X[k]);
	}
	return Y;
}

double r (complex c)
{
	return std::sqrt(c.real()*c.real() + c.imag()*c.imag());
}

c_array omega (size_t n)
{
	const double w = 2*M_PI/n;
	c_array result(n);
	for (int k{0}; k < n; ++k)
	{
		result[k] = std::polar(1.0,-w*k);
	}
	return result;
}