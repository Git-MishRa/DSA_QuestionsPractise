#include <iostream>
using namespace std;

void allIndices(int arr[], int n, int x)
{
    if (n == 0 && arr[n] == x)
    {
        cout << n << endl;
        return;
    }
    else if (n == 0)
    {
        return;
    }
    allIndices(arr, n - 1, x);
    if (arr[n] == x)
    {
        cout << n << endl;
    }
}

int main(){
    int n,x;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>x;
    allIndices(arr,n,x);
    return 0;
}