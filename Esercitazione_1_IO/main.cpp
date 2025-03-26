#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <numbers>

double map_points(double x){
		int a=1;
		int b=5;
		int c=-1;
		int d=2;
		double new_point=c+((d-c)/(b-a))*(x-a);
		return new_point;
	}
int main()
{
    std::string input="data.txt";
	std::ifstream inputfile(input);
	if (inputfile.fail())
	{
		std::cerr << "Errore nell'apertura del file" << std::endl;
		return 1;
	}
	std::string output='result.txt';
	std::ostream outputfile(output);
	if (!outputfile){
		std::cerr << "Errore nell'apertura del file" << std::endl;
		return 1;
	}
	return 0;
	double point;
	double sum=0.0;
	double mean=0.0;
	unsigned int k=1;
	ofs << "# N Mean" << std:endl;
	while (inputfile >> valore)
	{
		sum += map_points(point);
		mean=sum/k;
		outputfile << std::scientific << std::scientific(16) << mean << endl;
		k++;
	}
	inputfile.close();
	outputfile.close();
	return 0;	
}
