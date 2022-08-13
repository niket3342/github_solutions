class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /* BRUTE FORCE APPROACH BY GENERTING ALL PERMUTATIONS*/
//         if(words.size() == 0 || (s.size() < words.size() * words[0].size()))
//             return {};
        
//         sort(words.begin(), words.end());
//         vector<string> searchstr;
//         vector<int> result;
        
//         do {
//             string temp;
//             for(string str : words)
//                 temp += str;
            
//             searchstr.push_back(temp);
//         }while(next_permutation(words.begin(), words.end()));
        
//         int len = searchstr[0].size();
        
//         for(int i = 0; i <= s.size() - len; i++){
//             string cur = s.substr(i, len);
            
//             for(string ss : searchstr)
//                 if(ss == cur)
//                     result.push_back(i);
//         }
        
//         return result;
        
        
        
        int len = words[0].length(), noOfWords = words.size();//all words are of same length
        vector<int> result;
        map<string, int> wordMap;
        
        if (len * noOfWords > s.length())
            return result;
        
        for (string word : words)
            wordMap[word]++;
            
        for (int idx = 0; idx <= s.length() - (noOfWords * len); idx++) {
            map<string, int> wordsUsedMap;
            
            for (int chunkIdx = idx; chunkIdx < idx + (noOfWords * len); chunkIdx += len) {
                string cur = s.substr(chunkIdx, len);
                if(wordMap.find(cur) == wordMap.end())
                    break;

                wordsUsedMap[cur]++;
                
                if(wordsUsedMap[cur] > wordMap[cur])
                    break;
            }
            
            if (wordsUsedMap == wordMap)
                result.push_back(idx);
        }
        
        return result;
        
    }
};