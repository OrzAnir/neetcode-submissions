class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(string s: wordList) st.insert(s);
        queue<pair<int, string>> q;
        q.push({0, beginWord});
        if (st.find(beginWord) != st.end()) st.erase(beginWord);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto p = q.front(); q.pop();
                int distance = p.first; string s = p.second;
                if (s == endWord) return distance + 1;
                for(int i = 0; i < s.size(); i++) {
                    string str = s;
                    for(int j = 0; j < 26; j++) {
                        str[i] = 'a' + j;
                        if (st.find(str) != st.end()) {
                            st.erase(str);
                            q.push({distance + 1, str});
                        }
                    }
                }
            }
        }
        return 0;
    }
};
