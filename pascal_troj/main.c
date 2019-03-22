#include <stdio.h>
#include <stdlib.h>
long fact(int n){
int c;
long v=1;
for (c=1;c<=n;c++){
v=v*c;
}
return v;
}
int main()
{
    int i,n,c;

    printf("pocet riadkov:\n");
    scanf("%d", &n);

    for (i=0; i<n; i++){
        for(c=0;c<=(n-i-2); c++){
        printf(" ");
    }
    for (c=0;c<=i;c++){
        printf("%ld ", fact(i)/(fact(c)*fact(i-c)));

    }
    printf("\n");
    }
    return 0;
}
