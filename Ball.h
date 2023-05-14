#pragma once
#include "Object.h"

class Ball :
    public Object
{
    friend ostream& operator << (ostream& os, const Ball& ball);
    friend istream& operator >> (istream& is, Ball& ball);
private:
    double radius;
    double volume;
public:
    void Volume(bool file) override;
    void OutputFile() override;
    void InputFile() override;

    Ball();
    Ball(double radius);
    Ball(const Ball& other);
    ~Ball() override;
};