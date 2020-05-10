#include <stdlib.h>
#include <string>
#include <string.h>

class Matrix
{
public:

	static const int dimensions = 3;
	int values[dimensions][dimensions];
	int determinant;

	Matrix()
	{
		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				values[rows][cols] = 1 + rand() % 25;
			}
		}
	}

	int GetDeterminant()
	{
		int det = 0;

		det += values[0][0] * values[1][1] * values[2][2];
		det += values[0][1] * values[1][2] * values[2][0];
		det += values[1][0] * values[2][1] * values[0][2];

		det -= values[2][0] * values[1][1] * values[0][2];
		det -= values[2][1] * values[1][2] * values[0][0];
		det -= values[1][0] * values[0][1] * values[2][2];

		determinant = det;
		return det;
	}

	string printMatrix()
	{
		string output = "";
		for (int rows = 0; rows < dimensions; rows++)
		{
			for (int cols = 0; cols < dimensions; cols++)
			{
				output += values[rows][cols] + ",";
			}
			output += "\n";
		}
		return output;
	}


};
