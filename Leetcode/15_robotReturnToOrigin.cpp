class Solution
{
public:
    bool judgeCircle(string moves)
    {
        unordered_map<char, int> hmap;
        hmap['U'] = 0;
        hmap['D'] = 0;
        hmap['L'] = 0;
        hmap['R'] = 0;
        for (int i = 0; i < moves.length(); i++)
        {
            char ch = moves.at(i);
            hmap[ch]++;
        }
        if (hmap['U'] == hmap['D'] && hmap['L'] == hmap['R'])
        {
            return true;
        }
        return false;
    }
};