#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct Coord
{
	int _x;
	int _y;
};

bool cmp(const Coord &a, const Coord &b);
void swap(int idx1, int idx2, Coord *arr);
int get_mid (Coord *arr, int start, int end, bool(*cmp)(const Coord&, const Coord&)); //quicksort util
void quicksort(Coord *arr, bool (*cmp)(const Coord&, const Coord&), int start, int end);
void heap_util(Coord *arr, int n, int i,int start, bool (*cmp)(const Coord&, const Coord&));
void heapSort(Coord *arr, int left, int right, bool (*cmp)(const Coord&, const Coord&));
void sort(Coord *arr, bool (*cmp)(const Coord&, const Coord&), int size); //Bubble
void insertion_sort(Coord *arr, int left, int right, bool (*cmp)(const Coord&, const Coord&));
void introSort(Coord *arr, int left, int right, int depth, bool (*cmp)(const Coord&, const Coord&));


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int nb, i, tmp;
	i = 0;
	cin >>nb;

	Coord	*input = new Coord[nb];
	while (i < nb)
	{
		cin >>  input[i]._x >> input[i]._y;
		i++;
	}
	// sort (input, cmp, nb);
	// sort(input, cmp, 0, nb - 1); // quicksort
	// sort(input, input + nb, cmp); //function in lib
	
	int depth = 2 * log(nb);
	introSort(input, 0, nb - 1, depth, cmp);

	i = 0;
	while (i < nb)
	{
		 cout << input[i]._x <<  " " <<  input[i]._y << "\n";
		 i++;
	}
	delete[] input;
}

bool cmp(const Coord &a, const Coord &b)
{
	if(a._x == b._x)
		return (a._y < b._y);
	else
		return (a._x < b._x);
}

void swap (int idx1, int idx2, Coord *arr)
{
	Coord tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

int get_mid(Coord *arr, int start, int end, bool(*cmp)(const Coord&, const Coord&))
{
	int mid = (start + end) / 2;

	if (cmp(arr[mid], arr[start]))
		swap(start, mid, arr);
	if (cmp(arr[end], arr[start]))
		swap(start, end, arr);
		if (cmp(arr[end], arr[mid]))
		swap(mid, end, arr);

	return mid;	
}

// 퀵소트 
void quicksort(Coord *arr, bool (*cmp)(const Coord&, const Coord&), int start, int end)
{
	if (start >= end)
		return ;
	int pivotIdx = get_mid(arr, start, end, cmp);
	swap(start, pivotIdx, arr);
	Coord pivot = arr[start];
	int left = start + 1;
	int right = end;

	while (1)
	{
		while (left <= right && cmp(arr[left], pivot))
			left++;
		while (left <= right && cmp(arr[right], pivot))
			right--;
		
		if (left > right)
			break;
		swap(left, right, arr);
	}
	swap(start, right, arr);
	quicksort(arr, cmp, start, right-1);
	quicksort(arr, cmp, right + 1, end);
}

void heap_util(Coord *arr, int n, int i,int start, bool (*cmp)(const Coord&, const Coord&))
{
	int largest = i;
	int left = 2 * (i - start) + 1 + start;
	int right = 2 * (i - start) + 2 + start;

	if (left < start + n && cmp(arr[largest], arr[left]))
		largest = left;
	if (right < start + n && cmp(arr[largest], arr[right]))
		largest = right;

	if (largest != i) {
		swap(i, largest, arr);
		heap_util(arr, n, largest, start, cmp);
	}
}


//heap
void heapSort(Coord *arr, int left, int right, bool (*cmp)(const Coord&, const Coord&))
{
	int n = right - left + 1;
	int i = left + n / 2 - 1;
	while (i >= left)
	{
		heap_util(arr, n, i, left, cmp);
		i--;
	}

	i = right;
	while (i > left)
	{
		swap(left, i, arr);
		heap_util(arr, i - left, left, left, cmp);
	}
}

//버블
void sort(Coord *arr, bool (*cmp)(const Coord&, const Coord&), int size)
{
	int i = 0, j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(arr[j], arr[j+1]))
				swap (j, j + 1, arr);
			j++;
		}
		i++;
	}
}

//삽입
void insertion_sort(Coord *arr, int left, int right, bool (*cmp)(const Coord&, const Coord&))
{
	int i = left + 1;
	Coord tmp;
	while(i <= right)
	{
		tmp = arr[i];
		int j = i - 1;
		while (j >= left && cmp(tmp, arr[j]))
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		i++;
	}
}

void introSort(Coord *arr, int left, int right, int depth, bool (*cmp)(const Coord&, const Coord&))
{
	if (right - left <10)
	{
		insertion_sort(arr, left, right, cmp);
		return ;
	}
	if (depth == 0)
	{
		heapSort(arr, left, right, cmp);
		return ;
	}

	int pivotIdx = get_mid(arr, left, right, cmp);
    swap(left, pivotIdx, arr);
    Coord pivot = arr[left];
    int i = left + 1, j = right;

    while (i <= j) {
        while (i <= j && cmp(arr[i], pivot)) i++;
        while (i <= j && cmp(pivot, arr[j])) j--;
        if (i <= j) swap(i++, j--, arr);
    }
    swap(left, j, arr);

    introSort(arr, left, j - 1, depth - 1, cmp);
    introSort(arr, j + 1, right, depth - 1, cmp);
	// quicksort(arr, cmp, left, right);
}
