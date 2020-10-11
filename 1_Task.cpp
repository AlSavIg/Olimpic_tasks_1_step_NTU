#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef struct {
	int i;
	int j;
} pos_t;

int main() {
	int n, m;
	cin >> n >> m;
	//init
	vector<vector<vector<pos_t> > > map_adj; //i, j, array of pos_t
	for (int i = 0; i < n+1; i++) {
		vector<vector<pos_t> > temp_row;
		for (int j = 0; j < m+1; j++) {
			vector<pos_t> temp_ways;
			temp_row.push_back(temp_ways);
		}
		map_adj.push_back(temp_row);
	}
	
	//input
	for (int i = 0; i < n +1; i++) {
		string draw, poke;
		cin >> draw;
		if (i != n)
			cin >> poke;
		for (int j = 0; j < m; j++) {
			if (draw[j] == 'e'){
				pos_t temp_pos = {i, j+1};
				map_adj[i][j].push_back(temp_pos);
			}
		}
		for (int j = 0; j < m+1 && i != n; j++) {
			if (poke[j] == 'n'){
				pos_t temp_pos = {i, j};
				map_adj[i+1][j].push_back(temp_pos);
			}	
		}
		for (int j = 0; j < m+1 && i != n; j++) {
			if (poke[j] == 's'){
				pos_t temp_pos = {i+1, j};
				map_adj[i][j].push_back(temp_pos);
			} 
		}
		for (int j = 0; j < m; j++) {
			if (draw[j] == 'w'){
				pos_t temp_pos = {i, j};
				map_adj[i][j+1].push_back(temp_pos);
			}
		}
	}
	
	//bfs
	n++;m++;
	pos_t s = {0, 0};
	queue<pos_t> q;
	q.push(s);
	vector<vector<bool> > used;
	for (int i = 0; i < n; i++){
		vector<bool> temp(m);
		used.push_back(temp);
	}
	vector<vector<int> > d;
	vector<vector<pos_t> > p;
	for (int i = 0; i < n; i++){
		vector<int> temp_d(m);
		vector<pos_t> temp_p(m);
		d.push_back(temp_d);
		p.push_back(temp_p);
	}
	used[s.i][s.j] = true;
	pos_t temp_pos = {-1, -1};
	p[s.i][s.j] = temp_pos;
	while (!q.empty()) {
		pos_t v = q.front();
		q.pop();
		for (size_t i=0; i<map_adj[v.i][v.j].size(); ++i) {
			pos_t to = map_adj[v.i][v.j][i];
			if (!used[to.i][to.j]) {
				used[to.i][to.j] = true;
				q.push(to);
				d[to.i][to.j] = d[v.i][v.j] + 1;
				p[to.i][to.j] = v;
			}
		}
	}
	
	cout << d[n-1][m-1] << endl;
	
	vector<pos_t> path;
	pos_t target = {n-1, m-1};
	for (pos_t v=target; v.i!=-1; v=p[v.i][v.j]) {
		path.push_back (v);
	}
	for (int i=path.size() -1; i>=1; i--){
		if (path[i].i - path[i-1].i == -1)
			cout << 's';
		else if (path[i].i - path[i-1].i == 1)
			cout << 'n';
		else if (path[i].j - path[i-1].j == -1)
			cout << 'e';
		else if (path[i].j - path[i-1].j == 1)
			cout << 'w';
	}
	return 0;
}
