#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;
int soDinh, soCanh; // số đỉnh và số cạnh của đồ thị
vector<pair<int, int> > adj[100001]; // danh sách kề của đồ thị
int khoangCach[100001]; // mảng lưu trữ khoảng cách ngắn nhất từ đỉnh bắt đầu đến các đỉnh khác
bool visited[100001]; // mảng kiểm tra các đỉnh đã được xét đến hay chưa
void Dijkstra(int start) {
    // Khởi tạo mảng khoảng cách và mảng visited
    for (int i = 1; i <= soDinh; i++) {
        khoangCach[i] = INF;
        visited[i] = false;
    }
    // Khởi tạo đỉnh bắt đầu và khoảng cách tới nó bằng 0
    khoangCach[start] = 0;
    // Tạo hàng đợi ưu tiên để lưu trữ các đỉnh cần xét đến
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(khoangCach[start], start));
    // Duyệt qua đồ thị
    while (!pq.empty()) {
        // Lấy đỉnh có khoảng cách ngắn nhất từ hàng đợi
        pair<int, int> current = pq.top();
        pq.pop();
        int u = current.second;
        // Nếu đỉnh đã được xét đến trước đó, bỏ qua
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            // Nếu đỉnh chưa được xét đến và khoảng cách hiện tại từ đỉnh bắt đầu đến đỉnh kề nhỏ hơn khoảng cách hiện tại của đỉnh kề, cập nhật khoảng cách
            if (!visited[v] && khoangCach[u] + weight < khoangCach[v]) {
                khoangCach[v] = khoangCach[u] + weight;
                pq.push(make_pair(khoangCach[v], v));
            }
        }
    }
}
int main() {
    cin >> soDinh>> soCanh;
    // Đọc thông tin về các cạnh của đồ thị
    for (int i = 0; i < soCanh; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }
    // Tìm đường đi ngắn nhất từ đỉnh 1 đến đỉnh n
    Dijkstra(1);
    // In ra khoảng cách ngắn nhất từ đỉnh 1 đến đỉnh n
    cout << khoangCach[soDinh] << endl;
    return 0;
}