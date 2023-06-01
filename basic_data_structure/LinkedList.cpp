template <typename T>
class LinkedList{
public:
    LinkedList() {
        m_pHead = new Node();
        m_pTail = new Node();
        m_pHead->next = m_pTail;
        m_pTail->prev = m_pHead;
    };

    ~LinkedList() {
        if (m_pHead) {
            Node* temp = m_pHead;
            while(temp && temp->next) {
                Node* x = temp; 
                temp = temp->next;
                delete x;
            }
            delete temp;
        }
    }

    // add
    void addFirst(T t) {
        Node* newNode = new Node(t);
        Node* temp = m_pHead->next;
        m_pHead->next = newNode;
        newNode->prev = m_pHead;
        temp->prev = newNode;
        newNode->next = temp;
        m_size++;
    }

    void addLast(T t) {
        Node* newNode = new Node(t);
        Node* temp = m_pTail->prev;

        newNode->prev = temp;
        newNode->next = m_pTail;

        m_pTail->prev = newNode;
        temp->next = newNode;

        m_size++;
    }

    void add(int idx, T t) {
        auto p = getNode(idx);
        auto temp = p->prev;
        // temp->p 
        // temp->x->p

        Node* x = new Node(t);
        x->next = p;
        x->prev = temp;

        temp->next = x;
        p->prev = x;

        m_size++;
    }

    // delete
    bool removeFirst() {
        if (isEmpty()) {
            return false;
        }
        Node* x = m_pHead->next;
        Node* temp = x->next;
        // head->x->temp;
        m_pHead->next = temp;
        temp->prev = m_pHead;
        x->next = x->prev = nullptr;
        delete x;
        m_size--;
        return true;
    }

    bool removeLast() {
        if (isEmpty()) {
            return false;
        }
        Node* x = m_pTail->prev;
        Node* temp = x->prev;
        // temp->x->tail;
        temp->next = m_pTail;
        m_pTail->prev = temp;
        x->next = x->prev = nullptr;
        delete x;
        m_size--;
        return true;
    }

    bool remove(int idx) {
        if (isElementIndex(idx)) {
            return false;
        }
        Node* x = getNode(idx);
        Node* prev = x->prev;
        Node* next = x->next;
        // prev->x->next
        prev->next = next;
        next->prev = prev;

        x->next = x->prev = nullptr;
        delete x;
        m_size--;
        return true;
    }

    // modify
    bool set(int idx, T t) {
        if (isElementIndex(idx)) {
            return false;
        }
        auto x = getNode(idx);
        x->value = t;
        return true;
    }

    // query
    bool get(int idx, T& out) {
        if (isElementIndex(idx)) {
            return false;
        }
        out = getNode(idx)->value;
        return true;
    }

private:
    struct Node {
        Node(T t) {
            value = t;
        }
        Node() = default;

        Node* prev = nullptr;
        Node* next = nullptr;
        T value{};
    };

    Node* m_pHead=nullptr, m_pTail=nullptr;
    int m_size = 0;

    bool isElementIndex(int i) {
        return i>=0 && i<m_size;
    }

    bool isPositionIndex(int i) {
        return i>=0 && i<=m_size;
    }

    bool isEmpty() {
        return m_size == 0;
    }

    Node* getNode(int index) {
        Node* p = m_pHead->next;
        for (int i=0; i<index; i++) {
            p = p->next;
        }
        // optimize
        #if 0
        if (index < _size>>1) {
            // element stores in the first half.
            Node* p = m_pHead.next;
            for (int i=0; i<index; i++) {
                p = p.next;
            }
        } else {
            int step = _size - 1 - index;
            Node* p = m_pTail->prev;
            for (int i=0; i<step; i++) {
                p = p->prev;
            }
        }
        #endif;

        /*
        while (index--) {
            p = p.next;
        }
        */ 
        return p;
    }
};