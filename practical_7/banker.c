#include <stdio.h>

int main()
{
    int i,j,k;
    int n = 5; // processes
    int m = 4; // resources

    int alloc[5][4] = {
        {0,0,1,4},
        {0,6,3,2},
        {0,0,1,2},
        {1,0,0,0},
        {1,3,5,4}
    };

    int max[5][4] = {
        {0,6,5,6},
        {0,6,5,2},
        {0,0,1,2},
        {1,7,5,0},
        {2,3,5,6}
    };

    int avail[4] = {1,6,2,0};

    int need[5][4];
    int finish[5]={0};
    int safe[5];

    printf("\nALLOCATION TABLE\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",alloc[i][j]);
        }
        printf("\n");
    }

    printf("\nMAX TABLE\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",max[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nNEED TABLE\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    printf("\nAVAILABLE RESOURCES\n");
    for(i=0;i<m;i++){
        printf("%d ",avail[i]);
    }

    int count=0;

    while(count<n){
        for(i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;

                for(j=0;j<m;j++){
                    if(need[i][j] > avail[j]){
                        flag=1;
                        break;
                    }
                }

                if(flag==0){
                    for(k=0;k<m;k++){
                        avail[k]+=alloc[i][k];
                    }

                    safe[count]=i;
                    finish[i]=1;
                    count++;
                }
            }
        }
    }

    printf("\n\nSAFE SEQUENCE\n");

    for(i=0;i<n;i++){
        printf("P%d ",safe[i]);
    }

    printf("\n");

    return 0;
}
