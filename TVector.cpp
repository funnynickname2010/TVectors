#include "TVector.h"

std::ostream& operator <<(std::ostream& os, const TVector& vec)
{
	os << "(" << vec.val[0];

	for (int i = 1; i < vec.size; i++)
	{
		os << ", " << vec.val[i];
	}

	os << ")";
	return os;
}

std::istream& operator>>(std::istream& is, TVector& vec)
{
	if (is.peek() == '\n')
	{
		is.ignore();
	}

	std::string input;
	std::getline(is, input);
	std::istringstream inps(input);

	if (inps.peek() == '(')
	{
		inps.ignore();
	}

	for (int i = 0; i < vec.size; i++)
	{
		if (i != 0)
		{
			if (!(inps.get() == ','))
			{
				// Error handling: Failed to extract comma
				is.setstate(std::ios::failbit);
				break;
			}
		}
		if (!(inps >> vec.val[i]))
		{
			// Error handling: Failed to extract vector element
			is.setstate(std::ios::failbit);
			break;
		}
	}

	if (inps.peek() == ' ')
	{
		inps.ignore(); // Skipping the space before ')' if there's one
	}

	if (inps.peek() == ')')
	{
		inps.ignore();
	}

	if (is.rdstate() == std::ios::failbit)
	{
		std::cout << "//////INPUT ERROR\n";

		for (int i = 0; i < vec.size; i++)
		{
			vec[i] = 0;
		}
	}

	// Clear any error flags that may have been set on the stream
	is.clear();

	return is;
}

TVector& TVector::operator +=(const TVector& vec)
{
	return (*this = *this + vec);
}

TVector& TVector::operator -=(const TVector& vec)
{
	return (*this = *this - vec);
}

bool TVector::operator ==(const TVector& vec) const
{
	bool flag_equal = 1;

	if (size != vec.size)
	{
		flag_equal = 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (val[i] != vec.val[i])
			{
				flag_equal = 0;
				break;
			}
		}
	}

	return flag_equal;
}

bool TVector::operator !=(const TVector& vec) const
{
	bool flag_equal = 1;

	if (size != vec.size)
	{
		flag_equal = 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (val[i] != vec.val[i])
			{
				flag_equal = 0;
				break;
			}
		}
	}

	return !flag_equal;
}

double TVector::ScalarProduct(const TVector& vec) const
{
	double res = 0;

	if (size == vec.size)
	{
		for (int i = 0; i < size; i++)
		{
			res = res + (val[i] * vec.val[i]);
		}
	}
	else
	{
		//Error handling
	}

	return res;
}

TVector TVector::CrossProduct(const TVector& vec) const
{
	TVector res(size);

	if (size == 3 && vec.size == 3)
	{
		//Hardcoded formulas

		res.val[0] = val[1] * vec.val[2] - val[2] * vec.val[1];
		res.val[1] = val[2] * vec.val[0] - val[0] * vec.val[2];
		res.val[2] = val[0] * vec.val[1] - val[1] * vec.val[0];
	}
	else
	{
		//Error hadling
	}

	return res;
}

double TVector::TripleProduct(const TVector& vec1, const TVector& vec2) const
{
	double res;

	if (vec1.size == 3 && vec2.size == 3 && size == 3)
	{
		res = (*this).ScalarProduct(vec1.CrossProduct(vec2));
	}
	else
	{
		//Error hadling
		res = 0;
	}

	return res;
}

TVector::TVector(int n)
{
	size = n;
	val = new double[n];

	for (int i = 0; i < n; i++)
	{
		val[i] = 0;
	}
}

TVector::TVector(int n, double* p)
{
	size = n;
	val = new double[n];

	for (int i = 0; i < n; i++)
	{
		val[i] = p[i];
	}
}

TVector::TVector(const TVector& vec)
{
	size = vec.size;
	val = new double[size];

	for (int i = 0; i < size; i++)
	{
		val[i] = vec.val[i];
	}
}

TVector::~TVector()
{
	delete[] val;
	size = 0;
}

TVector& TVector::operator =(const TVector& vec)
{
	if (this != &vec)
	{
		if (size != vec.size)
		{
			delete[] val;
			size = vec.size;
			val = new double[size];
		}

		for (int i = 0; i < size; i++)
		{
			val[i] = vec.val[i];
		}
	}
	else
	{
		//Error implementation
	}

	return *this;
}

TVector TVector::operator +(const TVector& vec)
{
	TVector res(size);

	if (size == vec.size)
	{
		for (int i = 0; i < size; i++)
		{
			res[i] = val[i] + vec.val[i];
		}
	}
	else
	{
		//Error implementation
	}

	return res;
}

TVector TVector::operator -(const TVector& vec)
{
	TVector res(size);

	if (size == vec.size)
	{
		for (int i = 0; i < size; i++)
		{
			res[i] = val[i] - vec.val[i];
		}
	}
	else
	{
		//Error implementation
	}

	return res;
}

TVector TVector::operator *(const double scalar)
{
	TVector res(size);

	for (int i = 0; i < size; i++)
	{
		res[i] = val[i] * scalar;
	}

	return res;
}

TVector TVector::operator /(const double scalar)
{
	TVector res(size);

	if (scalar != 0)
	{
		for (int i = 0; i < size; i++)
		{
			res[i] = val[i] / scalar;
		}
	}
	else
	{
		//Error implementation
		return *this;
	}

	return res;
}

double& TVector::operator [](const int index)
{
	if (abs(index) < size && index > -1)
	{
		return val[index];
	}
	else if (abs(index) < size && index < 0)
	{
		return val[size + index];
	}
	else if (abs(index) > size)
	{
		//Error implementation
		return val[0];
	}
}

TVector& TVector::operator ++()
{
	for (int i = 0; i < size; i++)
	{
		val[i]++;
	}

	return *this;
}

TVector TVector::operator ++(int)
{
	TVector res(*this);
	
	for (int i = 0; i < size; i++)
	{
		val[i]++;
	}

	return res;
}

TVector& TVector::operator --()
{
	for (int i = 0; i < size; i++)
	{
		val[i]--;
	}

	return *this;
}

TVector TVector::operator --(int)
{
	TVector res(*this);

	for (int i = 0; i < size; i++)
	{
		val[i]--;
	}

	return res;
}