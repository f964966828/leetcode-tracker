/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> subvector(vector<vector<int>>& grid, int dir){
        // dir -> 0:topLeft, 1: topRight, 2: bottomLeft, 3: bottomRight
        int n = grid.size();
        int rbegin[] = {0, 0, n/2, n/2};
        int cbegin[] = {0, n/2, 0, n/2};
        
        vector<vector<int>> ret(n/2, vector<int>(n/2));
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                ret[i][j] = grid[i+rbegin[dir]][j+cbegin[dir]];
            }
        }

        return ret;
    }

    Node* construct(vector<vector<int>> grid) {
        int n = grid.size();
        int val = grid[0][0];
        bool isLeaf = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                if(grid[i][j] != val) isLeaf = false;
        }

        if(isLeaf){
            Node* node = new Node(val, isLeaf);
            return node;
        }else{
            Node* node = new Node(
                val, isLeaf,
                construct(subvector(grid, 0)),
                construct(subvector(grid, 1)),
                construct(subvector(grid, 2)),
                construct(subvector(grid, 3))
            );

            return node;
        }
    }
};
