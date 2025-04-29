// #include <stdio.h>
// #include <stdlib.h>
// void bsort(int *arr, int size);


// int main()
// {
// 	char input[11];
// 	scanf("%s", input);
// 	int len = 0;
// 	while (input [len])
// 		len++;
	
// 	int numarr[len];
// 	int i = 0;
// 	while (i < len)
// 	{
// 		numarr[i] = input[i] - '0';
// 		if (input[i] == '0')
// 			numarr[i] = 0;
// 		i++;
// 	}
// 	bsort(numarr, i);
// 	i = 0;
// 	while(i < len)
// 	{
// 		printf("%d",	numarr[i]);
// 		i++;
// 	}
// 	return 0;
// }

// void bsort(int *arr, int size)
// {
// 	int idx = 0, j = 0;
// 	while (idx < size)
// 	{
// 		j = 0;
// 		while (j < size - idx - 1)
// 		{
// 			if (arr[j] < arr[j+1])
// 			{
// 				int tmp = arr[j];
// 				arr[j] = arr[j + 1];
// 				arr[j + 1] = tmp;
// 			}
// 			j++;
// 		}
// 		idx++;
// 	}
// }

#include <iostream>
#include <algorithm>
using namespace std;


int main ()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string num;
	cin >>num;
	sort(num.begin(), num.end(), greater<char>());
	cout << num;
	return 0;
}