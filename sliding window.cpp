//Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.length();
        unordered_map<int,int> mp;
        int mx=0;
        while(j<n){
            mp[s[j]]++;
             if(mp.size()==(j-i+1)){
                 mx=max(mx,(j-i+1));
                 //j++;
             }else if(mp.size()<(j-i+1)){
                 while(mp.size()<(j-i+1)){
                     mp[s[i]]--;
                     if(mp[s[i]]==0){
                         mp.erase(s[i]);
                     }
                     i++;
                 }
             }
            j++;
        }
        return mx;
    }
};

//Subarrays with K Different Integers


//Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        int idx=n;
        if(m>n)
        return "";
        unordered_map<char,int> mp;
        for(int i=0;i<m;i++){
               mp[t[i]]++;
        }
        int cnt=mp.size(),ans=INT_MAX;
        int i=0,j=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                   mp[s[j]]--;
                   if(mp[s[j]]==0){
                        cnt--;
                   }
            }
            if(cnt>0)
            j++;

            else if(cnt==0){
                if((j-i+1)<ans){
                    ans=j-i+1;
                    idx=i;
                }

                //now try to minimize the answer
                while(cnt==0){
                if(mp.find(s[i])==mp.end()){
                    i++;
                  if((j-i+1)<ans){
                    ans=j-i+1;
                    idx=i;
                  }
                }
                else{
                        mp[s[i]]++;
                        if(mp[s[i]]>0)
                            cnt++;
                            i++;
                    if(cnt==0 && (j-i+1)<ans){
                    ans=j-i+1;
                    idx=i;
                  }    
                }
                }
            j++;
            }
           }
        return s.substr(idx,ans);
    }
};