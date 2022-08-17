class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[26] ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> s;
        for(string w:words)
        {
            string t = "";
            for(int i=0;i<w.size();i++)
            {
                t += code[w[i]-97];
            }
            s.insert(t);
        }
        return s.size();
    }
};