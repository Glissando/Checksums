// Checksums.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Checksum.h"

#include <iostream>

int main()
{
	Checksum checksum;
	std::vector<unsigned char> data{0xff, 0x12, 0x2e, 0x1c, 0x55, 0x33, 0xff, 0xff, 0xbf, 0x1d, 0xff, 0xff, 0xae, 0xbc};

	//uint32_t check = checksum.modularSum(data);
	//data.at(0) = 2;
	//bool malformed = checksum.modularSumVerify(data, check);

	uint32_t check = checksum.parityWord(data);
	data.at(2) = 0xfe;
	bool malformed = checksum.parityWordVerify(data, check);

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

