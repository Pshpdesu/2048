#include "Tile.h"


Tile::Tile()
{
	x = 0;
	y = 0;
	num = 0;
	enabled = false;
}

Tile::Tile(int a, int x, int y)
{
	num = a;
	this->x = x;
	this->y = y;
	num > 0 ? enabled = true : enabled = false;
}

Tile::Tile(const Tile & a)
{
	x = a.x;
	y = a.y;
	num = a.num;
	enabled = a.enabled;
}

Tile & Tile::operator=(const Tile & a)
{
	x = a.x;
	y = a.y;
	num = a.num;
	enabled = a.enabled;
	// TODO: insert return statement here
	return *this;
}

Tile & Tile::operator=(const int & a)
{
	num = a;
	return *this;
	// TODO: insert return statement here
}

Tile::Tile(int a)
{
	SetNum(a);
}

Tile::~Tile()
{
}

Tile operator+(const Tile & A, const Tile & B)
{
	Tile res(A.num+B.num,A.x,A.y);
	return res;
}
