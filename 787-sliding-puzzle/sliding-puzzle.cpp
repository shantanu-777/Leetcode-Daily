class Solution {

private:

    vector<int> getPos(vector<vector<int>>&state){
        for(int i=0;i<2;++i){
            for(int j=0;j<3;++j){
                if(state[i][j]==0){
                    return {i,j};
                }
            }
        }
        return {};
    }

    void swap(vector<vector<int>>&state, int x1, int y1, int x2, int y2){
        int elem = state[x1][y1];
        state[x1][y1]=0;
        state[x2][y2]=elem;
    }

    bool isValid(int x,int y){
        if(x>=0 && x<2 && y>=0 && y<3){return true;}
        return false;
    }

    string flatten(vector<vector<int>>& state){
        string ans="";
        for(int i=0;i<2;++i){
            for(int j=0;j<3;++j){
                ans+=to_string(state[i][j]);
            }
        }
        return ans;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>soln = {{1,2,3},{4,5,0}};
        queue<pair<vector<vector<int>>,int>>q;
        vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        set<string> visited;
        q.push({board,0});
        while(!q.empty()){
            auto state = q.front().first;
            int moves = q.front().second;
            q.pop();
            if(state==soln){return moves;}
            auto pos = getPos(state);int x=pos[0];int y=pos[1];
            for(auto &dir:dirs){
                int new_x=x+dir[0];int new_y=y+dir[1];
                if(isValid(new_x,new_y)){
                    swap(state,new_x,new_y,x,y);
                    string f = flatten(state);
                    if(visited.find(f)!=visited.end()){
                        swap(state,x,y,new_x,new_y);
                        continue;
                    }
                    else{
                        visited.insert(f);
                        q.push({state,moves+1});
                        swap(state,x,y,new_x,new_y);
                    }
                }
            }
        }
        return -1;
    }
};