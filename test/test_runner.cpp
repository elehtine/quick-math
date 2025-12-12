#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cassert>
#include <numeric>

using Pair = std::pair<int, int>;
constexpr char nl = '\n';

constexpr std::string text = "abacabadabacaba";

#include "numbers/euclidean.cpp"
#include "string/kmp.cpp"
#include "string/z_func.cpp"
#include "graph/union_find.cpp"
#include "graph/dijkstra.cpp"


void test_euclidean() {
  int a = 4 * 3 * 25;
  int b = 2 * 9 * 5;
  int expected = 2 * 3 * 5;
  auto [x, y] = euclidean(a, b);
  assert(a*x + b*y == expected);

  std::cout << "[PASS] euclidean" << nl;
}

void test_kmp() {
  std::vector<int> prefix = kmp(text);
  std::vector<int> expected = {0, 0, 1, 0, 1, 2, 3, 0, 1, 2, 3, 4, 5, 6, 7};
  assert(prefix == expected);

  std::cout << "[PASS] KMP" << nl;
}

void test_z() {
  std::vector<int> z = zFunction(text);
  std::vector<int> expected = {0, 0, 1, 0, 3, 0, 1, 0, 7, 0, 1, 0, 3, 0, 1};
  assert(z == expected);

  std::cout << "[PASS] Z-function" << nl;
}

void test_union_find() {
  UnionFind uf(5);
  uf.join(0, 1);
  uf.join(2, 3);
  uf.join(1, 3);
  assert(uf.find(0) == uf.find(2));
  assert(uf.find(0) != uf.find(4));
  std::cout << "[PASS] Union-Find" << std::endl;
}

void test_dijkstra() {
  std::vector<std::vector<std::pair<int, int>>> adj(4);
  adj[0] = {{1, 4}, {2, 1}};
  adj[2] = {{1, 2}};
  adj[1] = {{3, 1}};

  auto dist = dijkstra(adj, 0);
  assert(dist[0] == 0);
  assert(dist[1] == 3);
  assert(dist[2] == 1);
  assert(dist[3] == 4);

  std::cout << "[PASS] Dijkstra" << std::endl;
}

int main() {
  test_euclidean();
  test_kmp();
  test_z();
  test_union_find();
  test_dijkstra();
  std::cout << "All algorithms passed." << nl;
}
