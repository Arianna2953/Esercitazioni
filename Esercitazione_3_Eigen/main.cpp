#include "Eigen/Eigen"
#include <iostream>
#include <iomanip>


using namespace std;
using namespace Eigen;

VectorXd solve_QR(const MatrixXd &A, const VectorXd &b) { 
	VectorXd x_qr=A.householderQr().solve(b);
	return x_qr;
}
VectorXd solve_PALU(const MatrixXd &A, const VectorXd &b) {
	VectorXd x_palu=A.partialPivLu().solve(b);
	return x_palu;
}
double err_rel(const VectorXd &x_sol, const VectorXd &x_esatta) {
	return (x_sol-x_esatta).norm()/x_esatta.norm();	
}

int main()
{ 	
	Vector2d x_esatta(-1.0e+00, -1.0e+00);
	double epsilon=10e-15;
	double err_PALU, err_QR;
	
	Matrix2d A1 {
      {5.547001962252291e-01, -3.770900990025203e-02},
      {8.320502943378437e-01, -9.992887623566787e-01},
	  };
	Vector2d b1(-5.169911863249772e-01, 1.672384680188350e-01);
	if (abs(A1.determinant())<epsilon){
		cout << "la matrice è singolare" << endl;
	}else{
		cout << "la soluzione della matrice A1 con il sistema QR è:" << scientific << setprecision(15) << solve_QR(A1,b1) << endl;
		err_QR=err_rel(solve_QR(A1,b1),x_esatta);
		cout << "l'errore relativo tra la soluzione esatta e la soluzione ottenuta con il metodo QR per la matrice A1 è:" << scientific << setprecision(15) << err_QR << endl;
		cout << "la soluzione della matrice A1 con il sistema PALU è:" << scientific << setprecision(15) << solve_PALU(A1,b1) << endl;
		err_PALU=err_rel(solve_PALU(A1,b1),x_esatta);
		cout << "l'errore relativo tra la soluzione esatta e la soluzione ottenuta con il metodo PALU per la matrice A1 è:" << scientific << setprecision(15) << err_PALU << endl;
	}
	
	Matrix2d A2 {
      {5.547001962252291e-01, -5.540607316466765e-01},
      {8.320502943378437e-01, -8.324762492991313e-01},
	  };
	Vector2d b2(-6.394645785530173e-04, 4.259549612877223e-04);
	if (abs(A2.determinant())<epsilon){
		cout << "la matrice è singolare" << endl;
	}else{
		cout << "la soluzione della matrice A2 con il sistema QR è:" << scientific << setprecision(15) << solve_QR(A2,b2) << endl;
		err_QR=err_rel(solve_QR(A2,b2),x_esatta);
		cout << "l'errore relativo tra la soluzione esatta e la soluzione ottenuta con il metodo QR per la matrice A2 è:" << scientific << setprecision(15) << err_QR << endl;
		cout << "la soluzione della matrice A2 con il sistema PALU è:" << scientific << setprecision(15) << solve_PALU(A2,b2) << endl;
		err_PALU=err_rel(solve_PALU(A2,b2),x_esatta);
		cout << "l'errore relativo tra la soluzione esatta e la soluzione ottenuta con il metodo PALU per la matrice A2 è:" << scientific << setprecision(15) << err_PALU << endl;
	}
		
	Matrix2d A3 {
      {5.547001962252291e-01, -5.547001955851905e-01},
      {8.320502943378437e-01, -8.320502947645361e-01},
	  };
	Vector2d b3(-6.400391328043042e-10, 4.266924591433963e-10);
	if (abs(A3.determinant())<epsilon){
		cout << "la matrice è singolare" << endl;
	}else{
		cout << "la soluzione della matrice A3 con il sistema QR è:" << scientific << setprecision(15) << solve_QR(A3,b3) << endl;
		err_QR=err_rel(solve_QR(A3,b3),x_esatta);
		cout << "l'errore relativo tra la soluzione esatta e la soluzione ottenuta con il metodo QR per la matrice A3 è:" << scientific << setprecision(15) << err_QR << endl;
		cout << "la soluzione della matrice A3 con il sistema PALU è:" << scientific << setprecision(15) << solve_PALU(A3,b3) << endl;
		err_PALU=err_rel(solve_PALU(A3,b3),x_esatta);
		cout << "l'errore relativo tra la soluzione esatta e la soluzione ottenuta con il metodo PALU per la matrice A3 è:" << scientific << setprecision(15) << err_PALU << endl;
	}
	
    return 0;
}
