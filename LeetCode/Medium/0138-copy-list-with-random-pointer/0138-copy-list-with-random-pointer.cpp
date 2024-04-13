/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node* cur = head;
        while(cur) {
           Node *node = new Node(cur -> val);
           node -> next = cur -> next;
           cur -> next = node;
           cur = node -> next;
        }

        cur = head;
        Node* ret = head -> next;
        while(cur) {
            if(cur -> random) {
                cur -> next -> random = cur -> random -> next;
            }
            else   
                cur -> next -> random = nullptr;
            cur = cur -> next -> next;
        }

        cur = head;
        while(cur) {
            Node* tmp = cur -> next;
            cur -> next = cur -> next -> next;
            cur = cur -> next;

            if(cur)
                tmp -> next = cur -> next;
        }
        return ret;
    
    }
};