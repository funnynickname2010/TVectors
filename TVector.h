#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

class TVector
{
	int size;
	double* val;

public:

	explicit TVector(int n);
	TVector(int n, double* p);
	TVector(const TVector& vec);
	~TVector();

	TVector operator +(const TVector& vec);
	TVector operator -(const TVector& vec);
	TVector operator *(const double scalar);
	TVector operator /(const double scalar);
	TVector& operator =(const TVector& vec);
	TVector& operator +=(const TVector& vec);
	TVector& operator -=(const TVector& vec);
	double& operator [](const int index) ;
	TVector& operator ++();
	TVector operator ++(int);
	TVector& operator --();
	TVector operator --(int);
	
	bool operator ==(const TVector& vec) const;
	bool operator !=(const TVector& vec) const;

	double ScalarProduct(const TVector& vec) const;
	TVector CrossProduct(const TVector& vec) const;
	double TripleProduct(const TVector& vec2, const TVector& vec3) const;

	void SetSize();
	void SetVal();

	int GetSize();

	friend std::ostream& operator <<(std::ostream& os, const TVector& vec);
	friend std::istream& operator >>(std::istream& os, TVector& vec);
};

