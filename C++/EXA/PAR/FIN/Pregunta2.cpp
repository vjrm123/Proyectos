#include <iostream>
#include <string>

template<class T>
class Stack {
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            
           T value = Pop();
            std::cout << "eliminando " << value;
        }
    }

    void Push(const T& object);
    T Pop();
    bool isEmpty();
    void Print();

private:
    struct StackNode {
        T Data;
        StackNode* Next;

        StackNode(const T& newData, StackNode* nextNode)
            : Data(newData), Next(nextNode) {}
    };
    StackNode* top;
};

template<class T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

template<class T>
void Stack<T>::Push(const T& obj) {
    StackNode* newNode = new StackNode(obj, top);
    top = newNode;
}

template<class T>
T Stack<T>::Pop() {
    if (isEmpty()) {
        std::cout << "la lista esta vacia";
    }
    StackNode* nodeToDelete = top;
    T data = nodeToDelete->Data;
    top = top->Next;
    delete nodeToDelete;

    return data;
}

template<class T>
void Stack<T>::Print() {
    std::cout << "HEAD-> ";
    for (StackNode* P = top; P; P = P->Next) {
        std::cout << P->Data << "-> ";
    }
    std::cout << "NULL\n";
}

int main() {
    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    stack.Print();

    return 0;
}