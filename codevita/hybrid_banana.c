#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 300   // maximum spots including across trees
#define INF 999999

int graph[MAX][MAX];
int spotIndex[200][150]; // maps (spot, treeId) -> global index
int indexCount = 0;

int treeOfIndex[MAX];
int spotOfIndex[MAX];

int spotToTrees[200][150];
int treeCount[200];

int dist[MAX], visited[MAX];
int N; // number of total unique nodes

// Find minimum distance node
int getMinNode() {
    int min = INF, idx = -1;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char line[256];
    int trees[150][50][10];
    int treeSizes[150] = {0};
    int currTree = 0;

    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "break", 5) == 0) {
            currTree++;
            continue;
        }

        int nums[10], count = 0;
        char *token = strtok(line, " \n");
        while (token) {
            nums[count++] = atoi(token);
            token = strtok(NULL, " \n");
        }

        if (count == 2 && i == n - 1) { // last line: start, end
            start = nums[0];
            end = nums[1];
            break;
        }

        for (int j = 0; j < count; j++)
            trees[currTree][treeSizes[currTree]][j] = nums[j];
        treeSizes[currTree]++;
    }

    // Initialize graph with INF
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            graph[i][j] = INF;

    // Assign global indices for (spot, tree)
    for (int t = 0; t <= currTree; t++) {
        for (int i = 0; i < treeSizes[t]; i++) {
            for (int j = 0; trees[t][i][j]; j++) {
                int spot = trees[t][i][j];
                int already = 0;
                for (int k = 0; k < treeCount[spot]; k++)
                    if (spotToTrees[spot][k] == t)
                        already = 1;
                if (!already) {
                    spotToTrees[spot][treeCount[spot]++] = t;
                    spotIndex[spot][t] = indexCount;
                    treeOfIndex[indexCount] = t;
                    spotOfIndex[indexCount] = spot;
                    indexCount++;
                }
            }
        }
    }

    N = indexCount;

    // Add up/down edges
    for (int t = 0; t <= currTree; t++) {
        for (int i = 0; i < treeSizes[t]; i++) {
            int parent = trees[t][i][0];
            for (int j = 1; trees[t][i][j]; j++) {
                int child = trees[t][i][j];
                int pIdx = spotIndex[parent][t];
                int cIdx = spotIndex[child][t];

                graph[pIdx][cIdx] = 0; // down
                graph[cIdx][pIdx] = 1; // up
            }
        }
    }

    // Add cross-tree edges (switch trees)
    for (int s = 1; s < 200; s++) {
        if (treeCount[s] > 1) {
            for (int i = 0; i < treeCount[s]; i++) {
                for (int j = i + 1; j < treeCount[s]; j++) {
                    int a = spotIndex[s][spotToTrees[s][i]];
                    int b = spotIndex[s][spotToTrees[s][j]];
                    graph[a][b] = 1;
                    graph[b][a] = 1;
                }
            }
        }
    }

    // Initialize distances
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Multiple possible start nodes (same spot across trees)
    for (int i = 0; i < treeCount[start]; i++) {
        int idx = spotIndex[start][spotToTrees[start][i]];
        dist[idx] = 0;
    }

    // Dijkstra (simple array version)
    for (int step = 0; step < N - 1; step++) {
        int u = getMinNode();
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // Find min distance among all end spot nodes
    int answer = INF;
    for (int i = 0; i < treeCount[end]; i++) {
        int idx = spotIndex[end][spotToTrees[end][i]];
        if (dist[idx] < answer)
            answer = dist[idx];
    }

    if (answer == INF)
        printf("-1\n");
    else
        printf("%d\n", answer);

    return 0;
}
