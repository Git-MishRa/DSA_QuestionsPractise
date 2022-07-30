#include <iostream>
#include <stack>
using namespace std;
int main() // Encountering issue in logic when multiple elements are of same height
{
    int n;
    cin >> n;
    int arr[n], lb[n], rb[n];
    stack<int> lbs;
    stack<int> rbs;

    // INPUT ARRAY
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // left boundry array
    lb[0] = -1;
    lbs.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!lbs.empty() && arr[i] <= arr[lbs.top()]) // <= symbol to tackle elementsof same height
        {
            lbs.pop();
        }
        if (lbs.empty())
        {
            lb[i] = -1;
        }
        else
        {
            lb[i] = lbs.top();
        }
        lbs.push(i);
    }

    // right boundry array
    rb[n - 1] = n;
    rbs.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!rbs.empty() && arr[i] <= arr[rbs.top()]) // <= symbol to tackle elementsof same height
        {
            rbs.pop();
        }
        if (rbs.empty())
        {
            rb[i] = n;
        }
        else
        {
            rb[i] = rbs.top();
        }
        // if (arr[i] == arr[rbs.top()])
        // {
        //     arr[i] = n;
        // }

        rbs.push(i);
    }

    // defining max area and area dependencies vars
    int width, area, maxArea = 0;

    // Area Calculation
    for (int i = 0; i < n; i++)
    {
        // cout << "*" << rb[i] << "*" << endl;
        width = rb[i] - lb[i] - 1;
        // cout << "*" << width << "*" << endl;
        area = arr[i] * width;
        if (area > maxArea)
        {
            maxArea = area;
        }
    }

    cout << maxArea;

    return 0;
}
