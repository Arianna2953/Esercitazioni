#pragma once
#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

namespace PolygonalLibrary {

struct PolygonalMesh
{
    unsigned int NumCell0Ds = 0; // numero di Cell0D
    vector<unsigned int> Cell0DsId = {}; // id vertici, (1 x NumberCell0D)
    MatrixXd Cell0DsCoordinates = {}; // coordinate dei punti, (2 x NumberCell0D (x,y))
    map<unsigned int, list<unsigned int>> MarkerCell0Ds = {}; // Cell0D markers

    unsigned int NumCell1Ds = 0; // numero di Cell1D
    vector<unsigned int> Cell1DsId = {}; // id lati, (1 x NumberCell1D)
    MatrixXi Cell1DsExtrema = {}; // estremi dei lati, (2 x NumberCell1D (fromId,toId))
    map<unsigned int, list<unsigned int>> MarkerCell1Ds = {}; // Cell1D markers

    unsigned int NumCell2Ds = 0; // numero di Cell2D
    vector<unsigned int> Cell2DsId = {}; // id poligoni, (1 x NumberCell2D)
    vector<vector<unsigned int>> Cell2DsVertices = {}; // id vertici del poligono, (1 x NumberCell2DVertices[NumberCell2D])
    vector<vector<unsigned int>> Cell2DsEdges = {}; // id lati del poligono, (1 x NumberCell2DEdges[NumberCell2D])
	map<unsigned int, list<unsigned int>> MarkerCell2Ds = {}; // Cell2D markers
};
}
