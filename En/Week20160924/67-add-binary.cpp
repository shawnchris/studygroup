/**
67. Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int idx_a = a.size() - 1;
        int idx_b = b.size() - 1;
        int tmp = 0;
        while (idx_a >= 0 || idx_b >= 0 || tmp == 1) {
            if (idx_a >= 0) {
                tmp += a[idx_a--] - '0';
            }
            if (idx_b >= 0) {
                tmp += b[idx_b--] - '0';
            }
            result = char('0' + tmp % 2) + result;
            tmp /= 2;
        }
        return result;
    }
};