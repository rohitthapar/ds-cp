#include <iostream>
#include <vector>
#include <algorithm>

void DFS(int v, std::vector<bool>& visited, std::vector<std::vector<std::pair<int, int>>>& adjlist) {
    visited[v] = true;
    for (const auto& neighbor : adjlist[v]) {
        if (!visited[neighbor.first]) {
            DFS(neighbor.first, visited, adjlist);
        }
    }
}

int count_components(std::vector<std::vector<std::pair<int, int>>>& adjlist) {
    std::vector<bool> visited(adjlist.size(), false);
    int count = 0;
    for (int vertex = 1; vertex < adjlist.size(); vertex++) {
        if (!visited[vertex]) {
            DFS(vertex, visited, adjlist);
            count++;
        }
    }
    return count;
}

int getlat(int g_nodes, std::vector<int>& g_from, std::vector<int>& g_to, std::vector<int>& g_weight, int k) {
    std::vector<std::vector<std::pair<int, int>>> adjlist(g_nodes + 1);
    std::vector<std::pair<int, std::pair<int, int>>> zipped_lists;
    for (int i = 0; i < g_from.size(); i++) {
        zipped_lists.push_back(std::make_pair(g_weight[i], std::make_pair(g_to[i], g_from[i])));
    }
    std::sort(zipped_lists.begin(), zipped_lists.end());
    for (const auto& item : zipped_lists) {
        int weight = item.first;
        int to = item.second.first;
        int from = item.second.second;
        adjlist[from].push_back(std::make_pair(to, weight));
        adjlist[to].push_back(std::make_pair(from, weight));
    }
    int remptr = g_from.size() - 1;
    int res = 0;
    while (k >= count_components(adjlist) && remptr >= 0) {
        int u = g_from[remptr];
        int v = g_to[remptr];
        res = std::max(res, *std::max_element(g_weight.begin(), g_weight.begin() + remptr + 1));
        adjlist[u].erase(std::remove_if(adjlist[u].begin(), adjlist[u].end(), [v](const std::pair<int, int>& item) {
            return item.first == v;
        }), adjlist[u].end());
        adjlist[v].erase(std::remove_if(adjlist[v].begin(), adjlist[v].end(), [u](const std::pair<int, int>& item) {
            return item.first == u;
        }), adjlist[v].end());
        remptr--;
    }
    return res;
}