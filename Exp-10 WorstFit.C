// C++ implementation of worst - Fit algorithm
#include<stdio.h>

// Function to allocate memory to blocks as per worst fit
// algorithm
void worstFit(int blockSize[], int m, int processSize, int n)
{
	// Stores block id of the block allocated to a
	// process
	int allocation[n];

	// Initially no block is assigned to any process
	for(int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (int i=0; i<n; i++)
	{
		// Find the best fit block for current process
		int wstIdx = -1;
		for (int j=0; j<m; j++)
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
	for (int i = 0; i < n; i++)
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
	int pno; //number of blocks in the memory
    int bno; //number of processes in the input queue
    int x;
    int y;
    
    int blockSize[100]; //blocks
    int processSize[100];//processes
    
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
	
    int m = bno;
    int n = pno;
    
    worstFit(blockSize, m, processSize, n);
 
    return 0 ;
}
