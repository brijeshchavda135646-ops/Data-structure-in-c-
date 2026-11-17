// BFS traversal of a graph using adjacency matrix
#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10][10],visited[10]={0};
    int queue[10],front=0,rear=0;
    int n,i,j,start;

    printf("Enter number of vertices:");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d):",n-1);
    scanf("%d",&start);

    queue[rear]=start;
    rear++;
    visited[start]=1;

    printf("BFS traversal: ");

    while(front<rear)
    {
        int v=queue[front];
        front++;
        printf("%d ",v);

        for(i=0;i<n;i++)
        {
            if(a[v][i]==1 && visited[i]==0)
            {
                queue[rear]=i;
                rear++;
                visited[i]=1;
            }
        }
    }

    getch();
}