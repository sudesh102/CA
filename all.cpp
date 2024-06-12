//BINARY SEARCH SOLUTION  ( )
#include<iostream>
using namespace std;
int Binarysearch(int arr[],int size,int search,int *count)
{   int mid;
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==search)
        {
            (*count)++;
            return mid;
        }
        else if(arr[mid]<search)
        {
            low=mid+1;
            (*count)++;
        }
        else
        {
            high=mid-1;
            (*count)++;
        }
    }
    return 0;
}
int main()
{    int size;
    cout<<"Enter the size of an array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elemnts of an array : ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int search;
    cout<<"Enter the data that you wnat to search in array : ";
    cin>>search;
    int count=0;
    int ans= Binarysearch( arr,size,search,&count);
    if(ans==-1)
    {
        cout<<"Error : Data is not found.";
    }
    else
    {
        cout<<"The data is foud at "<<ans+1<<" index"<<endl;
    }
    cout<<"The total Itiration done for the operation are : "<<count<<endl;
}

//MIN-MAX SOLUTION
#include<iostream>
using namespace std;

void minMax(int arr[], int i, int j, int &Max, int &Min) {
    int Min1, Max1;
    if (i == j) {
        Min = Max = arr[i];
    } else if (i == j - 1) {
        if (arr[i] < arr[j]) {
            Min = arr[i];
            Max = arr[j];
        } else {
            Min = arr[j];
            Max = arr[i];
        }
    } else {
        int mid = (i + j) / 2;
        minMax(arr, i, mid, Max, Min);
        minMax(arr, mid + 1, j, Max1, Min1); 

        if (Min > Min1) { 
            Min = Min1;
        }

        if (Max < Max1) { 
            Max = Max1;
        }
    }
}

int main() {
    	int a[5]={10,50,20,90,30};
	int i;	int a[5]={10,50,20,90,30};
	int i;
    int arr[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int Min, Max;
    minMax(arr, 0, n - 1, Max, Min);
    cout << "Minimum element: " << Min << endl;
    cout << "Maximum element: " << Max << endl;
    return 0;
}

//MERGE SORT SOLUTION
#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high,int brr[])
{
    int i=low,j=mid+1,k=low;

    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            brr[k++]=arr[i++];  
        }
        else
        {
            brr[k++]=arr[j++];    
        }
    }
    while(i<=mid)
    {   brr[k]=arr[i];
            i++;
            k++;
     }
    while(j<=high)
    {
        brr[k]=arr[j];
            j++;
            k++;
     }

    for(int a=low;a<=high;a++)
    {
        arr[a]=brr[a];
    }
        
}

void mergesort(int arr[],int low,int high,int brr[])
{
    if(low<high)
    {
    int mid=(low+high)/2;
    mergesort(arr,low,mid,brr);
    mergesort(arr,mid+1,high,brr);
    merge(arr,low,mid,high,brr);
    }  
}
int main()
{
    int size,i,k;
    int low=0;
    int high;
    int mid;

    cout<<"Enter the size of an array : ";
    cin>>size;

    int arr[size];
    int brr[size];

    cout<<"Enter the elements of an array : ";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    high=size-1;
    mergesort(arr,low,high,brr);

    cout<<"The Sorted Array : ";
    for(i=0;i<size;i++)
    {
        cout<<" "<<arr[i];
    }

    return 0;
}

//quick sort problem
#include<stdio.h>
int partition(int a[],int lb,int ub);
int swap(int a[],int i,int j);
int quicksort(int arr[],int lb,int ub);

int partition(int a[5],int lb,int ub)
{
	int pivot=a[lb];
	int i=lb,j=ub,temp;
	while(i<j)
	{
		while(a[i]<=pivot)
		{	i++;
		}
		while(a[j]>pivot)
		{	j--;
		}
		if(i<j)
		{	swap(a,i,j);
		}
	}
	swap(a,lb,j);
	return j;
}
int swap(int a[],int i,int j)
{
	int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
}
int quicksort(int arr[5],int lb,int ub)
{
	if(lb<ub)
	{
		int location=partition(arr,lb,ub);
		quicksort(arr,lb,location-1);
		quicksort(arr,location+1,ub);
	}	
}
int main()
{
	int a[5]={10,50,20,90,30};
	int i;
	int lb=0,ub=4;
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("quick sort array ");
	quicksort(a,lb,ub);
		for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
}

//knapsack Problem 

#include<stdio.h>
int main()
{
	int cap=20;
	float profit=0;
	float wt[4]={10,5,4,3};
	float pr[4]={14,15,16,3};
	float ratio[4];
	int n=4;
	int i,j,temp;
	
	for( i=0;i<4;i++)
	{
		ratio[i]=(pr[i])/(wt[i]);
	}
	for( i=0;i<n-1;i++)
	{
		for( j=i+1;j<n;j++)
		{
			if(ratio[i]<=ratio[j])
			{
			 temp=ratio[i];
			ratio[i]=ratio[j];
			ratio[j]=temp;
			
			temp=wt[i];
			wt[i]=wt[j];
			wt[j]=temp;
			temp=pr[i];
			pr[i]=pr[j];
			pr[j]=temp;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		if(cap>0 &&wt[i]<=cap)
		{
			cap=cap-wt[i];
			profit=profit+pr[i];
		}
		else
		{
			profit=profit+((pr[i])*(cap/(wt[i])));
		}
	}
	printf("maximum Profit is:%2f Rs\n",profit);
}

//jobsequence problem

#include<stdio.h>
int main()
{
	int profit=0;
	int count=0;
	int dmax=0;
	int slot[5];
	int jobNo[5];
	int job[5]={1,2,3,4,5};
	int p[5],d[5];
	int i,j,r,temp=0;
	
	printf("enter the profit and deadline of each job\n");
	for(i=0;i<5;i++)
	{
		printf("profit:");
		scanf("%d",&p[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("deadline:");
		scanf("%d",&d[i]);
	}
	for( i=0;i<5;i++)
	{
		for( j=i+1;j<5;j++)
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
			
			temp=d[i];
			d[i]=d[j];
			d[j]=temp;
			
			temp=job[i];
			job[i]=job[j];
			job[j]=temp;
		}
		for(i=0;i<5;i++)
		{
			if(d[i]>dmax)
			{
				dmax=d[i];
			}
		}
		for(i=0;i<=dmax;i++)
		{
			slot[i]=-1;
		}
		for(i=0;i<5;i++)
		{
			for(r=d[i];i>=0;i--)
			{
				if(slot[r]==-1)
				{
					profit+=p[i];
					jobNo[i]=job[i];
					count++;
					break;
				}
			}
			if(count==dmax)
			{
				break;
			}
		}
	}
	printf("Profit=%d",profit);
	for(i=0;i<dmax;i++)
	{
		printf("\nJob no is %d",jobNo[i]);
	}
}

//SINGLE SOURCE SHORTEST PATH SOLUTION
#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INFINITY 9999
void dijkstra(int cost[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX], count, minDistance, nextNode, i, j;
    // Initialization
    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1) {
        minDistance = INFINITY;
        // Choose the next node
        for (i = 0; i < n; i++) {
            if (dist[i] < minDistance && !visited[i]) {
                minDistance = dist[i];
                nextNode = i;
            }
        }   
        visited[nextNode] = 1;
        
        // Update distances
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (minDistance + cost[nextNode][i] < dist[i]) {
                    dist[i] = minDistance + cost[nextNode][i];
                }
            }
        }
        count++;
    }   
    // Print the distance to each node
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    int cost[MAX][MAX], n, i, j, start;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INFINITY;
            }
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);
    dijkstra(cost, n, start);   
    return 0;
}

//0/1 KNAPSACK PROBLEM
#include <stdio.h>
// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build the table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    // Return the maximum value that can be put in the knapsack of capacity W
    return K[n][W];
}
int main() {
    int i,n, W;
    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    // Input values and weights of items
    printf("Enter values of items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    
    printf("Enter weights of items:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    // Input capacity of knapsack
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);
    // Call knapSack function and print the result
    printf("Maximum value in knapsack = %d\n", knapSack(W, wt, val, n));   
    return 0;
}

//SUM OF SUBSET
#include <stdio.h>
#define MAX 100
// Function to print the subset
void printSubset(int subset[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
// Backtracking function to find the subsets
void subsetSum(int arr[], int subset[], int n, int subSize, int total, int nodeCount, int sum) {
    if (total == sum) {
        printSubset(subset, subSize);
        return;
    }
    
    if (nodeCount == n || total > sum) {
        return;
    }   
    // Include the current element in the subset
    subset[subSize] = arr[nodeCount];
    subsetSum(arr, subset, n, subSize + 1, total + arr[nodeCount], nodeCount + 1, sum);
    // Exclude the current element from the subset and move to the next element
    subsetSum(arr, subset, n, subSize, total, nodeCount + 1, sum);
}
int main() {
    int i,n, sum;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[MAX];
    int subset[MAX];
    
    printf("Enter the elements:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the sum to be found: ");
    scanf("%d", &sum);
    
    printf("Subsets with the given sum are:\n");
    subsetSum(arr, subset, n, 0, 0, 0, sum);
    
    return 0;
}

//N QUEEN PROBLEM
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int board[MAX];
int count = 0;
void printSolution(int n) {
    count++;
    int i,j;
    printf("Solution %d:\n", count);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int row, int col) {
	int i;
    for (i = 1; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}
void solveNQueen(int row, int n) {
	int col;
    for ( col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (row == n)
                printSolution(n);
            else
                solveNQueen(row + 1, n);
        }
    }
}
int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid input. Number of queens should be between 1 and %d.\n", MAX);
        return 1;
    }

    solveNQueen(1, n);
    printf("Total solutions: %d\n", count);

    return 0;
}