#include "Field.h"

Field::Field()
{
	Size = 5;
	*field = new Tile[Size];
	for (int i = 0; i < Size; i++)
	{
		field[i] = new Tile[Size];
	}
}

Field::Field(UINT32 sizexy)
{
	Size = sizexy;
	field = new Tile*[Size];
	for (int i = 0; i < Size; i++)
	{
		field[i] = new Tile[Size];
	}
}

Field::Field(const Field & a)
{
	if (field != nullptr)
	{
		for (int i = 0; i < Size; i++)
			delete[] field[i];
		delete[]field;
	}
	Size = a.Size;
	field = new Tile*[Size];
	for (int i = 0; i < Size; i++)
	{
		field[i] = new Tile[Size];
	}
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			field[i][j] = a.field[i][j];
}

Field  &Field::operator=(const Field & a)
{
	Size = a.Size;
	*field = new Tile[Size];
	for (int i = 0; i < Size; i++)
	{
		field[i] = new Tile[Size];
	}
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			field[i][j] = a.field[i][j];
	return *this;
}



bool Field::Move(int dirx, int diry)
{
	bool res = false;
	bool check = false;
	if (dirx>0)
		for (int y = 0; y<Size; y++)
			for (int x = Size - 1; x >= 0; x--)
			{
				res = false;
				for (int nx = x - 1; (nx >= 0) && !res; nx--)
				{
					if (field[x][y].GetNum() == 0)
					{
						if (field[nx][y].GetNum() != 0)
						{
							field[x][y] = field[x][y] + field[nx][y];
							field[nx][y] = 0;
							nx++;
							x++;
							res = true;
							check = true;
						}
					}
					else
					{
						if ((field[x][y].GetNum() == field[nx][y].GetNum()) && (field[nx][y].GetNum() != 0))
						{
							field[x][y] = field[x][y] + field[nx][y];
							field[nx][y] = 0;
							check = true;
							res = true;
						}
						else
						{
							if (field[nx][y].GetNum() != 0)
								res = true;
						}
					}
				}
			}
	if (dirx<0)
		for (int y = 0; y<Size; y++)
			for (int x = 0; x <Size; x++)
			{
				res = false;
				for (int nx = x + 1; (nx < Size) && !res; nx++)
				{
					if (field[x][y].GetNum() == 0)
					{
						if (field[nx][y].GetNum() != 0)
						{
							field[x][y] = field[x][y] + field[nx][y];
							field[nx][y] = 0;
							nx--;
							x--;
							res = true;
							check = true;
						}
					}
					else
					{
						if ((field[x][y].GetNum() == field[nx][y].GetNum()) && (field[nx][y].GetNum() != 0))
						{
							field[x][y] = field[x][y] + field[nx][y];
							field[nx][y] = 0;
							check = true;
							res = true;
						}
						else
						{
							if (field[nx][y].GetNum() != 0)
								res = true;
						}
					}
				}
			}
	if (diry>0)
		for (int x = 0; x < Size; x++)
			for (int y = Size - 1; y >= 0; y--)
			{
				res = false;
				for (int ny = y - 1; (ny >= 0) && !res; ny--)
				{
					if (field[x][y].GetNum() == 0)
					{
						if (field[x][ny].GetNum() != 0)
						{
							field[x][y] = field[x][y] + field[x][ny];
							field[x][ny] = 0;
							y++;
							ny++;
							res = true;
							check = true;
						}
					}
					else
					{
						if ((field[x][y].GetNum() == field[x][ny].GetNum()) && (field[x][ny].GetNum() != 0))
						{
							field[x][y] = field[x][y] + field[x][ny];
							field[x][ny] = 0;
							check = true;
							res = true;
						}
						else
						{
							if (field[x][ny].GetNum() != 0)
								res = true;
						}
					}
				}
			}
	if (diry<0)
		for (int x = 0; x < Size; x++)
			for (int y = 0; y < Size; y++)
			{
				res = false;
				for (int ny = y + 1; (ny <Size) && !res; ny++)
				{
					if (field[x][y].GetNum() == 0)
					{
						if (field[x][ny].GetNum() != 0)
						{
							field[x][y] = field[x][y] + field[x][ny];
							field[x][ny] = 0;
							y--;
							ny--;
							res = true;
							check = true;
						}
					}
					else
					{
						if ((field[x][y].GetNum() == field[x][ny].GetNum()) && (field[x][ny].GetNum() != 0))
						{
							field[x][y] = field[x][y] + field[x][ny];
							field[x][ny] = 0;
							check = true;
							res = true;
						}
						else
						{
							if (field[x][ny].GetNum() != 0)
								res = true;
						}
					}
				}
			}
	return check;
}


Tile& Field::GetTile(UINT32 x, UINT32 y)
{
	return field[x][y];
}

Field::~Field()
{
	for (UINT32 i = 0; i < Size; i++)
		delete[] field[i];
	delete[] field;
}
