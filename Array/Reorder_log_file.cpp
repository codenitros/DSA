// https://leetcode.com/problems/reorder-data-in-log-files/

bool customsort(pair<string, string> s1, pair<string, string> s2){
    return s1.second==s2.second?s1.first<s2.first:s1.second<s2.second;
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digLogs;
        vector<pair<string, string>> letlog;
        
        for(int i=0;i<logs.size();i++){
            int k=0;
            while(k<logs[i].size() && logs[i][k]!=' '){
                k++;
            }
            if(!isalpha(logs[i][k+1])){
                digLogs.push_back(logs[i]);
            }else{
                letlog.push_back(make_pair(logs[i].substr(0, k), logs[i].substr(k+1)));
            }
        }

        sort(letlog.begin(), letlog.end(), customsort);
        
        
        
        vector<string> ans;
        for(int i=0;i<letlog.size();i++){
            ans.push_back(letlog[i].first + ' ' + letlog[i].second);
        }
        
        for(int i=0;i<digLogs.size();i++){
            ans.push_back(digLogs[i]);
        }
        return ans;
    }
};