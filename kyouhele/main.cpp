#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Coord
{
	int _x;
	int _y;
};

bool cmp(Coord a, Coord b)
{
	if(a._x == b._x)
		return (a._y < b._y);
	else
		return (a._x < b._x);
}

void swap (int idx1, int idx2, Coord *arr)
{
	int temp_x = arr[idx1]._x;
	int temp_y = arr[idx1]._y;
	arr[idx1]._x = arr[idx2]._x;
	arr[idx1]._y = arr[idx2]._y;
	arr[idx2]._x = temp_x;
	arr[idx2]._y = temp_y;
}

void heap_Cmp(Coord *arr, bool (*cmp)(Coord, Coord), int size)
{

}


void sort(Coord *arr, bool (*cmp)(Coord, Coord), int size)
{
	int i = 0, j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(arr[j], arr[j+1])==0)
				swap (j, j + 1, arr);
			j++;
		}
		i++;
	}
}


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int nb, i, tmp;
	i = 0;
	cin >>nb;

	Coord	input[nb];
	while (i < nb)
	{
		cin >>  input[i]._x >> input[i]._y;
		i++;
	}
	sort (input, cmp, nb);

	i = 0;
	while (i < nb)
	{
		 cout << input[i]._x <<  " " <<  input[i]._y << endl;
		 i++;
	}
}