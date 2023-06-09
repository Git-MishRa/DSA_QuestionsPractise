// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.



class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        if (nums[0] >= nums[nums.size() - 1])
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] < nums[i + 1])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    return false;
                }
            }
            return true;
        }
    }
};