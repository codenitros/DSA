//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //  add given words to a set
        set<string> mSet;
        
        bool isEndPresent=false;
        for(int i=0;i<wordList.size();i++){
            mSet.insert(wordList[i]);
            if(endWord.compare(wordList[i])==0)isEndPresent=true;
        }
        
        // if endword itself is not present in given word list we can straight away return
        if(!isEndPresent)return 0;
        
        
        // BFS
        queue<string> mQ;
        mQ.push(beginWord);
        int count=0;
        while(!mQ.empty()){
            // only place we increment the count
            count+=1;
            int qSize = mQ.size();
            while(qSize--){
                string cur = mQ.front();
                mQ.pop();

                // for each letter in cur word
                for(int i=0;i<cur.length();i++){
                    string temp = cur;
                    // replace one letter to form new word
                    for(char c='a'; c<='z'; c++){
                        temp[i]=c;
                        
                        // if same word is formed continue
                        if(cur.compare(temp)==0){
                            continue;
                        }
                        
                        // if endword is formed we are done
                        if(temp.compare(endWord)==0){
                            return count+1;
                        }
                        
                        // if the formed word is present in wordlist set then this should be considered
                        if(mSet.find(temp)!=mSet.end()){
                            mQ.push(temp);
                            
                            // remove the word since we have consumed and pushed to our queue
                            mSet.erase(temp);
                        }
                    }
                }
            }

        }
        
        return 0;
    }
};