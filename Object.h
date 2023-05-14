#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class Object{
public:
	virtual void Volume(bool file) = 0;
	virtual void OutputFile() = 0;
	virtual void InputFile() = 0;
	virtual ~Object() = 0;
};