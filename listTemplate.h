//
//  listTemplate.h
//  GoogleTestExample
//
//  Created by Ирина Литвинова on 16/04/2019.
//  Copyright © 2019 Alloysoft. All rights reserved.
//

#ifndef listTemplate_h
#define listTemplate_h

using  namespace std;

template <class T> class MyList;

template <class T>
class Element {
public:
    T data;
    Element *next;
    
    Element<T>(){};
    Element<T>(T number) {
        this->data = number;
        this->next = nullptr;
    }
    ~Element() {
        data = 0;
    }//TODO Fix Destructor
    friend class MyList<T>;
};

// Объявление класса списка
template <class T>
class MyList {
public:
    Element<T> *head;
    Element<T> *tail;
    int size; // на size_t
    
    MyList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    /*MyList(initializer_list<T> t_list) {
        this->size = 0;
        for (auto elem : t_list) {
            push_back(elem);
        }
    };*/
   /* ~MyList() { //TODO addiction for fixing destructor
        Element<T> *p1 = head, *p2 = head;
        if (size != 0) {
            while (p2 != nullptr) {
                p2 = p1->next;
                delete p1;
                p1 = p2;
                size--;
            }
            head = nullptr;
            tail = nullptr;
        }
    }*/
    void push_front(T add);
    void push_back(T add);
    int get_size() const;
    void pop_front();
    void pop_back();
    Element<T> &at(int position);
    bool isEmpty() const;
    void insert(T add, int position);
    void remove(int position);
    void clear();
    void set(T add, int position);
};

template <class T>
ostream &operator<<(ostream &os, const MyList<T> &lst) {
    Element<T> *element = lst.head;
    while (element != nullptr) {
        os << element->data << " ";
        
        element = element->next;
    }
    return os;
}

//Adding new element "add" to the end of the list
template <class T>
void MyList<T>::push_back(T add) {
    Element<T> *newElement;
    newElement = new Element<T>(add);
    if (size == 0) {
        this->head = newElement;
        this->tail = newElement;
    }
    else {
        tail->next = newElement;
        this->tail = newElement;
    }
    size++;
}

//Adding new element "add" to the front of the list
template <class T>
void MyList<T>::push_front(T add) {
    Element<T> *newElement;
    newElement = new Element<T>(add);
    if (size == 0) {
        head = newElement;
        tail = newElement;
    }
    else {
        newElement->next = head;
        head = newElement;
    }
    size++;
}

//Returning the size of list
template <class T>
int MyList<T>::get_size() const {
    return size;
}

//Deleting the first element of list
template <class T>
void MyList<T>::pop_back() {
    Element<T> *p1;
    if (size > 1) {
        p1 = head;
        while (p1->next != tail) {
            p1 = p1->next;
        }
        delete tail;
        size--;
        p1->next = nullptr;
        tail = p1;
    } else{
        if (size == 1) {
            delete head;
            size--;
        } else {
            throw out_of_range("There is no element to delete");
        }
    }
}

//Deleting the last element of list
template <class T>
void MyList<T>::pop_front() {
    Element<T> *begining = head;
    if (size != 0) {
        head = head->next;
        delete begining;
        size--;
    }
    else {
        throw out_of_range("There is no element to delete");
    }
}

//Searching for the element at "position" position (Numerations starts with 1)
template <class T>
Element<T> &MyList<T>::at(int position) {
    Element<T> *p1;
    if ((size >= position) && (position > 0)) {
        p1 = head;
        for (size_t i = 0; i < position; i++) {
            p1 = p1->next;
        }
        return *p1;
    } else {
        throw out_of_range("Index is greater than list size");
    }
}

//Checking if the list empty
template <class T>
bool MyList<T>::isEmpty() const {
    return size == 0;
}

//Inserts new element "add" before "position" position
template <class T>
void MyList<T>::insert(T add, int position) {
    Element<T> *p1, *newElement;
    p1 = head;
    newElement = new Element<T>(add);
    if ((position < size) && (position >= 0)) {
        if (position == 0) {
            push_front(add);
        } else {
            if (position == size + 1) {
                push_back(add);
            } else {
                for (size_t i = 0; i < position - 1; i++) {
                    p1 = p1->next;
                }
                newElement->next = p1->next;
                p1->next = newElement;
            }
        }
    } else{
        throw out_of_range("Index is greater than list size");
    }
}

//Removes the element at "position" position
template <class T>
void MyList<T>::remove(int position) {
    Element<T> *p1, *p2;
    if (position == 0) {
        p1 = head;
        head = p1->next;
        delete p1;
    } else {
        if ((position < size) && (position > 0)) {
            p1 = head;
            for (size_t i = 0; i < position - 1; i++) {
                p1 = p1->next;
            }
            p2 = p1->next;
            p1->next = p2->next;
            size--;
            delete p2;
        } else {
            throw out_of_range("Index is greater than list size");
        }
    }
}

//Deleting all elements of list
template <class T>
void MyList<T>::clear() {
    Element<T> *p1, *p2 = head;
    p1 = head;
    while (p2 != nullptr) {
        p2 = p1->next;
        delete p1;
        p1 = p2;
        size--;
    }
    head = nullptr;
    tail = nullptr;
}

//Changing the data of element at "position" position to "add"
template <class T>
void MyList<T>::set(T add, int position) {
    Element<T> *p1;
    
    if ((position < size) && (position >= 0)) {
        p1 = head;
        for (size_t i = 0; i < position; i++) {
            p1 = p1->next;
        }
        p1->data = add;
    } else{
        throw out_of_range("Index is greater than list size");
    }
}


#endif /* listTemplate_h */
