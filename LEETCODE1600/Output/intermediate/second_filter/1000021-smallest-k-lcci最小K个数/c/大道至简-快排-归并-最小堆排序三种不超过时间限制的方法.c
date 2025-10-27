class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(arr.empty()) return {};
        vector<int> v;

        int len=arr.size();
        HeapSort(arr,v,k,len);
        return v;        
    }

    void HeapSort(vector<int>& arr,vector<int>& v,int k,int len)
    {
        for(int i=(len-1)/2;i>=0;i--)
        {
            HeapAdjust(arr,i,len);
        }
        for(int j=len-1;j>=len-k;j--)
        {
            v.push_back(arr[0]);
            swap(arr[0],arr[j]);
            HeapAdjust(arr,0,j);
        }
    }
    void HeapAdjust(vector<int>& arr,int idx,int len)
    {
        int i=idx,j=2*i+1;
        int tmp=arr[i];
        while(j<len)
        {
            if(j+1<len&&arr[j+1]<arr[j])
                j++;
            if(arr[j]<tmp)
            {
                arr[i]=arr[j];
            }
            else
                break;
            i=j;
            j=2*i+1;
            
        }
        arr[i]=tmp;    
    }
};