#include <iostream>
#include <fstream>
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
	std::ifstream ifs("data.txt");
	if (ifs.fail()){
		std::cerr << "Errore nell'apertura del file" << std::endl;
		return 1;
	}
	std::string output="result.txt";
	std::ofstream ofs(output);
	if (!ofs){
		std::cerr << "Errore nell'apertura del file" << std::endl;
		return 1;
	}
	return 0;
	double point;
	double sum=0.0;
	double mean=0.0;
	unsigned int k=1;
	ofs << "# N Mean" << std::endl;
	while (ifs >> point)
	{
		sum += map_points(point);
		mean=sum/k;
		ofs << std::scientific << std::setprecision(16) << mean << std::endl;
		k++;
	}
	ifs.close();
	ofs.close();
	return 0;	
}
