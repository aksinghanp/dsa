//mex
class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};

//Integer to Roman
class Solution {
public String intToRoman(int num) {
int[] intCode= {1000,900,500,400,100,90,50,40,10,9,5,4,1};
String[] code = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    StringBuilder sb = new StringBuilder(); 
    for(int i = 0; i < intCode.length; i++){
        while(num >= intCode[i]){
            sb.append(code[i]);
            num -= intCode[i];
        }
    }   
    return sb.toString();   
}
};

//Next Permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=n;
        for(int i=n-1;i>0;i--){
           if(nums[i]>nums[i-1]){
               idx=i;
               break;
           } 
        }
        if(idx==n)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        int prev=idx-1;
        for(int i=idx+1;i<n;i++){
            if(nums[prev]<nums[i] && nums[i]<=nums[idx]){
                idx=i;
            }
        }
        swap(nums[prev],nums[idx]);
        sort(nums.begin()+prev+1,nums.end());
       // return nums;  
    }
};




