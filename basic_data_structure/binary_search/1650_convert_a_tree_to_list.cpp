class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* parent;
};

Node* lowestCommonAncestor(Node* p, Node* q)
{
    Node *a = p, *b = q;
    while (a != b) {
        if (!a)
            a = q;
        else 
            a = a->parent;
        
        if (!b)
            b = p;
        else 
            b = b->parent;
    }
    return a;
}