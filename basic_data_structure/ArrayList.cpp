#include <iostream>

template<typename E>
class ArrayList{
    ArrayList () {

    }

    void add(E e) {

    }

    void remove(int index) {

    }
    
private:
    E* m_pArr = nullptr;
    int size = 0;

private:

    void resize(int newCap) {
        E* pOldArr = m_pArr;
        m_pArr = new E[newCap];
        if (pOldArr) {
            delete pOldArr;
        }
    }
};