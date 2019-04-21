
#ifndef RedBlackTreeClass_h
#define RedBlackTreeClass_h


#include<iostream>
#include "listTemplate.h"

//Перенести нужные значения в private

using namespace std;

template <class T, class V> class RedBlackTree;
template <class T, class V> class Node;

// Defiining the class RedBlack Tree
template <class T, class V>
class RedBlackTree {
public:
    Node<T, V> *root;
    Node<T, V> *NIL;
    RedBlackTree() {
        NIL = new Node<T, V>();
        root = NIL;
    }
    ~RedBlackTree() {
        clear();
    }
    void insert(T key, V value);
    void turnLeft(Node<T, V> *x);
    void turnRight(Node<T, V> *x);
    void insertFix(Node<T, V> *fixNode);
    void remove(T key);
    void fixRemove(Node<T, V> *fixNode);
    void clear();
    MyList<T> get_keys();
    MyList<V> get_values();
    Node<T, V> *find(T key);
};

template <class T, class V>
class Node {
public:
    T key;
    bool color; //if true then color red, else color black
    V value;
    Node *left;
    Node *right;
    Node *parent;
    Node();
    Node(T key, V value, Node *parent);
    ~Node();
    void clearNode();
    MyList<T> get_keys_Node(MyList<T> keyList);
    MyList<T> get_values_Node(MyList<V> valueList);
    friend class RedBlackTree<T, V>;
};

template <class T, class V>
RedBlackTree<T, V> *Tree = new RedBlackTree<T, V>();
//Defining Node methods

template <class T, class V>
Node<T, V>::Node() {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    color = false;
    this->key = 0;
    this->value = 0;
}

template <class T, class V>
Node<T, V>::Node (T key, V value, Node *parent) {
    this->left = Tree<T, V>->NIL;
    this->right = Tree<T, V>->NIL;
    this->parent = parent;
    this->key = key;
    this->color = true;
    this->value = value;
    this->right->parent = this;
    this->left->parent = this;
}

template <class T, class V>
Node<T, V>::~Node() {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    key = 0;
    value = 0;
}

template <class T, class V>
void Node<T, V>::clearNode() {
    if (this != nullptr && this->key != 0) {
        left->clearNode();
        right->clearNode();
        delete this;
    }
}

template <class T, class V>
MyList<T> Node<T, V>::get_keys_Node(MyList<T> keyList) {
    if (this->key != 0 && this != nullptr) {
        keyList = left->get_keys_Node(keyList);
        keyList = right->get_keys_Node(keyList);
        keyList.push_back(this->key);
    }
    return keyList;
}

template <class T, class V>
MyList<T> Node<T, V>::get_values_Node(MyList<V> valueList) {
    if (this->key != 0 && this != nullptr) {
        valueList = left->get_values_Node(valueList);
        valueList = right->get_values_Node(valueList);
        valueList.push_back(this->value);
    }
    return valueList;
}
//Defining RedBlackTree methods

template <class T, class V>
void RedBlackTree<T, V>::turnLeft (Node<T, V> *fixingNode) {
    Node<T, V> *rightSon = fixingNode->right;
    fixingNode->right = rightSon->left;
    if (rightSon->left != NIL) {
        rightSon->left->parent = fixingNode;
    }
    if (rightSon != NIL) {
        rightSon->parent = fixingNode->parent;
    }
    if (fixingNode->parent != NIL) {
        if (fixingNode == fixingNode->parent->left) {
            fixingNode->parent->left = rightSon;
        }
        else {
            fixingNode->parent->right = rightSon;
        }
    }
    else {
        root = rightSon;
    }
    rightSon->left = fixingNode;
    if (fixingNode != NIL) {
        fixingNode->parent = rightSon;
    }
}

//Переименовать x и y
template <class T, class V>
void RedBlackTree<T, V>::turnRight(Node<T, V> *turningNode) {
    Node<T, V> *leftSon = turningNode->left;
    turningNode->left = leftSon->right;
    if (leftSon->right != NIL) {
        leftSon->right->parent = turningNode;
    }
    if (leftSon != NIL) {
        leftSon->parent = turningNode->parent;
    }
    if (turningNode->parent != NIL) {
        if (turningNode == turningNode->parent->right) {
            turningNode->parent->right = leftSon;
        }
        else {
            turningNode->parent->left = leftSon;
        }
    }
    else {
        root = leftSon;
    }
    leftSon->right = turningNode;
    if (turningNode != NIL) {
        turningNode->parent = leftSon;
    }
}


template <class T, class V>
void RedBlackTree<T, V>::insert(T key, V value) {
    Node<T, V> *current, *parent, *newNode;
    current = root;
    if (key <= 0) { //Исправить ситуацию с отрицательным значениями (Тест с отрицательными ключами)
        throw invalid_argument("Can not insert this type of key");
    }
    else {
        try {
            newNode = find(key);
            throw invalid_argument("This key already exist");
        }
        catch (out_of_range error) {
            while (current->key != 0) {
                parent = current;
                if (key < current->key) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }
            newNode = new Node<T, V>(key, value, parent);
            
            if (parent != NIL) {
                if (key < parent->key) {
                    parent->left = newNode;
                }
                else {
                    parent->right = newNode;
                }
            }
            else {
                root = newNode;
            }
            insertFix(newNode);
        }
    }
}

template <class T, class V>
void RedBlackTree<T, V>::insertFix(Node<T, V> *fixNode) {
    Node<T, V> *uncle = NIL;
    while ((fixNode != root) && (fixNode->parent->color == true)) {
        if (fixNode->parent == fixNode->parent->parent->left) {
            if (fixNode->parent->parent->right) {
                uncle = fixNode->parent->parent->right;
            }
            else {
                uncle = new Node<T, V>();
            }
            if (uncle->color == true) {
                fixNode->parent->color = false;
                uncle->color = false;
                fixNode->parent->parent->color = true;
                fixNode = fixNode->parent->parent;
            }
            else {
                if (fixNode == fixNode->parent->right) {
                    fixNode = fixNode->parent;
                    turnLeft(fixNode);
                }
                fixNode->parent->color = false;
                fixNode->parent->parent->color = true;
                turnRight(fixNode->parent->parent);
            }
        }
        else {
            if (fixNode->parent->parent->left) {
                uncle = fixNode->parent->parent->left;
                
            }
            else {
                uncle = new Node<T, V>();
            }
            if (uncle->color == true) {
                fixNode->parent->color = false;
                uncle->color = false;
                fixNode->parent->parent->color = true;
                fixNode = fixNode->parent->parent;
            }
            else {
                if (fixNode == fixNode->parent->left) {
                    fixNode = fixNode->parent;
                    turnRight(fixNode);
                }
                fixNode->parent->color = false;
                fixNode->parent->parent->color = true;
                turnLeft(fixNode->parent->parent);
            }
        }
    }
    root->color = false;
}

template <class T, class V>
Node<T, V> *RedBlackTree<T, V>::find(T key) {
    Node<T, V> *findNode;
    findNode = root;
    while (findNode != nullptr && findNode->key != key) {
        if (key < findNode->key) {
            findNode = findNode->left;
        }
        else {
            findNode = findNode->right;
        }
    }
    if (findNode == nullptr) {
        throw out_of_range("There is no elements with this key");
    }
    return findNode;
}


template <class T, class V>
void RedBlackTree<T, V>::remove(T key){
    Node<T, V> *deleteNode, *x, *y;
    deleteNode = find(key);
    if (deleteNode->left->key == 0 || deleteNode->right->key == 0) {
        y = deleteNode;
    }
    else {
        y = deleteNode->right;
        while (y->left->key != 0) {
            y = y->left;
        }
    }
    if (y->left->key != 0) {
        x = y->left;
    }
    else {
        x = y->right;
    }
    if (y->parent->key != 0) {
        if (x->key != 0) {
            x->parent = y->parent;
        }
        if (y == y->parent->left) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }
    }
    else {
        x = root;
    }
    if (y != deleteNode) {
        deleteNode->key = y->key;
    }
    if (y->color == false) {
        fixRemove(x);
    }
    if (y != root) {
        delete y;
    }
    else {
        clear();
    }
}

template <class T, class V>
void RedBlackTree<T, V>::fixRemove(Node<T, V> *fixNode) {
    Node<T, V> *brother;
    while (fixNode != root && fixNode->color == false) {
        if (fixNode == fixNode->parent->left) {
            if (fixNode->parent->right->key != 0) {
                brother  = fixNode->parent->right;
            }
            else {
                brother  = new Node<T, V>();
            }
            if (brother->color == true) {
                brother->color = false;
                fixNode->parent->color = true;
                turnLeft(fixNode->parent);
                brother  = fixNode->parent->right;
            }
            if ( (brother->left == nullptr || brother->left->color == false) && (brother->right == nullptr || brother->right->color == false)) {
                brother->color = true;
                fixNode = fixNode->parent;
            }
            else {
                if (brother->right->color == false) {
                    brother->left->color = false;
                    brother->color = true;
                    turnRight(brother);
                    brother = fixNode->parent->right;
                }
                brother->color = fixNode->parent->color;
                fixNode->parent->color = false;
                fixNode->right->color = false;
                turnLeft(fixNode->parent);
                fixNode = root;
            }
        }
        else {
            if (fixNode->parent->left != NIL) {
                brother = fixNode->parent->left;
            }
            else {
                brother = new Node<T, V>();
            }
            if (brother->color == true) {
                brother->color = false;
                fixNode->parent->color = true;
                turnRight(fixNode->parent);
                brother = fixNode->parent->left;
            }
            if (brother->right->color == false && brother->left->color == false) {
                brother->color = true;
                fixNode = fixNode->parent;
            }
            else {
                if (brother->left == NIL || brother->left->color == false ) {
                    if (brother->right != NIL) {
                        brother->right->color = false;
                    }
                    brother->color = true;
                    turnLeft(brother);
                    brother = fixNode->parent->left;
                }
                brother->color = fixNode->parent->color;
                fixNode->parent->color = false;
                brother->left->color = false;
                turnRight(fixNode->parent);
                fixNode = root;
            }
        }
    }
}

template <class T, class V>
void RedBlackTree<T, V>::clear() {
    root->clearNode();
    delete NIL;
    NIL = nullptr;
    root = nullptr;
}

template <class T, class V>
MyList<T> RedBlackTree<T, V>::get_keys() {
    MyList<T> keyList;
    keyList = root->get_keys_Node(keyList);
    return keyList;
}

template <class T, class V>
MyList<V> RedBlackTree<T, V>::get_values() {
    MyList<T> valueList;
    valueList = root->get_values_Node(valueList);
    return valueList;
}

#endif /* RedBlackTreeClass_h */
