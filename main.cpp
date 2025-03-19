#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


char FILE_PATH[] = "graph.txt";


int main() {
	std::ifstream file(FILE_PATH);
	int n, m;
	file >> n >> m;
	std::vector<std::vector<int>> g;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		file >> v >> u; 
		g[v].push_back(u);
		g[u].push_back(v);
	}
	int sv;
	file >> sv;
	std::queue<int> q;
	q.push(sv);
	std::vector<int> res;
	res.resize(n);
	for (int i = 0; i < n; ++i)
		res[i] = -1;
	res[sv] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int j = 0; j < g[v].size(); ++j) {
			int u = g[v][j];
			if (res[u] == -1) {
				res[u] = res[v] + 1;
				q.push(u);
			}
		}
	}
	for (int i = 0; i < res.size(); ++i)
		std::cout << res[i] << '\n';
	return 0;
}