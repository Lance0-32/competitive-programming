#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int parent[200010] = {};
int set_size[200010] = {};
int set_black[200010] = {};
int node_black[200010] = {};

void make_set(int v) {
    parent[v] = v;
    set_size[v] = 1;
    node_black[v] = 0;
    set_black[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void swap_color(int v) {
	int x = find_set(v);
	if (node_black[v] == 1) {
		node_black[v] = 0;
		set_black[x]--;
	} else {
		node_black[v] = 1;
		set_black[x]++;
	}
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (set_size[a] < set_size[b])
            swap(a, b);
        parent[b] = a;
        set_size[a] += set_size[b];
        set_black[a] += set_black[b];
    }
}

int main() {
	int n,q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		make_set(i);
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, v; cin >> u >> v;
			union_sets(u,v);
		} else if (t == 2) {
			int v; cin >> v;
			swap_color(v);
		} else if (t == 3) {
			int u; cin >> u;
			int v = find_set(u);
			if (set_black[v] > 0) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
	return 0;
}