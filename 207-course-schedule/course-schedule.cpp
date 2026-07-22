class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        int evaluatedNodes = numCourses;
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses; i++){
            if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int temp = q.front();
            evaluatedNodes--;
            q.pop();
            for(auto node : adj[temp] ){
                indegree[node]--;
                if(indegree[node]==0)q.push(node);
            }
        }
        if(evaluatedNodes>0)return false;
        return true;
    }
};