#include <iostream>
#include <cstdlib>

using namespace std;

int get_random()
{
    return rand() % 200;
}

int main()
{
    int n;

    cout << "Please enter a number" << endl;
    cin >> n;

    srand((unsigned) time(NULL)); 

    for (int i = 0; i <= 5; i++)
    {
        if (get_random() == 150)
            n += 1;
        else
        {
            i--;
        }
    }

    cout << "Your number + 5 is: " << n << endl;

    return 0;
}
