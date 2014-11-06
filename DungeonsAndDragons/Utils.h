#pragma once
#include <random>

class Utils
{
private:
	static int seed;
	static std::mt19937 rng;
public:
	Utils();
	~Utils();

	static std::string ToLowerCase(std::string string);
	static int RandomNumber(int max);
	static int RandomNumber(int min, int max);
};