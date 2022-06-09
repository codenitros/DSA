// https://leetcode.com/problems/partition-labels/

// a b a b c b a c a f e g h i j h k l i j

class solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurence(26, -1);
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            lastOccurence[s[i]-'a']=i;
        }

        int i=0, j=0;
        int start=i;

        while(){
            if(j >= lastOccurence[s[i]-'a']){
                if(i==j){
                    ans.push_back(i-start);
                    i++;
                    start=i;
                    j=i;
                }else{
                    i++;
                }
            }else{
                j = lastOccurence[s[i]-'a'];
            }
        }
        return ans;
    }
}