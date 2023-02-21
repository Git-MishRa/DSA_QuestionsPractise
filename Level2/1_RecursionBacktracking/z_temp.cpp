#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "saurabh";
    int a = 10;
    str += to_string(a);
    cout << str;
    return 0;
}