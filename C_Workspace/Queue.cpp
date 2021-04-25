#include <iostream>

template<class T> 
class Node {
public:
    T val;
    Node* next;
    Node* prev;

    Node(T data) : val(data), next(NULL), prev(NULL) 
    {}
};

template<class T>
class Queue {
private:
    Node<T>*  head;
    Node<T>* tail;
    int size;


public:
    Queue() : head(NULL), tail(NULL), size(0)
    {}
    
    void push(T data);
    T peek();
    T poll();

    void print();
    int length() { return size; }
};


template<class T>
void Queue<T>::push(T data) {
    Node<T>* temp = new Node<T>(data);

    if(head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->prev = head;
        head->next = temp;
        head = head->next;
    }

    size++;
}


template<class T>
T Queue<T>::peek() {
    return head->val;
}

template<class T>
T Queue<T>::poll() {

    T output = tail->val;

    tail = tail->next;
    delete tail->prev;
    tail->prev = NULL;

    size--;
    return output;
}


template<class T>
void Queue<T>::print() {
    Node<T> * temp = tail;
    while(temp != NULL) {
        std::cout << temp->val << std::endl;
        temp = temp->next;
    }
}


int main(int argc, char const *argv[])
{
    Queue<int> obj = Queue<int>();
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(5);

    obj.poll();
    obj.print();
    return 0;
}