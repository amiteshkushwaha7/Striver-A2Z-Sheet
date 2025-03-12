class Solution {
    public: 
      bool isSafe(int node, int color, map<int, int> &coloured, multimap<int, int> &graph) {
      auto range = graph.equal_range(node);
      for (auto it = range.first; it != range.second; ++it) {
          if (coloured[it->second] == color)  // Check if any adjacent node has the same color
              return false;
      }
      return true;
  }
  
  void solve(vector<int> &nodes, multimap<int, int> &graph, map<int, int> &coloured, int m, int index, bool &flag) {
      if (index == nodes.size()) {  // If all nodes are colored
          flag = true;
          return;
      }
  
      int node = nodes[index];
  
      for (int c = 1; c <= m; c++) {  // Try different colors
          if (isSafe(node, c, coloured, graph)) {
              coloured[node] = c;
  
              solve(nodes, graph, coloured, m, index + 1, flag);
  
              if (flag) return;  // Stop if solution found
  
              coloured[node] = 0;  // Backtrack
          }
      }
  }
  
  bool graphColoring(int v, vector<pair<int, int>> &edges, int m) {
      bool flag = false;
      multimap<int, int> graph;
      map<int, int> coloured;
      set<int> nodes;
  
      // Construct the graph and initialize colors
      for (auto p : edges) {
          graph.insert({p.first, p.second});
          graph.insert({p.second, p.first});
          nodes.insert(p.first);
          nodes.insert(p.second);
          coloured[p.first] = 0;
          coloured[p.second] = 0;
      }
  
      vector<int> nodeList(nodes.begin(), nodes.end()); // Convert set to vector for indexed access
  
      solve(nodeList, graph, coloured, m, 0, flag);
  
      return flag;
  }
  };