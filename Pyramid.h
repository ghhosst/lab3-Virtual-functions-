#pragma once
#include "Object.h"

class Pyramid :
    public Object
{
    friend ostream& operator << (ostream& os, const Pyramid& pyramid);
    friend istream& operator >> (istream& is, Pyramid& pyramid);
private:
    double base_area;
    double height;
    double volume;
public:
    void Volume(bool file) override;
    void OutputFile() override;
    void InputFile() override;

    Pyramid();
    Pyramid(double base_area, double height);
    Pyramid(const Pyramid& other);
    ~Pyramid() override;
};