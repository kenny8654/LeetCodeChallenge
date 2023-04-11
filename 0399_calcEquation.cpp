class Solution {
/**
Runtime: 0 ms, Beats: 100%
Memory: 8.3 MB, Beats: 57.62%
**/
  public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ret;
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i=0; i<equations.size(); i++){
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = double(1/values[i]);
        }
        for(auto &querie:queries){
            unordered_set<string> isVisit;
            double ans = dfs(graph, isVisit, querie[0], querie[1]);
            if(ans)
                ret.push_back(ans);
            else
                ret.push_back(-1.0);
            
        }
        return ret;
    }

    double dfs(unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string> isVisit, string top, string but) {
        if(graph[top].find(but) != graph[top].end())
            return graph[top][but];

        for(auto &dict:graph[top]){
            if(isVisit.find(dict.first) != isVisit.end())
                continue;
            isVisit.insert(dict.first);
            double ans = dfs(graph, isVisit, dict.first, but); 
            if(ans)
                return graph[top][dict.first] * ans;
        }
        return 0;
    }
};
