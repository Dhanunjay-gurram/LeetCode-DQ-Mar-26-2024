class Solution {
public:
    /*Intuition:
     
     We just place the number(num) in the index num-1 so that while checking if we have -ve number or zero in any index then that +ve number is missing
     Then we return the first missing +ve number
     Lets say if all numbers are present and are +ve then we return nums.size()+1
     Time Complexity: O(n)
     Space Complexity: O(n)
     
     */
    //Swapping approach
    int firstMissingPositive(vector<int>& nums) {
        int n= size(nums);
       
        for(int i=0;i<n;i++){
            int x=nums[i]; // x = current element
            
            //Loop to place correctly the swapped element
            while(x>=1 && x<=n && x!=i+1 && nums[x-1]!=x){
                swap(nums[x-1],nums[i]);
                x=nums[i];
            }
        }


        for(int i=0;i<n;i++){
            if(nums[i] == i+1)continue;
                return i+1;
            
        }
        
        return n+1;
    }
};

/*
 2. Sorting approach
 class Solution {
 public:
     int firstMissingPositive(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int j = 1;
         for(int i=0;i<nums.size();i++){
             if(nums[i]<=0){
                 continue;
             }
             else{
                 if(j == nums[i]){
                     while(i<nums.size()-1 && j==nums[i+1]){
                         i++;
                     }
                     j++;
                     continue;
                 }
                 return j;
             }
         }
         return j;
     }
 };
 
 
 //Time Complexity: O(nlogn)
   Space Complexity: O(n)
 */

/*
 3. Hashing
 class Solution {
 public:
     int firstMissingPositive(vector<int>& nums) {
         unordered_map<int,bool> up;
         for(auto x: nums){
             if(x>0){
                 up[x] = 1;
             }
         }
         for(int i=1;i<=nums.size()+1;i++){
             if(up.find(i)==up.end()){
                 return i;
             }
         }
         return -1;
     }
 };
 
 //Time Complexity: O(n)
 //Space Complexity: O(n)
 */

