long long maxProduct(int *arr, int n) {
	    if(n == 1)
            return arr[0];
        long long sum = 0;
        
        long long max_val = arr[0];
        long long min_val = arr[0];
        
        sum = arr[0];
        
        for(int i = 1; i < n; i++)
        {
            if(arr[i] < 0)
                swap(max_val, min_val);
            
            max_val = max(arr[i]*1LL, arr[i]*max_val);
            min_val = min(arr[i]*1LL, arr[i]*min_val);
            
            sum = max(sum, max_val);
        }
        
        return sum;
	}
