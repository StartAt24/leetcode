struct Node{
    Node* next;
    int val;
};

Node* MergeTwoList(Node* l1, Node* l2) {
    if (!l1 && !l2) {
        return nullptr;
    }

    if (l1 && !l2)
        return l1;
    
    if (!l1 && l2) 
        return l2;

    Node* ret = nullptr;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            ret = 
        }
    }

}