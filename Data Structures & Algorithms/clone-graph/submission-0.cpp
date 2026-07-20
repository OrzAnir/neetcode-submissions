/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneHelp(Node* node, map<Node*, Node*>& mpp) {
        Node* new_node = new Node(node->val);
        mpp[node] = new_node;
        for (auto it : node->neighbors) {
            if (mpp.find(it) != mpp.end()) new_node->neighbors.push_back(mpp[it]);
            else {
                new_node->neighbors.push_back(cloneHelp(it, mpp));
            }
        }
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        map<Node*, Node*> mpp;
        return cloneHelp(node, mpp);
    }
};
