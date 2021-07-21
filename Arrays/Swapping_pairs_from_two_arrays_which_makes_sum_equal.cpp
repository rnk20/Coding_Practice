/*

Let there be two arrays:
A = a1, a2, ... an
B = b1, b2,     bn

Let's say pair will be (a, b) from array A and B respectively.

then:
sumA + b - a = sumB + a - b

b - a = (sumB - sumA)/2;

Now just need to check if there exists two elements having difference ((sumB - sumA)/2).

*/

int findSwapValues(int A[], int n, int B[], int m)
{
	    unordered_map<int, int>hash_map;
	    
	    int sumA = 0, sumB = 0;
	    
	    for(int i = 0; i < n; i++)
	        sumA += A[i];
	       
	    for(int i = 0; i < m; i++)
	        sumB += B[i];
	    
	    if(sumA == sumB)
	    {
	         for(int i = 0; i < n ;i++)
	            hash_map[A[i]] = 1;
	         
	         for(int i = 0; i < m; i++)
	         {
	             if(hash_map[B[i]] == 1)
	                return 1;
	         }
	         
	         return -1;
	    }
	        
	    int arr_max = (sumA > sumB)?1:2;
	    int check_val = 0;
	    
	    if(arr_max == 1)
	    {
	        for(int i = 0; i < n ;i++)
	            hash_map[A[i]] = 1;
	        if((sumA - sumB)%2 == 1)
	            return -1;
	        check_val = (sumA - sumB)/2;
	    }
	    else if(arr_max == 2)
	    {
	        for(int i = 0; i < m; i++)
	             hash_map[B[i]] = 1;
	        if((sumB - sumA)%2 == 1)
	            return -1;
	       check_val = (sumB - sumA)/2;
	    }
	    
	    if(arr_max == 1)
	    {
	        for(int i = 0; i < m; i++)
	        {
	            if(hash_map[check_val + B[i]])
	                return 1;
	        }
	    }
	    else if(arr_max == 2)
	    {
	        for(int i = 0; i < n; i++)
	        {
	            if(hash_map[check_val + A[i]])
	                return 1;
	        }
	    }
	    
	    return -1;
	}
