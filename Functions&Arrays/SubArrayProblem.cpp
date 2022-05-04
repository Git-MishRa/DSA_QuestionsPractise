#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) // STARTING POINT OF SEQUENCE
    {
        for (int j = i; j < n; j++) // ENDING POINT OF SEQUENCE
        {
            for (int k = i; k <= j; k++) // ALL THE ELEMENTS BW STARTING AND ENDING
            {
                cout << arr[k] << "    ";
            }
            cout << endl; // CHANGING THE LINE AT THE END OF THE LIMIT
        }
    }
    return 0;
}