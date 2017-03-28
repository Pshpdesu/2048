#include "Tile.h"


Tile::Tile()
{
	x = 0;
	y = 0;
	num = 0;
	bool enable = false;
}

Tile::Tile(int a, int x, int y)
{
	num = a;
	this->x = x;
	this->y = y;
}

Tile::Tile(const Tile & a)
{
	x = a.x;
	y = a.y;
	enabled = a.enabled;
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
