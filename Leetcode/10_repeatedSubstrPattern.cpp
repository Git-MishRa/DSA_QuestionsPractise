class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // unique solution
        // double the string
        // remove the first and last char
        // check if the original string is present in this new one
        // if true, it is true, else false
        string t = s + s;
        if (t.substr(1, t.length() - 2).find(s) != -1)
        {
            return true;
        }
        return false;
    }
};