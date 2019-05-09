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

bool is_sorted(Node<int>* _list) {
    if (_list == nullptr) {
        return true;
    }
    if (_list->next == nullptr) {
        return true;
    }
    return _list->data <= _list->next->data
        && is_sorted(_list->next);
}

void append_sorted(Node<int>*& destination, Node<int>* source) {
    if (source == nullptr) {
        return;
    }
    
    Node<int>* merge = nullptr;
    Node<int>* last_in_merge = nullptr;
    Node<int>* crr_in_dest = destination;
    Node<int>* crr_in_src = source;

    while (crr_in_dest != nullptr && crr_in_src != nullptr) {
        if (crr_in_dest->data < crr_in_src->data) {
            if (merge == nullptr) {
                merge = new Node<int>(crr_in_dest->data);
                last_in_merge = merge;
            }
            else {
                last_in_merge->next = new Node<int>(crr_in_dest->data);
                last_in_merge = last_in_merge->next;
            }
            crr_in_dest = crr_in_dest->next;
        }
        else {
            if (merge == nullptr) {
                merge = new Node<int>(crr_in_dest->data);
                last_in_merge = merge;
            }
            else {
                last_in_merge->next = new Node<int>(crr_in_src->data);
                last_in_merge = last_in_merge->next;
            }
            crr_in_src = crr_in_src->next;
        }
    }
    while (crr_in_dest != nullptr) {
        if (merge == nullptr) {
            merge = new Node<int>(crr_in_dest->data);
            last_in_merge = merge;
        }
        else {
            last_in_merge->next = new Node<int>(crr_in_dest->data);
            last_in_merge = last_in_merge->next;
        }
        crr_in_dest = crr_in_dest->next;
    }
    while (crr_in_src != nullptr) {
        if (merge == nullptr) {
            merge = new Node<int>(crr_in_src->data);
            last_in_merge = merge;
        }
        else {
            last_in_merge->next = new Node<int>(crr_in_src->data);
            last_in_merge = last_in_merge->next;
        }
        crr_in_src = crr_in_src->next;
    }
    
    // Delete from old destination
    destination = merge;
}

Node<int>* union_of_sorted(Node<Node<int>*>* lists) {

    Node<int>* result = nullptr;

    Node<Node<int>*>* current_list = lists;

    while (current_list != nullptr) {
        if (is_sorted(current_list->data)) {
            append_sorted(result, current_list->data);
        }
        current_list = current_list->next;
    }

    return result;
}

void add_5(double& x) {
    x += 5;
}

void move(double*& x) {
    x = nullptr;
}

int main() {
    Node<int>* a1 = new Node<int>(11);
    a1->next = new Node<int>(12);
    a1->next->next = new Node<int>(13);

    Node<int>* a2 = new Node<int>(4);
    a2->next = new Node<int>(2);

    Node<int>* a3 = new Node<int>(11);
    a3->next = new Node<int>(12);

    Node<Node<int>*>* lists = new Node<Node<int>*>(a1);
    lists->next = new Node<Node<int>*>(a2);
    lists->next->next = new Node<Node<int>*>(a3);

    Node<int>* _union = union_of_sorted(lists);

    for (Node<int>* crr = _union; crr != nullptr; crr = crr->next) {
        cout << crr->data << ' ';
    }

    cout << '\n';
}
