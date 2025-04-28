#include <iostream>

using namespace std;

struct coord
{
    int x;
    int y;
};

int main ()
{
    int num;
    int x, y;

    std::cin >> num;

    int i = 1;
    while (i < num)
    {
        num = num - i;
        i++;
    }
    if (i % 2)
    {
        x = i + 1 - num;
        y = num;
    }
    else
    {
        x = num;
        y = i + 1 - num;
    }
    std::cout << x << "/" << y << endl;

    return 0;
}