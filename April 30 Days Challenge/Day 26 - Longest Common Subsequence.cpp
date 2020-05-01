class Solution {
    string text1;
    string text2;
    vector<vector<int>> vec;
public:
    int longestCommonSubsequence(string text1, string text2) {
        vec = vector<vector<int>>(text1.length(), vector<int>(text2.length(), -1));
        this->text1 = text1;
        this->text2 = text2;
        return longestCommonSubsequence2(0, 0);
    }
    
    int longestCommonSubsequence2(int s1, int s2) {
        if(s1 == text1.length() || s2 == text2.length()){
            return 0;
        }
        if(vec[s1][s2] != -1){
            return vec[s1][s2];
        }
        int l1 = longestCommonSubsequence2(s1, s2 + 1);
        int l2 = longestCommonSubsequence2(s1 + 1, s2);
        int lcs = max(l1, l2);
        if(text1[s1] == text2[s2]){
            int l3 = longestCommonSubsequence2(s1 + 1, s2 + 1) + 1;
            lcs = max(l1, l3);
        }
        vec[s1][s2] = lcs;
        return lcs;
    }
};