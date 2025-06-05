
#include <iostream>

using namespace std;
void	swap(int &nbr1, int &nbr2);

int main()
{
	int N, M;
	cin >> N >> M;
	int arr[N];

	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	
	int start, end;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		--start;
		--end;

		while (start < end)
		{
			swap(arr[start], arr[end]);
			start++;
			end--;
		}
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';

	return 0;
}

void	swap(int &nbr1, int &nbr2)
{
	int temp;

	temp = nbr1;
	nbr1 = nbr2;
	nbr2 = temp;
}
