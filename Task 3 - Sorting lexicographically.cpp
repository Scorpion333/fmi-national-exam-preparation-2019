#include<iostream>
#include<fstream>
using namespace std;

// Useful for short tests
void expect(const char* expected_output) {
    cout << "\nExpected:\n" << expected_output << "\n\n";
}

void save_in_char_array(char* char_array, int x) {
    if (x == 0) {
        char_array[0] = '0';
        char_array[1] = '\0';
        return;
    }

    int i = 0;

    while (x > 0) {
        char_array[i] = '0' + x % 10;
        i++;
        x = x / 10;
    }
    char_array[i] = '\0';

    //cout << char_array << '\n';
}

bool less_than_lex(int a, int b) {
    char a_as_str[20];
    char b_as_str[20];

    save_in_char_array(a_as_str, a);
    save_in_char_array(b_as_str, b);

    int i_a = strlen(a_as_str) - 1;
    int i_b = strlen(b_as_str) - 1;

    while (i_a >= 0 && i_b >= 0) {
        if (a_as_str[i_a] < b_as_str[i_b]) {
            return true;
        }
        else if (a_as_str[i_a] > b_as_str[i_b]) {
            return false;
        }
        i_a--;
        i_b--;
    }

    if (i_a == -1 && i_b == -1) {
        return false;
    }
    if (i_a == -1) {
        return true;
    }
    // Now i_b == -1
    return false;
}

void sort_lex(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int k = i+1; k < n; k++) {
            if (less_than_lex(arr[k], arr[i])) {
                int swap = arr[i];
                arr[i] = arr[k];
                arr[k] = swap;
            }
        }
    }
}

int main() {


    //cout << less_than_lex(2019, 204) << "---" << '\n';
    //cout << less_than_lex(201, 2019) << "---" << '\n';
    //cout << less_than_lex(201, 201) << "---" << '\n';
    //cout << less_than_lex(0, 9) << "---" << '\n';

    int arr[6] = { 13,14,7,2018,9,0 };
    // { 13, 201, 204, 2018, 201, 12 };

    sort_lex(arr, 6);

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << ' ';
    }
}