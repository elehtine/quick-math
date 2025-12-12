std::vector<int> dijkstra(std::vector<std::vector<Pair>> adjacencyList, int start) {
  int n = adjacencyList.size();
  std::vector<int> distance(n, std::numeric_limits<int>::max());
  distance[0] = 0;

  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> queue;
  queue.emplace(0, start);

  while (!queue.empty()) {
    auto [d, node] = queue.top();
    queue.pop();

    if (d > distance[node]) continue;
    for (auto [next, weight]: adjacencyList[node]) {
      if (weight + d >= distance[next]) continue;
      distance[next] = weight + d;
      queue.emplace(distance[next], next);
    }
  }

  return distance;
}
