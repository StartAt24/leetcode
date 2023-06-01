class MyLinkedList {
public:
    MyLinkedList() {
        _pHead = new Node();
    }
    // 1, 2, 7 
    int get(int index) {
        if(!isValidIndex(index)) {
            return -1;
        }
        return getIndex(index)->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        Node* temp = getIndex(0);
        // head->newNode;
        _pHead->next = newNode;
        newNode->next =temp;
        _size++;
    }

    void addAtTail(int val) {
        // get last node;
        Node* temp = _pHead;
        while(temp && temp->next) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        temp->next = newNode;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (!isValidInsertIndex(index))
            return;

        Node* prev = getIndex(index-1);
        Node* next = prev->next;

        // newNode->temp
        Node* newNode = new Node(val);
        prev->next = newNode;
        newNode->next = next;
        
        _size++;
    }

    void deleteAtIndex(int index) {
        if (!isValidIndex(index))
            return;
        Node* prev = getIndex(index-1);
        Node* current = prev->next;
        Node* next = current->next;
        prev->next = next;
        current->next = nullptr;
        delete current;
        _size--;
    }

private:
    struct Node{
        Node(int value) : val(value) {

        }
        Node() = default;
        Node* next = nullptr;
        int val = 0;
    };

    Node* getIndex(int index) {
        if (index == -1)
            return _pHead;

        if (!isValidIndex(index)) 
            return nullptr;

        // at least one element;
        Node* temp = _pHead->next;        
        for (int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    bool isEmpty() {
        return _size == 0;
    }

    bool isValidIndex(int index) {
        return index>=0 && index<_size;
    }

    bool isValidInsertIndex(int index) {
        return index>=0 && index<=_size;
    }

    int _size = 0;
    Node* _pHead = nullptr;
};

int main () {
    MyLinkedList l;
    l.addAtHead(7);
    l.addAtHead(2);
    l.addAtHead(1);
    l.addAtIndex(3,0);
    return 0;
}