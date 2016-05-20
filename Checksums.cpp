// Checksums.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Checksum.h"

#include <iostream>

int main()
{
	Checksum checksum;
	std::vector<unsigned char> data{1, 2, 3, 4, 5, 6};

	uint32_t check = checksum.modularSum(data);
	bool malformed = checksum.modularSumVerify(data, check);

	if (malformed)
	{
		std::cout << "Great :D" << std::endl;
	}
	else
	{
		std::cout << "Corrupted data" << std::endl;
	}

	system("pause");
    return 0;
}

