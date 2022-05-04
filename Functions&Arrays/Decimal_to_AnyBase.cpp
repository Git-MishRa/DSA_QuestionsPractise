#include <iostream>
#include <vector>
using namespace std;

int baseconvert(int a, int b)
{
    vector<int> num;
    do
    {
        num.push_back(a % b); // storing the remainder to be printed
    } while (a = a / b);

    num.shrink_to_fit();
    for (int i = num.size() - 1; i >= 0; i--) // Length is 1 smaller than size of vector cuz indexing start at 0 to n-1
    {
        cout << num[i];
    }
}
int main()
{
    system("cls");
    int d, b;
    cin >> d >> b;
    baseconvert(d, b);
    return 0;
}
