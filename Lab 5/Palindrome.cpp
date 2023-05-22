#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minInsertionsForPalindrome(const string& s, int left, int right, vector<vector<int>>& dp) {
    if (left >= right) {
        return 0;  
    }
    
    if (dp[left][right] != -1) {
        return dp[left][right];  
    }

    if (s[left] == s[right]) {
        dp[left][right] = minInsertionsForPalindrome(s, left + 1, right - 1, dp);
    } else {
        dp[left][right] = min(minInsertionsForPalindrome(s, left + 1, right, dp),
                               minInsertionsForPalindrome(s, left, right - 1, dp)) + 1;
    }
    
    return dp[left][right];
}

int main() {
    int N;
    cin >> N;
    
    string s;
    cin >> s;
    
    vector<vector<int>> dp(N, vector<int>(N, -1));  
    
    int minInsertions = minInsertionsForPalindrome(s, 0, N - 1, dp);
    
    cout << minInsertions << endl;
    
    return 0;
}
