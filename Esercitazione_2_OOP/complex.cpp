#include <iostream>
#include "complex.hpp"
int main(){
	complex_number<double> c1; // costruttore di default
	std::cout << "c1:" << c1 << std::endl;
	complex_number<double> c2(1.0,2.0);
	std::cout << "c2:" << c2 << std::endl;
	complex_number<double> c3(1.0,-2.0);
	std::cout << "c3:" << c3 << std::endl;
	std::cout << "coniugato di c2:" << c2.coniugate() << std::endl;
	//std::cout << 'coniugato di c3:' << c3.coniugate() << std::endl;
	std::cout << "parte reale di c2:" << c2.real_part() << std::endl;
	std::cout << "parte immaginaria di c2:" << c2.imag_part() << std::endl;
	complex_number<double> c4=c2+c3;
	std::cout << "c2+c3:" << c4 << std::endl; // somma tra due complessi con l'operatore +
	c2+=c3;
	std::cout << "c2+=c3:" << c2 << std::endl; // somma tra due complessi con l'operatore +=
	complex_number<double> c5=c2*c3;
	std::cout << "c2*c3:" << c5 << std::endl; // prodotto tra due complessi con l'operatore *
	c2*=c3;
	std::cout << "c2*=c3:" << c2 << std::endl; // prodotto tra due complessi con l'operatore *=
	double k=2;
	complex_number<double> c(2.5,3.2);
	std::cout << "k:" << k << std::endl;
	std::cout << "c:" << c << std::endl;
	complex_number<double> c6=c+k; // somma tra un complesso e uno scalare con l'operatore +
	std::cout << "c6:" << c6 << std::endl;
	complex_number<double> c7=c*k; // prodotto tra un complesso e uno scalare con l'operatore *
	std::cout << "c7:" << c7 << std::endl;
	complex_number<double> c8=k+c; // somma tra uno scalare e un complesso con l'operatore +
	std::cout << "c8:" << c8 << std::endl;
	complex_number<double> c9=k*c; // prodotto tra uno scalare e un complesso con l'operatore *
	std::cout << "c9:" << c9 << std::endl;
	return 0;
}