#include <iostream>
#include "Mat3.h"

int main(int arg, char* argv[]) {
	std::cout << "Matrix 1: \n";
	Mat3 matrix1 = Mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
	matrix1.print();
	std::cout << "\n\n";

	std::cout << "Matrix 2: \n";
	Mat3 matrix2 = Mat3(1.0f, 4.0f, 7.0f, 2.0f, 5.0f, 8.0f, 3.0f, 6.0f, 9.0f);
	matrix2.print();
	std::cout << "\n\n";

	std::cout << "Vector 1: \n";
	Vec3 vec = Vec3(1.0f, 2.0f, 3.0f);
	std::cout << vec.ToString() << "\n\n";

	std::cout << "Matrix 1 * Matrix 2: \n";
	matrix1 *= matrix2;
	matrix1.print();
	std::cout << "\n\n";

	std::cout << "Matrix 2 * Vector 1: \n";
	vec = matrix2 * vec;
	std::cout << vec.ToString() << "\n\n";
	
	std::cout << "Setting Matrix 1 for determinate operations without divide by zero error: \n";
	matrix1 = Mat3(-4.0f, -3.0f, 3.0f, 0.0f, 2.0f, -2.0f, 1.0f, 4.0f, -1.0f);
	matrix1.print();
	std::cout << "\n\n";

	std::cout << "The determinate of Matrix 1: \n";
	std::cout << matrix1.Det() << "\n\n";

	std::cout << "The inverse of Matrix 1: \n";
	Mat3::Inverse(matrix1).print();
	std::cout << "\n\n";

	system("pause");
}