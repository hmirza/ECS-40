// Haaris Mirza
// 912341213
// Tetromino.cpp

#include <iostream>
#include <stdexcept>
#include "Tetromino.h"

using namespace std;

char I::name(void) const
{
	return 'I';
}
char O::name(void) const
{
	return 'O';
}
char T::name(void) const
{
	return 'T';
}
char J::name(void) const
{
	return 'J';
}
char L::name(void) const
{
	return 'L';
}
char S::name(void) const
{
	return 'S';
}
char Z::name(void) const
{
	return 'Z';
}

void Tetromino::rotate(int nrot)
{
			//int tempX[4];
			//int tempY[4];

			int tempArrayX[4];
			int tempArrayY[4];
			

			//move user input values into new Array
			for (int p = 0; p < 4; p++)
			{	
				
				tempArrayX[p] = x[p];
				tempArrayY[p] = y[p];

			}

			//make new origin
			for(int l = 1; l < 4; l++)
			{
				x[0] = 0;
				y[0] = 0;
				x[l] = tempArrayX[l] - tempArrayX[0];
				y[l] = tempArrayY[l] - tempArrayY[0];
			}

			//need to do math operation to calculate 90 degree shift 
			int xtemp[4];
			int ytemp[4];
			
			//store 
			for (int j = 1; j<4;j++)
			{
				switch(nrot)
				{
					case 1:
						xtemp[j] = x[j];
						ytemp[j] = y[j];

						x[j] = -ytemp[j];
						y[j] = xtemp[j];
						break;
					case 2:
						xtemp[j] = x[j];
						ytemp[j] = y[j];

						x[j] = -xtemp[j];
						y[j] = -ytemp[j];
						break;
					case 3:
						xtemp[j] = x[j];
						ytemp[j] = y[j];
						
						x[j] = ytemp[j];
						y[j] = -xtemp[j];
						break;

					
				}	

				x[j] = x[j] + tempArrayX[0];
				y[j] = y[j] + tempArrayY[0]; 
			}

			//make sure x[0],y[0] are original user input values
			x[0] = tempArrayX[0];
			y[0] = tempArrayY[0];
}


void Tetromino::print(void) const
{
	cout << name() << " at (";
	cout << x[0] << "," << y[0];
	cout << ") (";
	cout << x[1] << "," << y[1];
	cout << ") (";
	cout << x[2] << "," << y[2];
	cout << ") (";
	cout << x[3] << "," << y[3];
	cout << ")" <<endl;

}


bool Tetromino::overlap(const Tetromino &t) const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (this->x[i] == t.x[j] && this->y[i] == t.y[j])
			{
				return true;
			}
		}
	}
	return false;

}

//constructor for I
I::I(int posx, int posy, int orientation)
{
	if (orientation >= 0 && orientation < 4)
	{
		x[0] = posx;
		y[0] = posy;

		x[1] = posx;
		y[1] = posy + 1;

		x[2] = posx;
		y[2] = posy + 2;

		x[3] = posx;
		y[3] = posy + 3;
		
		if (orientation > 0 && orientation < 4)
		{
			rotate(orientation);
		}
	}

	else
	{
		throw invalid_argument("invalid orientation");
	}

}

//constructor for O
O::O(int posx, int posy, int orientation)
{
	if (orientation >= 0 && orientation < 4)
	{	
		x[0] = posx;
		y[0] = posy;

		x[1] = posx + 1;
		y[1] = posy;

		x[2] = posx;
		y[2] = posy + 1;

		x[3] = posx + 1;
		y[3] = posy + 1;
		
		if (orientation > 0 && orientation < 4)
		{
			rotate(orientation);
		}
	}

	else
	{
		throw invalid_argument("invalid orientation");
	}

}

//constructor for T
T::T(int posx,int posy, int orientation)
{
	if (orientation >= 0 && orientation < 4)
	{
		x[0] = posx;	
		y[0] = posy;

		x[1] = posx -1;
		y[1] = posy + 1;

		x[2] = posx;
		y[2] = posy + 1;

		x[3] = posx + 1;
		y[3] = posy + 1;
		
		if (orientation > 0 && orientation < 4)
		{
			rotate(orientation);
		}
	}

	else
	{
		throw invalid_argument("invalid orientation");
	}

}

//constructor for J
J::J(int posx, int posy, int orientation)
{
	if (orientation >= 0 && orientation < 4)
	{
		x[0] = posx;
		y[0] = posy;

		x[1] = posx + 1;
		y[1] = posy;

		x[2] = posx + 1;
		y[2] = posy + 1;

		x[3] = posx + 1;
		y[3] = posy + 2;
	
		if (orientation > 0 && orientation < 4)
		{
			rotate(orientation);
		}
	}

	else
	{
		throw invalid_argument("invalid orientation");
	}

}

//constructor for L
L::L (int posx, int posy, int orientation)
{
	if (orientation >= 0 && orientation < 4)
	{
		x[0] = posx;
		y[0] = posy;

		x[1] = posx + 1;
		y[1] = posy;

		x[2] = posx;
		y[2] = posy + 1;

		x[3] = posx;
		y[3] = posy + 2;
		
		if (orientation > 0 && orientation < 4)
		{
			rotate(orientation);
		}
	}

	else
	{
		throw invalid_argument("invalid orientation");
	}

}

//constructor for S
S::S(int posx, int posy, int orientation)
{
	if (orientation >= 0 && orientation < 4)
	{
		x[0] = posx;
		y[0] = posy;

		x[1] = posx + 1;
		y[1] = posy;

		x[2] = posx + 1;
		y[2] = posy + 1;

		x[3] = posx + 2;
		y[3] = posy + 1;
		
		if (orientation > 0 && orientation < 4)
		{
			rotate(orientation);
		}
	}

	else
	{
		throw invalid_argument("invalid orientation");
	}

}

//constructor for Z
Z::Z (int posx, int posy, int orientation)
{
	if (orientation >= 0 && orientation < 4)
	{
		x[0] = posx;
		y[0] = posy;

		x[1] = posx + 1;
		y[1] = posy;

		x[2] = posx - 1;
		y[2] = posy + 1;

		x[3] = posx;
		y[3] = posy + 1;
		
		if (orientation > 0 && orientation < 4)
		{
			rotate(orientation);
		}
	}

	else
	{
		throw invalid_argument("invalid orientation");
	}

}





Tetromino *Tetromino::makeTetromino( char check, int posx, int posy, int orientation)
{
	 Tetromino *tetrominoPtr;

	if (check == 'I')
	{
		tetrominoPtr=new I(posx,posy,orientation);

		return tetrominoPtr ;
		
	}

	else if (check == 'O')
	{
		tetrominoPtr = new O(posx,posy,orientation);
		return tetrominoPtr;

	}


	else if (check == 'T')
	{
		tetrominoPtr = new T(posx,posy,orientation);

		return tetrominoPtr;
	}


	else if(check == 'J')
	{
		tetrominoPtr = new J(posx, posy, orientation);

		return tetrominoPtr;
	}

	else if (check == 'L')
	{
		
		tetrominoPtr = new L(posx,posy,orientation);
		return tetrominoPtr;
	}

	else if (check == 'S')
	{
		
		tetrominoPtr = new S(posx,posy,orientation);
		return tetrominoPtr;
	}

	else if (check == 'Z')
	{
		tetrominoPtr = new Z(posx,posy,orientation);
		return tetrominoPtr;
	}

	else 
	{
		throw invalid_argument ("invalid type");
		return 0;
	}


}






























