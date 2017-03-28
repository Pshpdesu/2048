#include "Core.h"



Core::Core()
{
	Size = 5;
	*field = new Tile[Size];
	for (int i = 0; i < Size; i++)
	{
		field[i] = new Tile[Size];
	}
}


Core::Core(UINT32 sizexy)
{
	Size = sizexy;
	*field = new Tile[Size];
	for (int i = 0; i < Size; i++)
	{
		field[i] = new Tile[Size];
	}
}

//===================
//dirx ==   -1 - left
//dirx ==	 1 - right
//diry ==	 1 - up
//diry ==	-1 - down
//===================

bool Core::Move(int dirx, int diry)
{
	bool res = false;
	for (int x = 0; x<Size; x++)
		for (int y = 0; y < Size; y++)
		{
			if (field[x][y].GetNum())
			{
				if (dirx != 0)
				{
					for (int nx = x + dirx; ((nx < Size) && (nx>Size))
						|| (field[x][y].GetNum() != 0); nx += nx + dirx)
						if ((field[nx][y].GetNum() != 0) && (field[x][y].GetNum() == field[nx][y].GetNum()))
						{
							field[nx][y] = field[nx][y] + field[x][y]; field[x][y] = 0;
							res = true;
						}
				}
				else
				{
					for (int ny = y + diry; ((ny < Size) && (ny>Size))
						|| (field[x][y].GetNum() != 0); ny += ny + diry)
						if ((field[x][ny].GetNum() != 0) && (field[x][y].GetNum() == field[x][ny].GetNum()))
						{
							field[x][ny] = field[x][ny] + field[x][y]; field[x][y] = 0;
							res = true;
						}
				}
			}

		}
	return res;
}

void Core::DrawField()
{
	system("clr");

	std::cout << '\n';
	for (int x = 0; x < Size*2; x++)
	{
		if(x%2)
		for(int y = 0;y<Size;y++)
		{
			std::cout << '\t' << field[x / 2][y].GetNum();
		}
		else std::cout << '\n';
	}
}

int Process()
{
	system("clr");

	return 0;
}

Core::~Core()
{
	for (UINT32 i = 0; i < Size; i++)
		delete[] field[i];
	delete[] field;
}


