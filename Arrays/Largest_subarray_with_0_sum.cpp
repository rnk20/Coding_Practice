int maxLen(int A[], int n)
{
    unordered_map<int, int>hash_map;
    
    int sum = 0, max_len = 0;
    
    for(int i = 0; i < n; i++)
    {
        sum += A[i];
        
        if(sum == 0)
        {
            max_len = max(max_len, (i + 1));
        }
        else if(hash_map.find(sum) != hash_map.end())
        {
            max_len = max(max_len, (i - hash_map[sum]));
        }
        else
        {
            hash_map[sum] = i;
        }
    }
    
    return max_len;
}
