#pragma once

class Tile
{
public:
	Tile();
	Tile(int a, int x, int y);
	Tile(const Tile& a);
	Tile &operator=(const Tile& a);
	Tile &operator=(const int& a);
	Tile(int a);
	int GetNum() { return num; };
	void SetNum(int a) {num = a;};
	friend Tile operator+(const Tile &A, const Tile &B);
	virtual ~Tile();

private:
	int num;
	int x, y;
	bool enabled;
};

struct TileBack
{
	Tile tile;
	int posx, posy;
};