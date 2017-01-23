#pragma once
#include <exception>
class mcoord
{
protected:    
    double *pcoord;
public:
    mcoord();
    mcoord(double xx, double yy);
    mcoord(const mcoord&);
    mcoord& operator=(const mcoord&);
    virtual ~mcoord();

};
