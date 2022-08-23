#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    if (num1>num2)
    {
        for (int i = 0; i*i < num2; i++)
        {
            if (/* condition */)
            {
                /* code */
            }
            
        }
        
    }
    else if (num2>num1)
    {
        
    }
    else{
        cout<<num1;
    }
    
    
    return 0;
}