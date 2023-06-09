// You are given two strings s and t.

// String t is generated by random shuffling string s and then add one more letter at a random position.

// Return the letter that was added to t.

// Remember, t is generated by shuffling s

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        // Appproach
        // create a frequency array
        // if the frequency dosen't match, retun ans
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            // s[i]-'a' returns the number of the letter
            // i.e a==0, f==6
            freq[s[i] - 'a']++;
        }

        // checking
        int checkFreq[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            checkFreq[t[i] - 'a']++;
            if (checkFreq[t[i] - 'a'] > freq[t[i] - 'a'])
            {
                return t[i];
            }
        }
        return t.at(t.length() - 1);
    }
};