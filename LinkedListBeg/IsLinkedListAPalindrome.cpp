#include <bits/stdc++.h>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linked_list
{
public:
    node *head, *tail;
    int size = 0;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        size++;
    }
    void display()
    {
        for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        {
            cout << tmp->data << " ";
        }
    }

    int isPalindrome()
    {

        // write your code here
        // Using stack
        stack<int> st;
        node *temp = head;
        while (temp->next != NULL)
        {
            st.push(temp->data);
            temp = temp->next;
        }
        st.push(temp->data);
        temp = head;
        while (temp->next != NULL)
        {
            if (temp->data != st.top())
            {
                return 0;
            }
            else
            {
                st.pop();
            }
            temp = temp->next;
        }
        return 1;
    }
};

int main()
{
    int b;
    cin >> b;
    linked_list a;
    vector<int> arr(b, 0);
    for (int i = 0; i < b; i++)
    {

        cin >> arr[i];
        a.add_node(arr[i]);
    }

    int res = a.isPalindrome();
    if (res == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}