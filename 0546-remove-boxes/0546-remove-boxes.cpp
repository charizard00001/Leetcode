class Solution {
    int dp[100][100][100];
    int n;
public:
    int f(int l, int r, int k, vector<int> &boxes){
        if(l > r) return 0;
        if(dp[l][r][k] != -1) return dp[l][r][k];
        int ans = (k + 1) * ( k + 1) + f(l + 1, r, 0, boxes);
        for(int i = l + 1 ; i <= r ; ++i){
            if(boxes[l] == boxes[i]){
                ans = max(ans, f(l + 1, i - 1, 0, boxes) + f(i, r, k + 1, boxes));
            }
        }
        return dp[l][r][k] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        n = boxes.size();
        memset(dp, -1, sizeof(dp));
        return f(0, n - 1, 0, boxes);
    }
};

// brute force recurssion

// class Solution {
// public:
//     int removeBoxes(vector<int>& boxes) {
//         int n = boxes.size();
//         if(n == 0) return 0;
//         int i = 0;
//         int ans = 0;
//         while(i < n){
//             int j = i;
//             while(j < n && boxes[j] == boxes[i]){
//                 j++;
//             }
//             int count = j - i;
//             vector<int> rem;
//             for(int k = 0 ; k < i ; ++k){
//                 rem.push_back(boxes[k]);
//             }
//             for(int k = j ; k < n ; ++k){
//                 rem.push_back(boxes[k]);
//             }
//             int points = count * count + removeBoxes(rem);
//             ans = max(ans, points);
//             i = j;
//         }
//         return ans;
//     }
// };