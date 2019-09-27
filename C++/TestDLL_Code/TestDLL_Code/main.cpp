#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

using namespace std;

//variables


//main functions
bool saveToFile(const char* filePath, float x, float y, float z) 
{
	ofstream fileStream;
	fileStream.open(filePath);
	if (fileStream.is_open())
	{
		fileStream << x << "," << y << "," << z;
		fileStream.close();
		return true;
	}
	return false;
}

bool loadTheFile(const char* filePath, float &x, float &y, float &z)
{
	string s = "";
	ifstream fileStream;
	fileStream.open(filePath);
	if (fileStream.is_open())
	{
		fileStream >> s;
		fileStream.close();
		sscanf(s.c_str(), "%f,%f,%f", &x, &y, &z);
		return true;
	}
	return false;
}

//
int main() 
{
	float x = 0, y=0, z=0;

	saveToFile("test", 4.78f , 5.90f , 6.93f);
	loadTheFile("test", x, y, z);
	printf("%f,%f,%f", x, y, z);
	return 0;
}