#include <iostream>
#include "Mat3.h"

int main(int arg, char* argv[]) {
	std::cout << "Starting Matrix: \n";
	Mat3 matrix = Mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
	matrix.print();
	std::cout << "\n\n";

	std::cout << "Matrix after Transposition: \n";
	matrix.Transpose();
	matrix.print();
	std::cout << "\n\n";

	std::cout << "Matrix after being set to Identity: \n";
	matrix.SetIdentity();
	matrix.print();
	std::cout << "\n\n";

	std::cout << "Matrix after being set for rotation of 45 degrees around Z: \n";
	matrix.RotateZ(45.0f);
	matrix.print();
	std::cout << "\n\n";

	std::cout << "Matrix after being set for scaling values [1, 2, 3] \n";
	matrix.Scale(1.0f, 2.0f, 3.0f);
	matrix.print();
	std::cout << "\n\n";

	system("pause");
}