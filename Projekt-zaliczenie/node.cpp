#include "stdafx.h"
#include "node.h"
#include <cstring>
#include <iostream>
node::node(int nb, char * st, double xx, double yy) : mcoord(xx, yy)
{
    numb = nb;
    strncpy_s(str, st, sizeof str);
}

node::node() : mcoord()
{
    numb = 0;
}

node::node(const node & source) : mcoord(source)
{
    numb = source.numb;
    strncpy_s(str, source.str, sizeof str);
}

node::~node()
{
}

std::istream& operator >> (std::istream &input, node &o)
{
    input >> o.numb;
    input >> o.str;
    input >> o.pcoord[0];
    input >> o.pcoord[1];

    return input;
}

std::ostream & operator<<(std::ostream & out, node & o)
{
    out << o.numb << " " << o.str << " " << o.getX() << " " << o.getY() ;
    return out;
}