class NumMatrix
{
    public:

        vector<vector < int>> matrix;

    int prefix[201][201]={0};

    NumMatrix(vector<vector < int>> &matrix)
    {
        this->matrix = matrix;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {

       	// simple question of prefix sum of matrix

       	// for filling first row and column

       	// prefix[1][1]=matrix[0][0];

       	// for(int i = 1 ; i < n ; i++)
       	// {
       	//     prefix[1][i]=prefix[0][i-1]+matrix[0][i-1];
       	// }
       	// for(int j = 1; j < m ; j++)
       	// {
       	//     prefix[j][1]= prefix[j-1][0]+matrix[j-1][0];
       	// }

        return prefix[row2 + 1][col2 + 1] - prefix[row2 + 1][col1] - prefix[row1][col2 + 1] + prefix[row1][col1];
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */