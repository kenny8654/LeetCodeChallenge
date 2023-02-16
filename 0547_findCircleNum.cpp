/**
Runtime: 23 ms, Beats: 84.49%
Memory: 14.1 MB, Beats: 53.22%
**/
class Solution {
private:
    int citySize;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ret = 0;
        citySize = isConnected.size();
        vector<bool> isVisited(citySize, false);

        for(int i=0; i<citySize; i++){
            if(isVisited[i]) 
                continue;

            ret++;
            queue<int> que;
            isVisited[i] = true;
            que.push(i);
            while(!que.empty()){
                BFS(isConnected, isVisited, que, que.front());
                que.pop();
            }
            
        }
        return ret;
    }

    void BFS(vector<vector<int>>& isConnected, vector<bool>& isVisited, queue<int>& que, int i){
        for(int j=0; j<citySize; j++){
            if(!isVisited[j] && i != j && isConnected[i][j]){
                isVisited[j] = true;
                que.push(j);
            }
        }
    }
};
