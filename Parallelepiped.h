#pragma once
#include "Object.h"

class Parallelepiped :
    public Object
{
    friend ostream& operator << (ostream& os, const Parallelepiped& point);
    friend istream& operator >> (istream& is, Parallelepiped& p);
private:
    double base_area;
    double height;
    double volume;
public:
    void Volume(bool file) override;
    void OutputFile() override;
    void InputFile() override;

    Parallelepiped();
    Parallelepiped(double base_area, double height);
    Parallelepiped(const Parallelepiped& other);
    ~Parallelepiped() override;
};