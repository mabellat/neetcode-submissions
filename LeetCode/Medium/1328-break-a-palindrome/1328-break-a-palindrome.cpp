class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if (n == 1) return "";

        // Check only the first half (automatically skips the middle char if n is odd)
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }

        // If all characters in the first half are 'a', change the last char to 'b'
        s[n - 1] = 'b';
        return s;
    }
};