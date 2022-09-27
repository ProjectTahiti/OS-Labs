// C implementation of First - Fit algorithm
#include<stdio.h>
int blockSize[10], m, processSize[10], n, i, j, allocation[10], bno, pno, x, y;
// Function to allocate memory to
// blocks as per First fit algorithm
void firstFit()
{
    // Initially no block is assigned to any process
    for(i = 0; i < n; i++)
    {
	allocation[i] = -1;
    }

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (i = 0; i < n; i++)        //here, n -> number of processes
    {
	for (j = 0; j < m; j++)        //here, m -> number of blocks
	{
	    if (blockSize[j] >= processSize[i])
	    {
		// allocating block j to the ith process
		allocation[i] = j;

		// Reduce available memory in this block.
		blockSize[j] -= processSize[i];

		break;    //go to the next process in the queue
	    }
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

    firstFit();

    return 0 ;
}
