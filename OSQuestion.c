#include <stdio.h> 
int main() 
{ 
    // P0, P1, P2, P3, P4 are the Process names here 
  
    int n, m, i, j, k; 
    n = 5; // Number of processes 
    m = 3; // Number of resources 
    int allocation[5][3] = { { 0, 1, 0 },{ 2, 0, 0 },{ 3, 0, 2 },{ 2, 1, 1 },{ 0, 0, 2 } };  // Allocation Matrix
                               //  P0       //P1        //P2       //P3         //P4
  
  
    int max[5][3] = { { 7, 5, 3 },{ 3, 2, 2 },{ 9, 0, 2 },{ 2, 2, 2 },{ 4, 3, 3 } };// MAX Matrix
                          //P0       //P1        //P2       //P3         //P4
  
   
    int available[3] = { 3, 3, 2 }; // Available Resources 
  
    int fin[n],answer[n],in=0; 
    for (k=0;k<n;k++) 
	{ 
        fin[k] = 0;//finish=false 
    } 
    int need[n][m];//need matrix 
    for (i=0;i<n;i++) 
	{ 
        for (j= 0;j<m;j++) 
            need[i][j] = max[i][j] - allocation[i][j];//creating need matrix 
    } 
    int y = 0; 
    //applying safety algorithm
    for (k=0;k<5;k++) 
	{ 
        for (i=0;i<n;i++) 
		{ 
            if (fin[i]==0) 
			{ 
                int count = 0; 
                for (j=0;j<m;j++) 
				{ 
                    if (need[i][j]>available[j]) 
                        {
						count=1;	
						} 
                    break; 
                } 
  
                if(count==0) 
				{ 
                    answer[in++]=i; 
                    for(y=0;y<m;y++)
					{
						available[y]+=allocation[i][y];
		            }
                    fin[i]=1;//finish=true
                } 
            } 
        } 
    } 
  
    printf("********************THE SAFE SEQUENCE IS*************************\n"); 
    for (i = 0; i < n - 1; i++) 
        printf(" P%d ->", answer[i]); 
    printf(" P%d", answer[n - 1]); 
  
    return (0); 
   
} 
