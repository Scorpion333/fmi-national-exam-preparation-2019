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

struct Cell {
    char data;
    int row;
    int col;

    Cell(char _data, int _row, int _col) {
        data = _data;
        row = _row;
        col = _col;
    }
};

int largest_area(char forest[100][100], int m, int n) {
    bool visited[100][100] = { true };

    int max = 0;

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (!visited[row][col] && forest[row][col] == '4') {
                
                char wanted = forest[row][col];

                queue<Cell> q;
                q.push(Cell(forest[row][col], row, col));
                visited[row][col] = true;

                int current_area = 1;

                while (!q.empty()) {
                    Cell current = q.front();
                    q.pop();

                    if (current.row > 0 && visited[row - 1][col] == false
                     && forest[current.row - 1][current.col] == wanted) {

                        q.push(Cell(
                            forest[current.row - 1][current.col],
                            current.row - 1,
                            current.col
                        ));
                        visited[row-1][col] = true;
                        current_area++;
                    }
                    if (current.col > 0 && visited[row][col - 1] == false
                     && forest[current.row][current.col - 1] == wanted) {

                        q.push(Cell(
                            forest[current.row][current.col - 1],
                            current.row,
                            current.col - 1
                        ));
                        visited[row][col-1] = true;
                        current_area++;
                    }
                
                    if (current.row < m-1 && visited[row + 1][col] == false
                     && forest[current.row + 1][current.col] == wanted) {

                        q.push(Cell(
                            forest[current.row + 1][current.col],
                            current.row + 1,
                            current.col
                        ));
                        visited[row+1][col] = true;
                        current_area++;
                    }
                    if (current.col < n-1 && visited[row][col + 1] == false
                     && forest[current.row][current.col + 1] == wanted) {

                        q.push(Cell(
                            forest[current.row][current.col + 1],
                            current.row,
                            current.col + 1
                        ));
                        visited[row][col+1] = true;
                        current_area++;
                    }
                }

                if (current_area > max) {
                    max = current_area;
                }
            }
        }
    }

    return max;
}

int main() {
    char forest[100][100] = {
        "RR1144",
        "4RRR14",
        "S1R423",
        "4444SR"
    };
    //for (int i = 0; i < 4; i++) {
    //    for (int k = 0; k < 6; k++) {
    //        cout << forest[i][k] << ' ';
    //    }
    //    cout << '\n';
    //}

    cout << largest_area(forest, 4, 6);

    cout << '\n';
}
