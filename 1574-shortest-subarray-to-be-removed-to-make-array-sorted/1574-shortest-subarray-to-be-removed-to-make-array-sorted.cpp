
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int n =(int) arr.size();
        int h = n-1 , l=0 ;
        
        
        
        for(int i=h;i>=1;i--)  
        {
            if(arr[i]>=arr[i-1] && h>0)
            {
                h--;
            }
            else break;
        }

        int res=h;

       for( l=0 ; l<h && (l==0 || arr[l-1]<=arr[l])  ;l++)
       {
             
             while(h<n && arr[l]>arr[h])
              {
                 h++;
              }


           res = min(res,h-l-1);

        
           
       }
      return res;

        
        
    }
};