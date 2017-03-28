#pragma once
#include "Tile.h"
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <Windows.h>

class Core
{
public:
	Core();
	Core(UINT32 sizexy);
	//===================
	//dirx ==   -1 - left
	//dirx ==	 1 - right
	//diry ==	 1 - up
	//diry ==	-1 - down
	//===================
	bool Move(int dirx, int diry);
	void DrawField();
	int Process();
	virtual ~Core();

private:
	Tile** field;
	UINT32 Size;
};

