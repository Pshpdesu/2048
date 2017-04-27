#include "Core.h"

Core::Core()
{
	srand(time(NULL));
	Size = 5;
	field = new Field(Size);
}


Core::Core(UINT32 sizexy)
{
	srand(time(NULL));
	Size = sizexy;
	field = new Field(sizexy);
}


void Core::DrawField()
{
	//system("cls");

	std::cout << '\n';
	//------------ÂûâüC ýEEûQüA------------
	for (int x = 0; x < Size*2; x++)
	{
		if(x%2)
		for(int y = 0;y<Size;y++)
		{
			if (field->GetTile(x/2,y).GetNum()!=0)
			std::cout <<'|'<< field->GetTile(x / 2, y).GetNum() << '\t';
			else std::cout << '|'<< '\t';
		}
		else std::cout << '\n';
	}
}

int Core::Process()
{
	system("cls");

	//==============Initialize================
	UINT32 retrycount = -1;
	UINT32 nretry = 0;
	UINT32 x = rand() % Size;
	UINT32 y = rand() % Size;
	x = 0;
	y = 0;
	UINT32 count = 0;
	int num = rand() % 2 + 2;
	int check;
	num += num % 2;
	field->GetTile(x, y) = num;
	this->DrawField();
	std::cout << "\nLyubaya klavisha - osuschestvlenie hoda; ESC - vihod\n";
	bool res1, res2, res3 = true;
	//========================================
	
	while ((_getch() != 27)||(!res1 && !res2 && !res3 && (nretry<retrycount)))
	{
		system("cls");
		
		if (count > 0)
		{
			*field = State.front();
			State.pop_front();
			if (field->GetTile(TileBackup.front().posx, TileBackup.front().posy).GetNum() == 0) {
				field->GetTile(TileBackup.front().posx, TileBackup.front().posy) = TileBackup.front().tile;
			}
			TileBackup.pop_front();
			count--;
		}
		else
		{
			State.push_front(*field);
			Gen(res3, TileBackup);
		}
		this->DrawField();
		std::cout << "\n===================================";
		this->DrawField();
		system("pause>nul");
		system("cls");
		
		this->DrawField();
			switch (_getch()) {
			case 'k':  res1=field->Move(1, 0);  break;
			case 'i':  res1=field->Move(-1, 0);  break;
			case 'j':  res1=field->Move(0, -1);  break;
			case 'l':  res1=field->Move(0, 1);  break;
			default: res1 = Move();	break;
			}
		res2 = Check();
		res3 = CheckEmptyCells();
		std::cout << "\n===================================";
		this->DrawField();
		system("pause>nul");
		
		
		if (!res1 && !res2 && !res3 )
		{
			if (nretry<retrycount) {
				std::cout << "\n Perehod na shag nazad";
				count++;
				nretry++;
			}
			else std::cout << " \n Eto konec.";
		}
		
		if (res2)
			std::cout << "\nEto pobeda";

		std::cout << "\nLyubaya klavisha - osuschestvlenie hoda; ESC - vihod\n";
	}
	State.clear();
	return 0;
}

bool Core::Move()
{
	//int dx=0, dy=0,ix=0,iy=0,lastx=0,lasty=0;
	bool res=false;
	if (prevStep==0||prevStep==4)
		if (field->Move(1, 0))
		{
			res = true;
			prevStep = 2;
			return res;
		}
		else 
			if (field->Move(0, 1))
			{
				res = true; 
				prevStep = 3;
				return res;
			}
			else
				if (field->Move(-1, 0)) {
					res = true;
					prevStep = 1;
					return res;
				}
				else
					if (field->Move(-1, 0))
					{
						res = true;
						prevStep = 4;
						return res;
					}
	if (prevStep == 1)
		if (field->Move(1, 0))
		{
			res = true;
			prevStep = 2;
			return res;
		}
		else
			if (field->Move(0, 1))
			{
				res = true;
				prevStep = 3;
				return res;
			}
			else
				if (field->Move(0, -1))
				{
					res = true;
					prevStep = 1;
					return res;
				}
				else
					if (field->Move(-1, 0))
					{
						res = true;
						prevStep = 4;
						return res;
					}
	if (prevStep == 2)
		if (field->Move(0, 1))
		{
			res = true;
			prevStep = 3;
			return res;
		}
		else
			if (field->Move(0, -1))
			{
				res = true;
				prevStep = 1;
				return res;
			}
			else
				if (field->Move(1, 0))
				{
					res = true;
					prevStep = 2;
					return res;
				}
				else
					if (field->Move(-1, 0))
					{
						res = true;
						prevStep = 4;
						return res;
					}
	if (prevStep == 3)
		if (field->Move(1, 0))
		{
			res = true;
			prevStep = 2;
			return res;
		}
		else
			if (field->Move(0,-1))
			{
				res = true;
				prevStep = 1;
				return res;
			}
			else
				if (field->Move(0, 1))
				{
					res = true;
					prevStep = 3;
					return res;
				}
				else
					if (field->Move(-1, 0))
					{
						res = true;
						prevStep = 4;
						return res;
					}
	return res;
}

bool Core::Check()
{
	bool res=false;
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			if (field->GetTile(i,j).GetNum() >= 2048)
				res = true;
	return res;
}

bool Core::CheckEmptyCells()
{
	bool res=false;
	for (int i = 0; i < Size; i++)

		for (int j = 0; j < Size; j++)
			if (field->GetTile(i, j).GetNum() == 0)
				res = true;
	return res;
}

bool Core::Gen(bool clear)
{
	UINT32 x, y,num;
	bool res=false;
	if (clear)
	{
		do
		{
			x = rand() % Size;
			y = rand() % Size;
			num = rand() % 2+2;
			num += num % 2;
			if (field->GetTile(x, y).GetNum() == 0)
			{
				field->GetTile(x, y) = num;
				res = true;
			}
		} while (!res);
	}

	return res;
}

bool Core::Gen(bool clear, std::list<TileBack> &TileBackup)
{
	UINT32 x, y, num;
	bool res = false;
	if (clear)
	{
		do
		{
			x = rand() % Size;
			y = rand() % Size;
			num = rand() % 2 + 2;
			num += num % 2;
			if (field->GetTile(x, y).GetNum() == 0)
			{
				field->GetTile(x, y) = num;
				TileBack Back;
				Back.tile = field->GetTile(x,y);
				Back.posx = x;
				Back.posy = y;
				TileBackup.push_front(Back);
				res = true;
			}
		} while (!res);
	}

	return res;
}


Core::~Core()
{
	delete field;
}