#include <iostream>

template<typename E>
class ArrayList{
    ArrayList() {
        m_pArr = new E[m_capacity];
    }
    ~ArrayList() {
        if (m_pArr)
            delete[] m_pArr;
    }

    void addLast(E e) {
        if (m_capacity == m_size) {
            resize(m_capacity*2);
        }
        m_pArr[size] = e;
        m_size++;
    }

    bool add(int idx, E e) {
        if (!isPositionIndex(idx))
            return false; 
        
    }

    void removeLast(int index) {
        if (isEmpty())
            return;
        m_size--;
        // element will be clear in resize function.
        if (m_size < m_capacity/4) {
            resize(m_capacity/2);
        }
    }
    
private:
    E* m_pArr = nullptr;
    // current size of elements
    int m_size = 0;
    int m_capacity = 1;

private:
    void resize(int newCap) {
        E* pOldArr = m_pArr;
        m_pArr = new E[newCap];
        m_capacity = newCap;

        // copy data
        for (int i=0; i<m_size; i++) {
            m_pArr[i] = pOldArr[i];
        }

        if (pOldArr) {
            delete[] pOldArr;
        }
    }

    bool isEmpty() {
        return m_size == 0;
    }

    bool isElementIndex(int idx) {
        return idx>=0 && idx < m_size;
    }

    // position index is the location where you add new element.
    bool isPositionIndex(int idx) {
        return idx>=0 && idx <= m_size;
    }
};