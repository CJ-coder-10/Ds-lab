#include <stdio.h>

int main() 
{
	int n,i,j;
	printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 ) {
        printf("Invalid number of vertices!\n");
        return 0;
    }
    int graph[n][n];
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		graph[i][j]=0;
		}
	}
    int visited[n];
    for(i=0;i<n;i++)
    {
    	visited[i]=0;
	}
    int parent[n];
    for (i = 0; i < n; i++)
        parent[i] = -1;
    int queue[n];

    int e, u, v, start, goal;
    int front = 0, rear = 0;
    int node, path[n], len = 0;

    

    printf("Enter number of edges: ");
    scanf("%d", &e);

    if (e < 0 || e > n * (n - 1) / 2) {
        printf("Invalid number of edges!\n");
        return 0;
    }

    printf("Enter edges (u v) of the graph.ie,vertices from 0 to %d:\n", n - 1);

    for (i = 0; i < e; ) {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Warning: Invalid vertex! Enter vertices from 0 to %d.\n", n - 1);
            continue;
        }
         if (u == v || graph[u][v] == 1) {
            printf("Warning: Self-loops and duplicate edges are not allowed.\n");
            continue;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
        i++;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("Enter destination vertex: ");
    scanf("%d", &goal);

    if (start < 0 || start >= n || goal < 0 || goal >= n) {
        printf("Warning: Invalid start or destination vertex!\n");
        return 0;
    }

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        node = queue[front++];
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                parent[i] = node;
                queue[rear++] = i;
            }
        }
    }

    if (!visited[goal]) {
        printf("\nNo path exists\n");
    } else {
        node = goal;

        while (node != -1) {
            path[len++] = node;
            node = parent[node];
        }

        printf("\nShortest Path: ");

        for (i = len - 1; i >= 0; i--)
            printf("%d ", path[i]);

        printf("\nDistance: %d\n", len - 1);
    }

    return 0;
}
