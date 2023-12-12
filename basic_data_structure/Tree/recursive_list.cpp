#include <vector>

using namespace std;

struct Node{
    Node(int v) : val(v) {

    }

    Node* next;
    int val;
};

class RecursiveList{
public:
    void AddFirst(int val) {
        Node* newNode = new Node(val);
        newNode->next = _first;
        _first = newNode; 
        _size++;
    }

    void AddLast(int val) {
        Node* lastNode = LastNode();
        Node* newNode = new Node(val);
        lastNode->next = newNode;
        _size++;
    }

    int RemoveFirst() {
        Node* temp = _first;
        _first = _first->next;
        delete temp;
        _size--;
    }

    int RemoveLast() {
        _first = RemoveLastNode(_first);
        _size--;
    }

private:
    Node* LastNode() {
        return LastNode(_first);
    }

    Node* AddLast(int val, Node* n) {
        if (n == nullptr)
            return new Node(val);
        n = AddLast(val, n->next);
        return n;
    }

    // x->y->z->null
    Node* AddIndex(int val, int idx, Node* n) {
        if (idx == 1) {
            Node* newNode = new Node(val);
            newNode->next = n->next;
            return newNode;
        }

        n->next = AddIndex(val, idx-1, n->next);
        return n;
    }

    Node* RemoveIndex(int idx, Node* n) {
        if (idx == 0)
            return n->next;
        n->next = RemoveIndex(idx-1, n->next);
        return n;
    }

    Node* GetNode(int idx) {
        return GetNode(_first, idx);
    }

    Node* GetNode(Node* start, int idx){
        if (idx == 0)
            return start;
        return GetNode(start->next, idx-1);
    }

    Node* LastNode(Node* n) {
        if (n->next == nullptr)
            return n;
        return LastNode(n->next);
    }

    // 1->2->3->nullptr
    Node* RemoveLastNode(Node* n) {
        if (n->next == nullptr)
            return nullptr;

        n->next = RemoveLastNode(n->next);
        return n;
    }

private:
    Node* _first = nullptr;
    int _size = 0;
};