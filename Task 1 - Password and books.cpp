#include<iostream>
#include<string>
using namespace std;

// Useful for short tests
void expect(const char* expected_output) {
    cout << "\nExpected:\n" << expected_output << "\n\n";
}

bool is_sorted(string* row, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (row[i] > row[i + 1]) {
            return false;
        }
    }
    return true;
}

void reveal_password(string a[100][100], int m, int n) {
    
    for (int i = 0; i < m; i++) {
        if (is_sorted(a[i], n)) {
            string middle_book = a[i][(n - 1) / 2];

            int count = 0;

            for (int k = 0; k < middle_book.length(); k++) {
                if (middle_book[k] == ' ') {
                    cout << count << ' ';
                    count = 0;
                }
                else {
                    count++;
                }
            }
            cout << count << ' ';
        }
    }
}

int main() {
    string a[100][100] = {
        { "Algebra", "Analit geom", "Mat" },
        { "UP", "OOP", "SDP" },
        { "abc", "def", "xyz" }
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << '\n';
        }
    }

    reveal_password(a, 3, 3);
    expect("6 4 3");
}