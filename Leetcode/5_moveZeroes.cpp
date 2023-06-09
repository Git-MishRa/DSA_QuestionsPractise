class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i - count] == 0)
            {
                nums.erase(nums.begin() + i - count);
                nums.push_back(0);
                count++;
            }
        }
    }
};