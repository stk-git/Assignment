#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int get_network_quality(int **towers, int num_towers, int radius, int x, int y) {
    int quality = 0;
    for (int i = 0; i < num_towers; i++) {
        int dx = x - towers[i][0];
        int dy = y - towers[i][1];
        int d = sqrt(dx*dx + dy*dy);
        if (d <= radius) {
            quality += towers[i][2] / (1 + d);
        }
    }
    return quality;
}

void get_best_coordinate(int **towers, int num_towers, int radius, int *best_coordinate) {
    int max_quality = INT_MIN;
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            int quality = get_network_quality(towers, num_towers, radius, x, y);
            if (quality > max_quality) {
                max_quality = quality;
                best_coordinate[0] = x;
                best_coordinate[1] = y;
            } else if (quality == max_quality) {
                if (x < best_coordinate[0]) {
                    best_coordinate[0] = x;
                    best_coordinate[1] = y;
                } else if (x == best_coordinate[0] && y < best_coordinate[1]) {
                    best_coordinate[1] = y;
                }
            }
        }
    }
}

int main() {
    int num_towers,radius;
    printf("enter no of towers:");
    scanf("%d",&num_towers);
    printf("enter the radius:");
    scanf("%d",&radius);
    int **towers = malloc(num_towers * sizeof(int *));
    for (int i = 0; i < num_towers; i++) {
        towers[i] = malloc(3 * sizeof(int));
    }
    for (int i=0;i<num_towers;i++)    
    {    
        for (int j=0;j<3;j++)    
        {    
            printf("Enter tower[%d][%d]: ",i,j);                
            scanf("%d",&towers[i][j]);    
        }    
    }    
    int best_coordinate[2];
    get_best_coordinate(towers, num_towers, radius, best_coordinate);
    printf("(%d, %d)\n", best_coordinate[0], best_coordinate[1]);

    // Free memory
    for (int i = 0; i < num_towers; i++) {
        free(towers[i]);
    }
    free(towers);

    return 0;
}
