class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max = 0;
        int sum = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int money : accounts[i])
            {
                sum += money;
            }
            sum > max ? max = sum : sum = 0;
            sum = 0;
        }
        return max;
    }
};