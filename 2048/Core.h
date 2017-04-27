#pragma once
#include "Tile.h"
#include "Field.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <list>

class Core
{
public:
	Core();
	Core(UINT32 sizexy);
	void DrawField();
	int Process();
	//false - fail; true - succ
	bool Move();
	bool Check();
	bool CheckEmptyCells();
	bool Gen(bool clear);
	bool Gen(bool clear, std::list<TileBack> &TileBackup);
	virtual ~Core();

private:
	Field *field;
	UINT32 Size;
	//==========
	//0 - none
	//1 - right
	//2 - down
	//3 - left
	//4 - up
	//==========
	INT32 prevStep;
	INT32 a;
	std::list<Field> State;
	std::list<TileBack> TileBackup;
};

