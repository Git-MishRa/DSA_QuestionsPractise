class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        int checkFreq[26] = {0};
        if (s.length() > t.length())
        {
            return false;
        }
        for (int i = 0; i < t.length(); i++)
        {
            checkFreq[t[i] - 'a']++;
            if (checkFreq[t[i] - 'a'] > freq[t[i] - 'a'])
            {
                return false;
            }
        }
        return true;
    }
};