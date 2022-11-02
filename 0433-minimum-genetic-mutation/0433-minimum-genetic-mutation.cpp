	#define ll long long
class Solution {
public:
    unordered_set<string>st;
    unordered_set<string>visited;
    char arr[4]={'A','C','G','T'};
    ll solve(int index,string &curr,string &target){
        if(visited.find(curr)!=visited.end()){
            return INT_MAX;
        }
        if(st.find(curr)==st.end()){
            return INT_MAX;
        }
        if(curr==target){
            return 0;
        }
        visited.insert(curr);
        ll ans=INT_MAX;
        for(int i=0;i<curr.size();++i){
            char ch=curr[i];
            for(int j=0;j<4;++j){
                if(arr[j]==ch){
                    continue;
                }
                curr[i]=arr[j];
                ans=min(ans,1+solve(i+1,curr,target));
                curr[i]=ch;
            }
        }
        return ans;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        for(string str:bank){
            st.insert(str);
        }
        st.insert(start);
        ll ans=solve(0,end,start);
        if(ans>=INT_MAX){
            return -1;
        }
        return ans;
    }
};