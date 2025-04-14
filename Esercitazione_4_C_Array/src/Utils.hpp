#pragma once
#include <iostream>
using namespace std;
// lettura file di input
bool ImportVectors(const string& inputFilePath,
                   double& S,
				   size_t& n,
                   double*& w,
                   double*& r);
// calcolo del tasso di rendimento dei dati forniti
double DotProduct(const size_t& n,
                  const double* const& w,
                  const double* const& r);
// calcolo del valore del portfolio
double ValuePortfolio(const size_t& n,
                  const double& S,
				  const double* const& w,
                  const double* const& r);
// calcolo dei dati da esportare sul file di output
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
				  const double& S,
                  const double* const& w,
                  const double* const& r,
				  const double& prod,
                  const double& V);