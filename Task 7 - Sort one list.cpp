#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

// Useful for short tests
void expect(const char* expected_output) {
    cout << "\nExpected:\n" << expected_output << "\n\n";
}

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T _data) {
        data = _data;
        next = nullptr;
    }
};

void sort(Node<int>*& _list) {
    if (_list == nullptr || _list->next == nullptr) {
        return;
    }

    sort(_list->next);

    Node<int>* old_second_element = _list->next;

    if (_list->data <= old_second_element->data) {
        return;
    }

    Node<int>* crr_in_next = _list->next;

    int inserted = _list->data;

    while (crr_in_next->next != nullptr
        && crr_in_next->next->data < inserted) {
        crr_in_next = crr_in_next->next;
    }
    
    _list->next = crr_in_next->next;
 
    crr_in_next->next = _list;
 
    _list = old_second_element;
}

int main() {
    Node<int>* a1 = new Node<int>(10);
    a1->next = new Node<int>(8);
    a1->next->next = new Node<int>(11);
    a1->next->next->next = new Node<int>(7);
    a1->next->next->next->next = new Node<int>(9);

    sort(a1);

    for (Node<int>* crr = a1; crr != nullptr; crr = crr->next) {
        cout << crr->data << ' ';
    }

    cout << '\n';
}
