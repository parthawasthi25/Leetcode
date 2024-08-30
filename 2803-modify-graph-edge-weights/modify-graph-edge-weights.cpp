class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
         long long shortestDistance = dijkstra(edges, n, source, destination);
        if (shortestDistance < target) { 
            return {};
        }
        bool isEqualToTarget = shortestDistance == target;
        for (auto& edge : edges) {
            if (edge[2] > 0) { 
                continue;
            }
            if (isEqualToTarget) { 
                edge[2] = 2e9;
                continue;
            }
            edge[2] = 1;
            shortestDistance = dijkstra(edges, n, source, destination);
            if (shortestDistance <= target) { 
                isEqualToTarget = true;
                edge[2] += target - shortestDistance;
            }
        }
        return isEqualToTarget ? edges : vector<vector<int>>{};
    }
    long long dijkstra(const vector<vector<int>>& edges, int n, int src, int dest) {
        long long graph[n][n];
        long long distance[n];
        bool visited[n];
        for (int i = 0; i < n; ++i) {
            fill(graph[i], graph[i] + n, 2e9);
            distance[i] = 2e9;
            visited[i] = false;
        }
        distance[src] = 0;
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            if (weight == -1) {
                continue;
            }
            graph[from][to] = weight;
            graph[to][from] = weight;
        }
        for (int i = 0; i < n; ++i) {
            int closestUnvisitedNode = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (closestUnvisitedNode == -1 || distance[j] < distance[closestUnvisitedNode])) {
                    closestUnvisitedNode = j;
                }
            }
            visited[closestUnvisitedNode] = true;
            for (int j = 0; j < n; ++j) {
                distance[j] = min(distance[j], distance[closestUnvisitedNode] + graph[closestUnvisitedNode][j]);
            }
        }
        return distance[dest];
    }
};