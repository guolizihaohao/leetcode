// https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int n1 = (int) num1.size(), n2 = (int) num2.size();
        int k = n1 + n2 - 2;
        vector<int> v(n1 + n2, 0);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                v[k - i - j] += (num1[i] -'0') * (num2[j] - '0');
            }
        }
        int carry_bit = 0; 
        for (int i = 0; i < n1 + n2; ++i) {
            v[i] += carry_bit;
            carry_bit = v[i] / 10;
            v[i] %= 10;
        }
        int i = n1 + n2 - 1;
        while (v[i] == 0) --i;
        if (i < 0) return "0";
        while (i >= 0) res.push_back(v[i--] + '0');
        return res;
    }
};
