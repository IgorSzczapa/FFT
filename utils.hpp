#pragma once

using complex = std::complex<double>;
using c_array = std::valarray<complex>;
using d_array = std::valarray<double>;	

d_array load_args (int argc, char* argv[])
{
	d_array data(argc-1);
	for (int k{1}; k < argc; ++k)
	{
		data[k-1] = std::stod(argv[k]);
	}
	return data;
}

template < typename type >
void print (const std::valarray<type>& X, std::string sep = "\n", std::ostream& os = std::cout)
{
	for (const auto& x : X) os << x << sep;
	os << std::endl;
}

template < typename type0, typename type1 >
void print (const std::valarray<type0>& X, const std::valarray<type1>& Y)
{
	for (int k{0}; k < X.size(); ++k) std::cout << X[k] << " : " << Y[k] << std::endl;
	std::cout << std::endl;
}