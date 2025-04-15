#include "Utils.hpp"
#include "iomanip"
#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
using namespace std;
// lettura e importo dei valori forniti dal file di imput
bool ImportVectors(const string& inputFilePath,
                   double& S,
				   size_t& n,
                   double*& w,
                   double*& r)
{
	ifstream file(inputFilePath);
	if (file.fail())
	{
		cerr << "Errore nell'apertura del file" << endl;
		return false;
	}
	string riga;
	char lettera;
	char separatore;
	// lettura di S
	getline(file,riga);
	stringstream string1(riga);
	string1 >> lettera >> separatore >> S;
	// lettura di n
	getline(file,riga);
	stringstream string2(riga);
	string2 >> lettera >> separatore >> n;
	// controllo del valore di n
	if (n==0){
		cerr << "il valore di n è 0" << endl;
		return 1;
	}
	string tmp; //salto la riga
	getline(file,tmp); //leggo e non salvo la riga
	string line;
	w=new double[n];
	r=new double[n];
	for (unsigned int i=0; i<n; i++) {
		getline(file,line);
		stringstream riga(line);
		char separatore;
		riga >> w[i];
		riga >> separatore;
		riga >> r[i];
	}
	return true;
}
double DotProduct(const size_t& n,
                        const double* const& w,
                        const double* const& r)
{
	double prod=0.0;
	for (unsigned int i=0; i<n; i++){
		prod+=w[i]*r[i];
	}
	return prod;	
}
double ValuePortfolio(const size_t& n,
                  const double& S,
				  const double* const& w,
                  const double* const& r)
{
	double V=0.0;
	for (unsigned int i=0; i<n; i++) {
		V+=w[i]*(1+r[i]);
	}
	V=V*S;
	return V;
}					  
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
				  const double& S,
                  const double* const& w,
                  const double* const& r,
				  const double& prod,
                  const double& V)	
{
	ofstream outputFile(outputFilePath);
	if (outputFile.fail())
	{
		cerr << "Errore nell'apertura del file" << endl;
		return false;
	}
	outputFile << scientific << setprecision(2) << fixed << "S = " << S << ", n = " << n << endl; //output prima riga
	//output w
	outputFile << "w = [ ";
	for (unsigned int i=0; i<n; i++){
		outputFile << w[i] << " ";
	}
	outputFile << "]" << endl;
	//output r
	outputFile << "r = [ ";
	for (unsigned int i=0; i<n; i++){
		outputFile << r[i] << " ";
	}
	outputFile << "]" << endl;
	outputFile << scientific << setprecision(4) << fixed << "Rate of return of the portfolio: " << prod << endl;
	outputFile << scientific << setprecision(2) << fixed << "V: " << V << endl;
	return true;
}