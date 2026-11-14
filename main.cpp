#include <iostream>
#include <vector>
#include <cassert>
#include "header/SegmentTree.h"

using namespace std;

int main() {// Initial array: [1, 3, 5, 7, 9, 11]
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree st(nums);

    cout << "Running SegmentTree Test Cases...\n" << endl;

    // Test 1: Full range query sum(0, 5) -> 1+3+5+7+9+11 = 36
    assert(st.query(0, 5) == 36);
    cout << " [PASS] query(0, 5) == 36" << endl;

    // Test 2: Sub-range query sum(1, 3) -> 3+5+7 = 15
    assert(st.query(1, 3) == 15);
    cout << " [PASS] query(1, 3) == 15" << endl;

    // Test 3: Single element query sum(2, 2) -> 5
    assert(st.query(2, 2) == 5);
    cout << " [PASS] query(2, 2) == 5" << endl;

    // Test 4: Update index 2 from 5 to 10
    // Array becomes: [1, 3, 10, 7, 9, 11]
    st.update(2, 10);
    cout << " [INFO] Updated index 2 to value 10" << endl;

    // Test 5: Query range sum(1, 3) after update -> 3+10+7 = 20
    assert(st.query(1, 3) == 20);
    cout << " [PASS] query(1, 3) after update == 20" << endl;

    // Test 6: Full range query sum(0, 5) after update -> 36 - 5 + 10 = 41
    assert(st.query(0, 5) == 41);
    cout << " [PASS] query(0, 5) after update == 41" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}