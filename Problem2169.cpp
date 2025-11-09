class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 > num2) return countOperations(num2, num1);
        if (num1 == 0) return 0;
        return (num2 / num1) + countOperations((num2 % num1), num1);
    }
};