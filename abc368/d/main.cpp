#include <iostream>
#include <vector>
#include <set>

const int MAX_N = 2e5 + 5;

std::vector<int> adj[MAX_N];
std::set<int> required_vertices;
int min_vertices = MAX_N;

int dfs(int v, int parent) {
    int subtree_size = 1;
    int required_count = required_vertices.count(v);

    for (int u : adj[v]) {
        if (u != parent) {
            int child_result = dfs(u, v);
            subtree_size += child_result;
            if (required_vertices.count(u) || child_result > 0) {
                required_count++;
            }
        }
    }

    if (required_count == required_vertices.size()) {
        min_vertices = std::min(min_vertices, subtree_size);
    }

    return (required_count > 0 || required_vertices.count(v)) ? subtree_size : 0;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < K; i++) {
        int v;
        std::cin >> v;
        required_vertices.insert(v);
    }

    dfs(1, 0);

    std::cout << min_vertices << std::endl;

    return 0;
}
