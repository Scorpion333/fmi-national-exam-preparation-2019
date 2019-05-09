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

struct Node {
    char data;
    Node* left;
    Node* mid;
    Node* right;

    Node(char data,
         Node* left,
         Node* mid,
         Node* right) {
        this->data = data;
        this->left = left;
        this->mid = mid;
        this->right = right;
    }
};

string read_last(Node* tree) {
    if (tree == nullptr) {
        return "";
    }

    vector<Node*> current_level;
    current_level.push_back(tree);

    while (!current_level.empty()) {
        vector<Node*> next_level;
        for (int i = 0; i < current_level.size(); i++) {
            if (current_level[i]->left != nullptr) {
                next_level.push_back(current_level[i]->left);
            }
            if (current_level[i]->mid != nullptr) {
                next_level.push_back(current_level[i]->mid);
            }
            if (current_level[i]->right != nullptr) {
                next_level.push_back(current_level[i]->right);
            }
        }
        if (next_level.empty()) {
            string result;
            for (int i = 0; i < current_level.size(); i++) {
                result += current_level[i]->data;
            }
            return result;
        }
        else {
            current_level = next_level;
        }
    }
}

void serialize(Node* tree, ofstream& out) {
    if (tree == nullptr) {
        out << '*';
        return;
    }

    out << '(' << tree->data << ' ';
    serialize(tree->left, out);
    out << ' ';
    serialize(tree->mid, out);
    out << ' ';
    serialize(tree->right, out);
    out << ')';
}

void serialize(Node* tree, string file_path) {
    ofstream out(file_path);

    serialize(tree, out);
}

int main() {
    Node* tree = new Node(
        'b',
        new Node(
            'x',
            new Node('p', nullptr, nullptr, nullptr),
            new Node('q', nullptr, nullptr, nullptr),
            new Node('r', nullptr, nullptr, nullptr)
        ),
        new Node(
            'y',
            new Node('s', nullptr, nullptr, nullptr),
            nullptr,
            nullptr
        ),
        nullptr
    );
    serialize(tree, "new_file.txt");
}
