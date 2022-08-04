string ans =" ";
if(strs.size()==0) return " ";
if(strs.size()==1) return strs[0];
for(int i=0;i<strs.size()-1;i++)
{
string x= strs[i], y=strs[i+1];
for(int j=0;j<min(x.length(),y.length());j++)
{
if(x[j] == y[j]) ans+=x[j];
else break;
}
}
return ans;
int n = str.size();
if(n==0) return "";
string ans  = "";
sort(begin(str), end(str));
string a = str[0];
string b = str[n-1];
for(int i=0; i<a.size(); i++){
if(a[i]==b[i]){
ans = ans + a[i];
}
else{
break;
}
}
return ans;