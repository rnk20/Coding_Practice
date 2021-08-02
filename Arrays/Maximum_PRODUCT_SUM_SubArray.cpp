
/******************************************************

Maximum sum subarray 
We will have one variable "current_sum" to store the current sum.
Here whenever current_sum becomes negative we will put it to zero to calculate new sum.


*******************************************************/

int maxSubarraySum(int arr[], int n){
        
        int max_sum = INT_MIN;
        int current_sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            current_sum = current_sum + arr[i];
            
            max_sum = max(max_sum, current_sum);

            if(current_sum < 0)
                current_sum = 0;
        }
        
        return max_sum;
    }


/***************************************************************

Maximum Product Subarray

Here we can get maximum product from negative product also.

We will have two variables to store current maximum and current minimum:
1) max_current_sum = 1  : This will contain positive element or 1 only
2) min_current_sum = 1  : This will contain negative element or 1 only


****************************************************************/

long long maxProduct(int *arr, int n) {
	    
	if(n == 1)
	     return 1LL*arr[0];
	     
	long long current_max = 1;
	long long current_min = 1; 
	long long max_product = 0;
	int flag = 0;
	
	for(int i = 0; i < n; i++)
	{
	    if(arr[i] > 0)
	    {
	        current_max = current_max * arr[i];
	        
	        // Only if negative not "1"
	        if(current_min < 0)
	            current_min = current_min * arr[i];
	    }
	    else if(arr[i] == 0)
	    {
	        current_max = 1;
	        current_min = 1;
	    }
	    // current_max*arr[i] will become current_min
	    // current_min*arr[i] will become current_max only if current_min is negative else it is set to 1 only.
	    else if(arr[i] < 0)
	    {
	        long long temp = current_max;
	        
	        if(current_min < 0)
	           current_max = current_min * arr[i];
	        else
	           current_max = 1;
	        
	        current_min = temp * arr[i];
	    }
	    
	    max_product = max(max_product, current_max);
	}
	
	return max_product;

}
