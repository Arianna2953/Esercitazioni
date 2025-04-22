#include <iostream>
#include "PolygonalMesh.hpp"
#include "Utils.hpp"
#include "UCDUtilities.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;

int main()
{
	PolygonalMesh mesh;

    if(!ImportMesh(mesh))
    {
        cerr << "file not found" << endl;
        return 1;
    }
	
	// verifica che tutti i marker siano ben memorizzati
	map<unsigned int, list<unsigned int>>&m0Dsmaker=mesh.MarkerCell0Ds;
	map<unsigned int, list<unsigned int>>&m1Dsmaker=mesh.MarkerCell1Ds;
	map<unsigned int, list<unsigned int>>&m2Dsmaker=mesh.MarkerCell2Ds;
	
	for (auto&[marker,listid]: m0Dsmaker)
	{
		cout << "Marker0D: " << marker << "IDs = [";
		for (auto& id : listid)
			cout << " " << id;
		cout << " ]" << endl;
	}
	
	cout << endl;
	for (auto&[marker,listid]: m1Dsmaker)
	{
		cout << "Marker1D: " << marker << "IDs = [";
		for (auto& id : listid)
			cout << " " << id;
		cout << " ]" << endl;
	}
	
	cout << endl;
	for (auto&[marker,listid]: m2Dsmaker)
	{
		cout << "Marker2D: " << marker << "IDs = [";
		for (auto& id : listid)
			cout << " " << id;
		cout << " ]" << endl;
	}
	// verifica che la mesh che ho memorizzato sia equivalente a quella di input (così da poter esporatre la maeh memorizzata e usare paraview)
	Gedim::UCDUtilities utilities;
	utilities.ExportPoints("./Cell0Ds.inp",mesh.Cell0DsCoordinates);
	utilities.ExportSegments("./Cell1Ds.inp",mesh.Cell0DsCoordinates,mesh.Cell1DsExtrema);
	
    return 0;
}
