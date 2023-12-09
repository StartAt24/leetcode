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

        _size--;
    }

    int RemoveLast() {
        _size--;
    }

private:
    Node* LastNode() {
        return LastNode(_first);
    }

    Node* LastNode(Node* n) {
        if (n->next == nullptr)
            return n;
        return LastNode(n->next);
    }

private:
    Node* _first = nullptr;
    int _size = 0;
};