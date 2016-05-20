#pragma once

#include <vector>

using namespace std;

class Checksum
{
public:
	Checksum();
	~Checksum();

	uint32_t modularSum(vector<unsigned char> bytes);
	bool modularSumVerify(vector<unsigned char> bytes, uint32_t checksum);
	
	uint32_t parityWord(vector<unsigned char> bytes);
	bool parityWordVerify(vector<unsigned char> bytes, uint32_t checksum);

private:
	uint32_t discardOverflow(uint32_t x);
	uint32_t bitCount(uint32_t x);
};

