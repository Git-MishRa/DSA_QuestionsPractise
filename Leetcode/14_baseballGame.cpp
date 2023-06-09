class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        int ans = 0;
        vector<int> v;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "C")
            {
                ans -= v[v.size() - 1];
                v.pop_back();
            }
            else if (operations[i] == "D")
            {
                ans = ans + (v[v.size() - 1] * 2);
                v.push_back(v[v.size() - 1] * 2);
            }
            else if (operations[i] == "+")
            {
                ans += v[v.size() - 1] + v[v.size() - 2];
                v.push_back(v[v.size() - 1] + v[v.size() - 2]);
            }
            else
            {
                string x = "";
                x += operations[i];
                int a = stoi(x);
                v.push_back(a);
                ans += a;
            }
        }
        return ans;
    }
};