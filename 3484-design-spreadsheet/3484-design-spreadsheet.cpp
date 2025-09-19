#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid; // rows x 26 columns

    // Helper: convert cell string like "A1" -> (row, col)
    pair<int,int> parseCell(const string& cell) {
        char colChar = cell[0];                 // 'A' to 'Z'
        int col = colChar - 'A';                // 0-indexed
        int row = stoi(cell.substr(1)) - 1;     // 1-indexed -> 0-indexed
        return {row, col};
    }

    // Helper: get cell value (0 if unset/out of bounds)
    int getCellValue(const string& token) {
        if (isdigit(token[0])) {
            // It's a number
            return stoi(token);
        } else {
            // It's a cell reference
            auto [r, c] = parseCell(token);
            if (r < 0 || r >= rows || c < 0 || c >= 26) return 0;
            return grid[r][c];
        }
    }

public:
    Spreadsheet(int rows) : rows(rows) {
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        if (r >= 0 && r < rows && c >= 0 && c < 26) {
            grid[r][c] = value;
        }
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        if (r >= 0 && r < rows && c >= 0 && c < 26) {
            grid[r][c] = 0;
        }
    }

    int getValue(string formula) {
        // formula format: "=X+Y"
        if (formula[0] != '=') return 0;

        string expr = formula.substr(1); // remove '='
        size_t plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        int val1 = getCellValue(left);
        int val2 = getCellValue(right);
        return val1 + val2;
    }
};

/**
 * Example usage:
 * Spreadsheet* spreadsheet = new Spreadsheet(3);
 * cout << spreadsheet->getValue("=5+7") << endl;  // 12
 * spreadsheet->setCell("A1", 10);
 * cout << spreadsheet->getValue("=A1+6") << endl; // 16
 * spreadsheet->setCell("B2", 15);
 * cout << spreadsheet->getValue("=A1+B2") << endl; // 25
 * spreadsheet->resetCell("A1");
 * cout << spreadsheet->getValue("=A1+B2") << endl; // 15
 */
