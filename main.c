#include "graph.h"
#include "file_read.h"
#include <stdlib.h>
#include <stdio.h>

/*VYTVOŘENÍ JEDNODUCHÉHO GRAFU*/

int testGraph(char *file_name, unsigned int start, unsigned int end) {
    unsigned int num_of_nodes;
    FILE *file = fopen(file_name, "r");
    if (!file)
        return -1;
    num_of_nodes = countNodes(file);
    tNode *graph = (tNode *) malloc(num_of_nodes * sizeof(tNode));
    printf("==================================================================\n");
    printf("Počet uzlů: %d\n\n", num_of_nodes);
    printf("Po přečtení souboru: \n");
    printf("----------------------------------------------------\n");
    fileRead(file, graph, num_of_nodes);
    graphPrint(graph, num_of_nodes);
    printf("----------------------------------------------------\n\n");
    unsigned int *path = NULL;
    unsigned int path_length = 0;
    printf("Po vyhledání nejkratší cesty: \n");
    printf("----------------------------------------------------\n");
    shortestPath(graph, num_of_nodes, start, end, &path, &path_length);
    distancePrint(graph, num_of_nodes);
    printf("----------------------------------------------------\n\n");
    printf("Nejkratší cesta z uzlu | %d | do uzlu | %d | : \n", start, end);
    if (path_length == 0) {
        printf("Cesta neexistuje!");
    } else {
        for (unsigned int i = 0; i < path_length; ++i) {
            printf("| %d | ", path[i]);
        }
    }
    unsigned int num_of_paths = 0;
    findAllShortestPaths(graph, num_of_nodes, start, end, &path, &path_length,&num_of_paths);
    printf("\n\nPočet nejkratších cest: %d", num_of_paths);
    printf("\n==================================================================\n");
    fclose(file);
    graphRemove(graph, num_of_nodes);
    free(path);
    return 0;
}


int main() {
    testGraph("../graph.txt", 1, 4);
}
