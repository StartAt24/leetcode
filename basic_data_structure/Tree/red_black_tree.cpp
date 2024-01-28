#include <map>

enum class Color{
    Red,
    Black
};

struct Node{
    int val=0;
    Node* left = nullptr;
    Node* right = nullptr;
    Color c; 
};

class RedBlackTree{

};