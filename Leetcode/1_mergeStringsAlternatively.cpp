class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < word1.length() + word2.length(); i++)
        {
            // cases
            // 1 word1 is shorter
            // 2 word2 is shorter
            // 3 same length
            if (c1 >= word1.length())
            {
                string s2 = word2.substr(c2, word2.length() - c2);
                return ans += s2;
            }
            else if (c2 >= word2.length())
            {
                string s1 = word1.substr(c1, word1.length() - c1);
                return ans += s1;
            }
            else
            {
                if (i % 2 == 0)
                {
                    ans += word1.at(c1);
                    c1++;
                }
                else
                {
                    ans += word2.at(c2);
                    c2++;
                }
            }
        }
        return ans;
    }
};