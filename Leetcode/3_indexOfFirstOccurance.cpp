class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        char start = needle[0];
        int range = haystack.length() - needle.length();
        for (int i = 0; i <= range; i++)
        {
            if (haystack[i] == start)
            {
                if (haystack.substr(i, needle.length()) == needle)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};