#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int array[40];
    srand(time(NULL));
    for (i=0; i<3; i++){
        array[i] = rand()%6 + 1;
        printf("%d", array[i]);
    }
    return (EXIT_SUCCESS);
}
