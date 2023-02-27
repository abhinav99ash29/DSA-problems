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

    int check(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        bool o = false, z = false;
        for(int i=x1;i<=x2;i++) {
            for(int j=y1;j<=y2;j++) {
                if (grid[i][j] == 1) o = true;
                if (grid[i][j] == 0) z = true;
            }
        }
        if (o && z) return -1;
        if (o) return 1;
        if (z) return 0;
        return -1;
    }

    Node* fn(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        int ch = check(grid,x1,y1,x2,y2);
        if (ch != -1) {
            Node* node = new Node(ch, true);
            return node;
        }
        int xmid = (x1+x2)/2;
        int ymid = (y1+y2)/2;
        Node* node = new Node(0, false,
        fn(grid,x1,y1,xmid,ymid),fn(grid,x1,ymid+1,xmid,y2),
        fn(grid,xmid+1,y1,x2,ymid), fn(grid,xmid+1,ymid+1,x2,y2));
        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return fn(grid,0,0,n-1,n-1);
    }
};
