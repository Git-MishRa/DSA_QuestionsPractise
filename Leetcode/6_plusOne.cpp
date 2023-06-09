class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        int sum = digits.back() + 1;
        if (sum >= 10)
        {
            carry = sum / 10;
            digits[digits.size() - 1] = sum % 10;
        }
        else
        {
            digits[digits.size() - 1] = digits[digits.size() - 1] + 1;
            return digits;
        }
        int i = 1;
        while (carry != 0)
        {
            if (i >= digits.size())
            {
                digits.insert(digits.begin(), carry);
                return digits;
            }
            else
            {
                sum = digits[digits.size() - i - 1] + carry;
                if (sum >= 10)
                {
                    carry = sum / 10;
                    digits[digits.size() - 1 - i] = sum % 10;
                }
                else
                {
                    digits[digits.size() - i - 1] = sum;
                    carry = 0;
                    return digits;
                }
            }
            i++;
        }
        return digits;
    }
};