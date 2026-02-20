class Solution {
public:
    int thirdMax(vector<int>& nums) {
     long long first = LLONG_MIN;
     long long sec = LLONG_MIN;
     long long third = LLONG_MIN;

     for(int num : nums){
        if(num == first || num == sec || num == third){
            continue;
        }

        if(num > first){
            third = sec;
            sec = first;
            first = num;
        }else if(num > sec){
            third = sec;
            sec = num;
        }else if(num > third){
            third = num;
        }
     }
     if(third == LLONG_MIN){
        return first;
     }else{
        return third;
     }
    }
};