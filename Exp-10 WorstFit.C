// C++ implementation of worst - Fit algorithm
#include<stdio.h>
int blockSize[10], m, processSize[10], n, i, j, allocation[10], bno, pno, x, y, wstIdx;
// Function to allocate memory to blocks as per worst fit
// algorithm
void worstFit()
{
	// Initially no block is assigned to any process
	for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (i=0; i<n; i++)
	{
		// Find the best fit block for current process
		wstIdx = -1;
		for (j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (wstIdx == -1)
					wstIdx = j;
				else if (blockSize[wstIdx] < blockSize[j])
					wstIdx = j;
			}
		}

		// If we could find a block for current process
		if (wstIdx != -1)
		{
			// allocate block j to p[i] process
			allocation[i] = wstIdx;

			// Reduce available memory in this block.
			blockSize[wstIdx] -= processSize[i];
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (i = 0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
        printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

// Driver code
int main()
{
    printf("Enter no. of blocks: ");
    scanf("%d", &bno);
    printf("\nEnter size of each block: ");
    for(x = 0; x < bno; x++)
	scanf("%d", &blockSize[x]);
		
    printf("\nEnter no. of processes: ");
    scanf("%d", &pno);
    printf("\nEnter size of each process: ");
    for(y = 0; y < pno; y++)
	scanf("%d", &processSize[y]);
	
    m = bno;
    n = pno;
    
    worstFit();
 
    return 0 ;
}
