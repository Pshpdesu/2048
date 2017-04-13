#pragma once
#include "Tile.h"
#include <iostream>
#include <Windows.h>

class Field
{
public:
	Field();
	Field(UINT32 sizexy);
	Field(const Field &a);
	Field &operator=(const Field& a);
	//===================
	//dirx ==   -1 - left
	//dirx ==	 1 - right
	//diry ==	 1 - up
	//diry ==	-1 - down
	//===================
	bool Move(int dirx, int diry);
	Tile& GetTile(UINT32 x, UINT32 y);

	virtual ~Field();

private: 
	Tile **field;
	UINT32 Size;
};

