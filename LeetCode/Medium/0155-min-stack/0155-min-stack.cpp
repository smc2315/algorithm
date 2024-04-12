class MinStack {
    struct Node {
    int val;
    int minVal;
    Node* next;

    Node(int v, int minV, Node* n):val(v), minVal(minV), next(n) {

    }
 };
 Node* head;
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if(head == nullptr)
            head = new Node(val, val, nullptr);      
        else
            head = new Node(val, min(head -> minVal, val), head);
        
    }
    
    void pop() {
        head = head -> next;
    }
    
    int top() {
        return head -> val;
    }
    
    int getMin() {
        return head -> minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */