#include "TVector.h"

void interface_input(TVector& x, TVector& y);
void interface_input(TVector& x, double& y);
void interface_options();

int main()
{
	int n;
	std::cout << "Input size of the vectors: ";
	std::cin >> n;
	
	TVector a(n), b(n);
	int operation_id;
	TVector res(n);
	bool res_bool;
	double res_double;
	TVector c(n);

	interface_input(a, b);

	do
	{
		interface_options();

		std::cin >> operation_id;

		char option_chosen;
		double scalar;

		switch (operation_id)
		{
			std::cin >> operation_id;

		case 1:

			res = a + b;
			break;

		case 2:

			res = a - b;
			break;

		case 3:

			std::cout << "Which vector would you like to multiply: a or b? " << std::endl;
			std::cin >> option_chosen;

			std::cout << "Input a scalar to multiply vector " << option_chosen << " by: " << std::endl;
			std::cin >> scalar;
			
			if (option_chosen == 'a')
			{
				res = a * scalar;
			}
			else if (option_chosen == 'b')
			{
				res = b * scalar;
			}
			else
			{
				std::cout << "Error. No such vector detected.\n";
			}

			break;

		case 4:

			std::cout << "Which vector would you like to divide: a or b? " << std::endl;
			std::cin >> option_chosen;

			std::cout << "Input a scalar to divide vector " << option_chosen << " by: " << std::endl;
			std::cin >> scalar;

			if (option_chosen == 'a')
			{
				res = a / scalar;
			}
			else if (option_chosen == 'b')
			{
				res = b / scalar;
			}
			else
			{
				std::cout << "Error. No such vector detected.\n";
			}

			break;

		case 5:

			res = a = b;
			break;

		case 6:

			res_bool = a == b;
			break;

		case 7:

			res_bool = a != b;
			break;

		case 8:

			res_double = a.ScalarProduct(b);
			break;

		case 9:

			res = a.CrossProduct(b);
			break;

		case 10:

			std::cout << "Input vector c: " << std::endl;
			std::cin >> c;

			res_double = a.TripleProduct(b, c);
			break;

		case 11:
			interface_input(a, b);
			break;

		case 12:

			res = a += b;
			break;

		case 13:

			res = a -= b;
			break;

		case 14:

			break;
		}

		if (operation_id != 14)
		{
			std::cout << "\n ----Operation details---- \n";
			std::cout << "a: " << a << '\n';
			std::cout << "b: " << b << '\n';

			if (operation_id == 6 || operation_id == 7)
			{
				std::cout << "returned value: " << res_bool << std::endl << std::endl;
			}
			else if (operation_id == 8)
			{
				std::cout << "returned value: " << res_double << std::endl << std::endl;
			}
			else if (operation_id == 10)
			{
				std::cout << "c: " << c << '\n';
				std::cout << "returned value: " << res_double << std::endl << std::endl;
			}
			else if (operation_id != 11)
			{
				std::cout << "returned value: " << res << std::endl << std::endl;
			}
		}

	} while (operation_id != 14);



	return 0;
}

void interface_input(TVector& x, TVector& y)
{
	std::cout << "Expression format: \na <operation> b\n";

	std::cout << "Input a: ";
	std::cin >> x;
	std::cout << "Input b: ";
	std::cin >> y;
}

void interface_input(TVector& x, double& y)
{
	std::cout << "Expression format: \na <operation> b\n";

	std::cout << "Input a: ";
	std::cin >> x;
	std::cout << "Input b: ";
	std::cin >> y;
}

void interface_options()
{
	std::cout << "\nWhich operation do you want to test?\n";
	std::cout << "1. +\n";
	std::cout << "2. -\n";
	std::cout << "3. * [a or b miltiplied by scalar]\n";
	std::cout << "4. / [a or b divided by scalar]\n";
	std::cout << "5. =\n";
	std::cout << "6. ==\n";
	std::cout << "7. !=\n";
	std::cout << "8. Scalar product\n";
	std::cout << "9. Cross product\n";
	std::cout << "10. Triple product (a, [b, c])\n";
	std::cout << "11. Change the variables' values\n";
	std::cout << "12. +=\n";
	std::cout << "13. -=\n";
	std::cout << "14. Exit\n\n";
}