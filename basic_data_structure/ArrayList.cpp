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
        m_pArr[m_size] = e;
        m_size++;
    }

    bool add(int idx, E e) {
        if (!isPositionIndex(idx))
            return false;
        // data[idx..] move to data[idx+1 ..]
        int elementCountToMove = m_size -idx;
        if (elementCountToMove == 0) {
            m_pArr[idx] = e;
            m_size++;
            return true;
        }

        for (int i=m_size; i>idx; i--) {
            m_pArr[i] = m_pArr[i-1];
        }

        m_pArr[idx] = e;
        m_size++;
        return true;
    }

    bool get(int idx, E& out) {
        if (!isElementIndex(idx)) {
            return false;
        }
        out = m_pArr[idx];
        return true;
    }

    bool set(int idx, E in) {
        if (!isElementIndex(idx)) {
            return false;
        }
        m_pArr[idx] = in;
        return true;
    }

    void removeLast() {
        if (isEmpty())
            return;
        m_size--;
        // element will be clear in resize function.
        if (m_size < m_capacity/4) {
            resize(m_capacity/2);
        }
    }

    void removeIndex(int idx) {
        if (!isElementIndex(idx))
            return;
        // clear element
        m_pArr[idx].~E();
        // move other elements
        if (idx == m_size-1) {
            m_size--;
            return;
        }

        for (int i=idx; i<m_size-1; i++) {
            m_pArr[idx] = m_pArr[idx+1];
        }
        // clear last elemet;
        m_pArr[m_size-1].~E();

        m_size--;
        return;
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