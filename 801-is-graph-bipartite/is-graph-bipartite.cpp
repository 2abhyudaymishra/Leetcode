class Solution {
public:
    bool canBeColored(vector<vector<int>>& graph ,int node, vector<int>&color){
        int neighbourColor = color[node]==0?1:0;
        
        for(auto neighbour: graph[node]){
            if(color[neighbour]==-1){
                color[neighbour] = neighbourColor;
                if(canBeColored(graph, neighbour, color)==false){
                    return false;
                }
            }else if(color[neighbour]!=neighbourColor)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int numOfVertices = graph.size();
        vector<int>color(numOfVertices,-1); //-1 = !visited
        
        for(int node=0; node<numOfVertices; node++){
            if(color[node]==-1){
                color[node]=0;
                if(canBeColored(graph, node, color)==false)return false;
            }
        }
        return true;
    }
};