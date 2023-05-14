#pragma once
#include "Object.h"
class Tetrahedron :
    public Object
{
    friend ostream& operator << (ostream& os, const Tetrahedron& tetrahedron);
    friend istream& operator >> (istream& is, Tetrahedron& tetrahedron);
private:
    double edge_length;
    double volume;
public:
    void Volume(bool file) override;
    void OutputFile() override;
    void InputFile() override;

    Tetrahedron();
    Tetrahedron(double edge_length);
    Tetrahedron(const Tetrahedron& other);
    ~Tetrahedron() override;
};

