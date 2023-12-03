#include <iostream>
#include <algorithm>

using namespace std;

const int rows = 15;
const int cols = 2;

void findMinSumRows(int arr[rows][cols], int &minSumRow1, int &minSumRow2) {
    int minSum = INT_MAX;

    for (int i = 0; i < rows - 1; ++i) {
        int currentSum = arr[i][0] + arr[i][1] + arr[i + 1][0] + arr[i + 1][1];
        if (currentSum < minSum) {
            minSum = currentSum;
            minSumRow1 = i;
            minSumRow2 = i + 1;
        }
    }
}

void sortRow(int row[cols]) {
    sort(row, row + cols);
}

int main() {
    int arr[rows][cols];

    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }

    int minSumRow1, minSumRow2;
    findMinSumRows(arr, minSumRow1, minSumRow2);

    cout << "Номера рядків з мінімальною сумою: " << minSumRow1 + 1 << " та " << minSumRow2 + 1 << std::endl;

    for (int i = 0; i < rows; ++i) {
        sortRow(arr[i]);
    }

    cout << "Відсортований масив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}