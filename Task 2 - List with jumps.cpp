#include<iostream>
#include<fstream>
using namespace std;

// Useful for short tests
void expect(const char* expected_output) {
    cout << "\nExpected:\n" << expected_output << "\n\n";
}

struct Node {
    int data;
    Node* next;
    Node* jump;

    Node(int _data) {
        data = _data;
        next = nullptr;
        jump = nullptr;
    }
};

int sqrt_upper_bound(int n) {
    int i = 1;
    
    while (i * i < n) {
        i++;
    }

    return i;
}

Node* read_list(ifstream& in) {
    
    Node* _list = nullptr;  // pointer to first element
    Node* current = _list;  // pointer to last element

    int number;
    int count = 0;

    while (!in.eof()) {
        in >> number;
        count++;

        if (_list == nullptr) {
            _list = new Node(number);
            current = _list;
        }
        else {
            current->next = new Node(number);
            current = current->next;
        }
    }

    int jump_interval = sqrt_upper_bound(count);

    current = _list;

    while (current != nullptr) {

        Node* next_jump = current;

        for (int i = 0; i < jump_interval; i++) {
            if (next_jump == nullptr) {
                break;
            }
            else {
                next_jump = next_jump->next;
            }
        }

        current->jump = next_jump;

        current = current->jump;
    }

    return _list;
}

bool member(int x, Node* _list) {

    Node* current = _list;
    Node* previous = nullptr;

    while(current != nullptr) {
        if (current->data == x) {
            return true;
        }
        else if (current->data > x) {
            if (previous == nullptr) {
                return false;
            }
            Node* node = previous;
 
            while (node != current) {
                if (node->data == x) {
                    return true;
                }
                node = node->next;
            }
            return false;
        }
        else {
            previous = current;
            current = current->jump;
        }
    }

    return false;
}

int main() {
    ifstream in("numbers.txt");
    
    Node* the_list = read_list(in);

    for (Node* crr = the_list; crr != nullptr; crr = crr->next) {
        cout << crr->data << ' ';
    }
    expect("1 2 3 4 6 7 8 9");

    for (Node* crr = the_list; crr != nullptr; crr = crr->jump) {
        cout << crr->data << ' ';
    }
    expect("1 4 8");

    cout << member(5, the_list);
    cout << member(6, the_list);
    cout << member(8, the_list);

    cout << member(-2, the_list);
    cout << member(12, the_list);

    expect("01100");
}