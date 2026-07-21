class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> s(n+2,0);
        for(int i=0; i<n; i++){
            int x=edges[i][0];
            int y=edges[i][1];
            if(s[x]!=0) return x;
            if(s[y]!=0) return y;
            s[x]++;
            s[y]++;
        }
        return 0;
    }
};