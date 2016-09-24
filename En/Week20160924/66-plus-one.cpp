/*
https://leetcode.com/problems/plus-one/

66. Plus One 

Total Accepted: 124781 Total Submissions: 348791 Difficulty: Easy

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int offset = 1;
        for (int i = size-1; i >= 0; --i) {
            if (offset == 1) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                    offset = 1;
                } else {
                    digits[i]++;
                    offset = 0;
                }
            }
        }
        
        if (offset == 1) {
            vector<int>::iterator it = digits.begin();
            digits.insert(it, 1);
        }
        
        return digits;
    }
};