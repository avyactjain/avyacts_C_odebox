 #include<stdio.h>
 #include<iostream>
 #include<stdlib.h>

 int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}

 
 int main()
 {
     int arr[50];
     for(int i = 0; i < 50 ; i ++)
     {
         arr[i] = rand();
     }
     for ( int t = 0; t<50; t++)
     {
         for(int j = 0; j < 49 ; j++)
         {
             if(arr[t]<arr[j])
             {
                 int temp = arr[j];
                 arr[j] = arr[t];
                 arr[t] = temp;
             }
         }
     }

     for(int i = 0; i < 50 ; i ++)
     {
         printf("%d \n", arr[i]);
     }

     
     int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 1356425228;
    int result = binarySearch(arr, 0, n-1, x);
    (result == -1)? printf("Element is not present"
                                       " in array")
               : printf("Element is present at "
                                "index %d", result);

    printf("%i \n", arr[27]);
    return 0;
}

     
 
