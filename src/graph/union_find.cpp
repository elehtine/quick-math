class UnionFind {
  public:
    UnionFind(int n): parent(n), size(n, 1) {
      std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
      if (parent[node] == node) return node;
      return find(parent[node]);
    }

    void join(int left, int right) {
      left = find(left);
      right = find(right);
      if (left == right) return;
      if (size[left] < size[right]) {
        std::swap(left, right);
      }
      parent[right] = left;
      size[left] += size[right];
    }

  private:
    std::vector<int> parent;
    std::vector<int> size;
};
