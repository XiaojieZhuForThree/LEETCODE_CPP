#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using std::string;
using std::vector;

struct TrieNode {
  std::unordered_map<string, std::shared_ptr<TrieNode>> children;
  bool deleted = false;
};

class Solution {
 public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    vector<vector<string>> ans;
    vector<string> path;
    std::unordered_map<string, vector<std::shared_ptr<TrieNode>>> subtreeToNodes;

    std::ranges::sort(paths);

    for (const vector<string>& path : paths) {
      std::shared_ptr<TrieNode> node = root;
      for (const string& s : path) {
        if (!node->children.count(s))
          node->children[s] = std::make_shared<TrieNode>();
        node = node->children[s];
      }
    }

    buildSubtreeToRoots(root, subtreeToNodes);

    for (const auto& [_, nodes] : subtreeToNodes)
      if (nodes.size() > 1)
        for (std::shared_ptr<TrieNode> node : nodes)
          node->deleted = true;

    constructPath(root, path, ans);
    return ans;
  }

 private:
  std::shared_ptr<TrieNode> root = std::make_shared<TrieNode>();

  string buildSubtreeToRoots(
      std::shared_ptr<TrieNode> node,
      std::unordered_map<string, vector<std::shared_ptr<TrieNode>>>& subtreeToNodes) {
    string subtree = "(";
    for (const auto& [s, child] : node->children)
      subtree += s + buildSubtreeToRoots(child, subtreeToNodes);
    subtree += ")";
    if (subtree != "()")
      subtreeToNodes[subtree].push_back(node);
    return subtree;
  }

  void constructPath(std::shared_ptr<TrieNode> node, vector<string>& path,
                     vector<vector<string>>& ans) {
    for (const auto& [s, child] : node->children)
      if (!child->deleted) {
        path.push_back(s);
        constructPath(child, path, ans);
        path.pop_back();
      }
    if (!path.empty())
      ans.push_back(path);
  }
};