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
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if(node->neighbors.size() == 0)
            return new Node(node->val);
        
        unordered_map<Node*, Node*> tracker;

        Node* my_clone = new Node(node->val, {});
        tracker[node] = my_clone;
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            node =  q.front(); q.pop();

            for(auto nei: node->neighbors){
                if(tracker.find(nei) == tracker.end()){
                    tracker[nei] = new Node(nei->val);
                    q.push(nei);
                }
                tracker[node]->neighbors.push_back(tracker[nei]);
            }
        }

        return my_clone;


        // return dfs(node, tracker);
    }

    

    // Node* dfs(Node* node, unordered_map<Node*, Node*> &tracker){
    //     Node* cloned = new Node(node->val);
    //     vector<Node*> padosi;
    //     tracker[node] = cloned;


    //     for(auto nei: node->neighbors){
    //         if(tracker.find(nei) == tracker.end()){
    //             padosi.push_back(dfs(nei, tracker));
    //         }else{
    //             padosi.push_back(tracker[nei]);
    //         }
    //     }
    //     cloned->neighbors = padosi;

    //     return cloned;

    // }
};

