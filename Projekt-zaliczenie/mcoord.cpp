#include "stdafx.h"
#include "mcoord.h"

mcoord::mcoord()
{
    pcoord = new double[2];
    pcoord[0] = 0; pcoord[1] = 1;
};

mcoord::mcoord(double xx, double yy)
{
    pcoord = new double[2];
    pcoord[0] = xx;
    pcoord[1] = yy;
}

mcoord::mcoord(const mcoord & rhs)
{
    pcoord = new double[2];
    pcoord[0] = rhs.pcoord[0];
    pcoord[1] = rhs.pcoord[1];
}

mcoord & mcoord::operator=(const mcoord & rhs)
{
    pcoord[0] = rhs.pcoord[0];
    pcoord[1] = rhs.pcoord[1];
    return *this;
}

mcoord::~mcoord()
{
    delete[] pcoord;
}