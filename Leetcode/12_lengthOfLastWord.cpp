class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        // removing the spaces from the end
        int x = s.length() - 1;
        while (s[x] == ' ')
        {
            x--;
        }
        for (int i = x; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                count++;
            }
            else
            {
                return count;
            }
        }
        return count;
    }
};