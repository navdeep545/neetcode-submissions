class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Handle edge case for an empty matrix
        if (matrix.empty() || matrix[0].empty()) return {};

        int rows = matrix.size(), cols = matrix[0].size();
        int rowStart = 0, rowEnd = rows - 1;
        int colStart = 0, colEnd = cols - 1;

        vector<int> result;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Traverse from left to right
            for (int col = colStart; col <= colEnd; ++col) {
                result.push_back(matrix[rowStart][col]);
            }
            ++rowStart;

            // Traverse from top to bottom
            for (int row = rowStart; row <= rowEnd; ++row) {
                result.push_back(matrix[row][colEnd]);
            }
            --colEnd;

            // Traverse from right to left, if still within bounds
            if (rowStart <= rowEnd) {
                for (int col = colEnd; col >= colStart; --col) {
                    result.push_back(matrix[rowEnd][col]);
                }
                --rowEnd;
            }

            // Traverse from bottom to top, if still within bounds
            if (colStart <= colEnd) {
                for (int row = rowEnd; row >= rowStart; --row) {
                    result.push_back(matrix[row][colStart]);
                }
                ++colStart;
            }
        }

        return result;
    }
};
