// dllmain.cpp : Defines the entry point for the DLL application.
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <fstream>
#include <iostream>

using namespace std;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


#define ASSONE_API __declspec(dllexport)

extern "C" {
	//main functions
	ASSONE_API bool saveToFile(const char* filePath, float x, float y, float z)
	{
		ofstream fileStream;
		fileStream.open(filePath); //opens file
		if (fileStream.is_open()) //if the file opens successfully
		{
			fileStream << x << "," << y << "," << z; //saves the x, y and z coordinates to file
			fileStream.close();
			return true;
		}
		return false;
	}

	ASSONE_API bool loadTheFile(const char* filePath, float& x, float& y, float& z)
	{
		string s = "";
		ifstream fileStream;
		fileStream.open(filePath);
		if (fileStream.is_open()) //if file opens successfully
		{
			fileStream >> s;
			fileStream.close();
			if (sscanf(s.c_str(), "%f,%f,%f", &x, &y, &z) != 3) {
				return false;
			} //reads the x y and z coordinates 
			return true;
		}
		return false;
	}
}