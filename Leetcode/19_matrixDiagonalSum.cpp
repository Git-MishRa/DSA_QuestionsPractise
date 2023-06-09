class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        // base case
        if (mat.size() == 0)
        {
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                // only one of the cases run in case of both being true
                if (i == j || i + j == mat.size() - 1)
                {
                    sum += mat[i][j];
                }
            }
        }
        // no need to subtract, no duplicate value is added
        // sum=sum-mat[mat.size()/2][mat.size()/2];
        return sum;
    }
};