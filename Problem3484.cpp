#include <vector>
#include <string>
using std::string;

class Spreadsheet {
public:
    std::vector<std::vector<int>>grid;
    Spreadsheet(int rows) {
        grid = std::vector<std::vector<int>>(rows, std::vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1))-1;
        grid[r][c] = value;
        
    }
    
    void resetCell(string cell) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1))-1;

        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        int ans = 0;
        int i = 1;
        while(formula[i] != '+'){
            i++;
        }
        string s = formula.substr(1, i-1);
        string s2 = formula.substr(i+1);
        if(isdigit(s[0])){
            ans += stoi(s);
        }
        else{
            int c = s[0] - 'A';
            int r = stoi(s.substr(1)) - 1;
            ans += grid[r][c];
        }
        if(isdigit(s2[0])){
            ans += stoi(s2);
        }
        else{
            int c = s2[0] - 'A';
            int r = stoi(s2.substr(1))-1;
    
            ans += grid[r][c];
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */