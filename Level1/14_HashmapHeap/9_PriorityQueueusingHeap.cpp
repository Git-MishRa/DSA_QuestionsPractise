#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> mydata;

int _size()
{
    // write your code here
    return mydata.size();
}

void swap(int i, int pi)
{
    int di = mydata[i];
    int dpi = mydata[pi];
    mydata[i] = dpi;
    mydata[pi] = di;
}

void upHeapify(int i)
{
    if (i == 0)
    {
        return;
    }
    int pi = (i - 1) / 2;
    if (mydata[i] < mydata[pi])
    {
        swap(i, pi);
        upHeapify(pi);
    }
}

void add(int val)
{
    // write your code here
    mydata.push_back(val);
    upHeapify(mydata.size() - 1);
}

void downHeapify(int pi)
{
    int min = pi;
    // checking left child
    int li = 2 * pi + 1;
    if (li < mydata.size() && mydata[li] < mydata[min])
    {
        min = li;
    }
    // checking right child
    int ri = 2 * pi + 2;
    if (ri < mydata.size() && mydata[ri] < mydata[min])
    {
        min = ri;
    }

    // swapping
    if (min != pi)
    {
        swap(pi, min);
        downHeapify(min);
    }
}

int _remove()
{
    // write your code here
    if (mydata.empty())
    {
        cout << "Underflow"<<endl;
        return -1;
    }
    swap(0, mydata.size() - 1);
    int ans = mydata[mydata.size() - 1];
    mydata.pop_back();
    // re arranging the data
    downHeapify(0);
    return ans;
}

int peek()
{
    // write your code here
    if (_size() == 0)
    {
        cout << "Underflow" << endl;
        return -1;
    }

    return mydata[0];
}

int main()
{

    while (1)
    {
        string str;
        getline(cin, str);
        if (str[0] == 'a')
        {
            string num = str.substr(4, str.length());
            int val = stoi(num);
            add(val);
        }
        else if (str[0] == 'r')
        {
            int val = _remove();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str[0] == 'p')
        {
            int val = peek();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else
            break;
    }
}