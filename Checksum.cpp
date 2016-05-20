#include "stdafx.h"
#include "Checksum.h"

Checksum::Checksum()
{
}

Checksum::~Checksum()
{
}

uint32_t Checksum::modularSum(vector<unsigned char> bytes)
{
	uint32_t check = 0;

	for (uint32_t i = 0; i < bytes.size(); i++)
	{
		check = discardOverflow(check, bytes.at(i));
		check += bytes.at(i);
	}

	return ~check + 1;
}

bool Checksum::modularSumVerify(vector<unsigned char> bytes, uint32_t checksum)
{
	uint32_t check = 0;

	for (uint32_t i = 0; i < bytes.size(); i++)
	{
		check = discardOverflow(check, bytes.at(i));
		check += bytes.at(i);
	}

	if (check + checksum == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

uint32_t Checksum::parityWord(vector<unsigned char> bytes)
{
	uint32_t check = bytes.at(0) ^ bytes.at(1);

	for (uint32_t i = 2; i < bytes.size(); i++)
	{
		check ^= bytes.at(i);
	}

	return check;
}

/*
With this checksum, any transmission error which flips a single bit of the message,
or an odd number of bits, will be detected as an incorrect checksum. 
However, an error which affects two bits will not be detected if those bits lie at the same position in two distinct words. 
Also swapping of two or more words will not be detected. If the affected bits are independently chosen at random, 
the probability of a two-bit error being undetected is 1/n.
*/
bool Checksum::parityWordVerify(vector<unsigned char> bytes, uint32_t checksum)
{
	uint32_t check = parityWord(bytes) ^ checksum;
	if (check == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

uint32_t Checksum::discardOverflow(uint32_t x, unsigned char byte)
{
	if (0xffffffff - x < byte)
	{
		x &= 0x7fffffff;
	}

	return x;
}