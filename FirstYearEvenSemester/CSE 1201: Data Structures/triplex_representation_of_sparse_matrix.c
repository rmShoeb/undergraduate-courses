#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int sparse_matrix[5][5];
    int triplex_representation[5][3];
    int i,j;
    int k=0;
    int nrows=0;

    printf("Enter the sparse matrix here:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            scanf("%d",&sparse_matrix[i][j]);
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(sparse_matrix[i][j]!=0)
            {
                triplex_representation[k][0]=i;
                triplex_representation[k][1]=j;
                triplex_representation[k][2]=sparse_matrix[i][j];
                k++;
                nrows++;
            }
        }
    }

    printf("The triplex representation of the Sparse matrix:\n");
    printf(" Row || Column || Data\n");
    printf("______________________\n");
    for(i=0;i<nrows;i++)
    {
        printf("  %d  ||   %d    ||  %d\n",triplex_representation[i][0],triplex_representation[i][1],triplex_representation[i][2]);
        printf("______________________\n");
    }

    return 0;
}
