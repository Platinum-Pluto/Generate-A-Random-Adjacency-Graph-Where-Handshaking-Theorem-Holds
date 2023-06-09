#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a[5001][5001];
int main()
{
    clock_t t,h,print_time;
    int i,j,edge_amount,k,l,degree,total_degree=0,n;
    double computational_timei,computational_timeii,computational_timeiii;
    float nano_time;
    printf("Enter Vertices: ");
    scanf("%d",&n);
    printf("\nGenerating random adjacency graph\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    t=clock();                  //starting time of whole function
    srand(time(NULL));
    edge_amount=rand();
    h=clock();                  //Starting time of graph generation
    for(i=0;i<edge_amount;i++)
    {
        k=rand()%n;
        l=rand()%n;
        a[k][l]=a[k][l]+1;
        a[l][k]=a[l][k]+1;
    }
    h=clock()-h;             //Ending time of graph generation
    for(i=0;i<n;i++)
    {
        degree=0;
        for(j=0;j<n;j++)
        {
            degree=degree+a[i][j];
        }
        total_degree=total_degree+degree;
    }
    if(total_degree==edge_amount*2)                  //checking if The Handshaking theorem holds or not
    {
        print_time=clock();                             //printing time
        printf("\n\nThe Handshaking theorem holds\n");
        print_time=clock()-print_time;                 //printing time
    }
    else{
        print_time=clock();                            //printing time
        printf("\n\nThe Handshaking theorem does not hold\n");
        print_time=clock()-print_time;                 //printing time
    }
    t=clock()-t;                                       //Ending time of whole function
    computational_timei=((double)t)/CLOCKS_PER_SEC;
    computational_timeii=((double)h)/CLOCKS_PER_SEC;
    computational_timeiii=((double)print_time)/CLOCKS_PER_SEC;
    nano_time=((computational_timei-computational_timeii)-computational_timeiii)*1000000000;
    printf("\nTotal edges = %d",edge_amount);
    printf("\nTotal degrees= %d\n\nComputational time of counting edges and determining degrees in nanoseconds %f ns",total_degree,nano_time);
    printf("\n");

}


