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
		double new_point=c+((d-c)/(b-a))*(x-a); // la formula per la traslazione dei punti di un intervallo [a,b] ad un intervallo [c,d] è x_new=c+((d-c)/(b-a))*(x-a)
		return new_point;
	}
int main()
{
	std::ifstream ifs("data.txt");
	if (ifs.fail()){ // controllo che il file di input si apra correttamente
		std::cerr << "Errore nell'apertura del file" << std::endl;
		return 1;
	}
	std::string output="result.txt"; //creo il file di output
	std::ofstream ofs(output);
	if (!ofs){ // controllo che il file di output si apra correttamente
		std::cerr << "Errore nell'apertura del file" << std::endl;
		return 1;
	}
	return 0;
	double point; // varibile ausiliaria in cui memorizzo i valori letti dal file
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
