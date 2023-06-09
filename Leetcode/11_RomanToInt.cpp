class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        // hashmap
        unordered_map<char, int> hmap;
        // pushing values of the symbols;
        hmap['I'] = 1;
        hmap['V'] = 5;
        hmap['X'] = 10;
        hmap['L'] = 50;
        hmap['C'] = 100;
        hmap['D'] = 500;
        hmap['M'] = 1000;
        for (int i = 0; i < s.length(); i++)
        {
            char x = s.at(i);
            if (hmap[s[i + 1]] > hmap[s[i]])
            {
                ans += hmap[s[i + 1]] - hmap[s[i]];
                i++;
            }
            else
            {
                ans += hmap[s[i]];
            }
        }
        return ans;
    }
};