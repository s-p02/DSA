/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    pair<int,int> getmiddile(MountainArray &mountainArr, int n){
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid= (low+high)/2;
            int left=mid;
            int right=mid;
            if(mid+1<n) right=mountainArr.get(mid+1);
            if(mid-1>0) left=mountainArr.get(mid-1);
            int mmid= mountainArr.get(mid);
            if(mmid>left && mmid>right){
                return {mid,mmid};
            }
            else if(right>mmid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }
    int getleft(int target, MountainArray &mountainArr, int index,int n){
        int low=0;
        int high= index-1;
        while(low<=high){
            int mid= (low+high)/2;
            int mmid= mountainArr.get(mid);
            if(mmid==target){
                return mid;
            }
            if(mmid>target){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return -1;
    }
    
    int getright(int target, MountainArray &mountainArr, int index,int n){
        int low=index+1;
        int high= n-1;
        while(low<=high){
            int mid= (low+high)/2;
            int mmid= mountainArr.get(mid);
            if(mmid==target){
                return mid;
            }
            if(mmid<target){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n= mountainArr.length();
        auto ans= getmiddile(mountainArr,n);
        int index= ans.first;
        int val=ans.second;
        cout<<val<<endl;
        if(val==target){
            return index;
        }
        int l= getleft(target,mountainArr,index,n);
        int r= getright(target,mountainArr,index,n);
        
        if(l==-1 && r==-1){
            return -1;
        }
        if(l!=-1){
            return l;
        }
        else{
            return r;
        }
        return 0;

    }
};