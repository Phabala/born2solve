#include <iostream>
#include <algorithm>
using namespace std;

struct primeN
{
	int num;
	int first;
	int second;
};

primeN find_prime(primeN num);
bool is_prime(int num);


int main ()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, i = 0;
	cin >> n;

	primeN *num = new primeN[n];
	while (i < n)
	{
		cin >> num[i].num;
		if (num[i].num % 2)
			return 0;
		num[i] = find_prime(num[i]);
		// cout << num[i].first <<" -------- "<< num[i].second << endl;			//출력부
		i++;
	}

	i = 0;
	while (i < n)
	{
		cout << num[i].first <<" "<< num[i++].second << endl;			//출력부
	}
	delete[] num;
	return 0;
}

primeN find_prime(primeN input)
{
	int small =  input.num/2, big = input.num - small;
	while (1)
	{
		if (is_prime(small) && is_prime(big))
		{
			input.first = small;
			input.second = big;
			break;
		}
		small--;
		big++;
	}
	// cout << input.first <<"========== "<< input.second << endl;			//출력부
	return input;
}

bool is_prime(int num)
{
	int i = 2;

	while (i < num)
	{
		if (num % i == 0)
			return (false);
		i++;
	}
	return (true);

}