#include <stdio.h>
int main()
 {
  int r, c, a[100][100];
  printf("Enter the number of rows \n");
  scanf("%d", &r);
  printf("Enter the number of columns \n");
  scanf("%d", &c);
  int b[c][r];
  printf("\nEnter elements of 1st matrix:\n");
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      printf("Enter element a%d%d: \n", i + 1, j + 1);
      scanf("%d", &a[i][j]);
    }
    int m=0,n=0;
 for (int i = 0; i < c; i++)
 {
    for (int j = 0; j < r; j++) 
         { 
             b[i][j]=a[m++][n];
             if(m==r)
             {
                 n++;m=0;
             }
         }
 }

printf("Transpose matrix is\n");
for (int i = 0; i < c; i++)
    {
    for (int j = 0; j < r; j++) 
    {
      printf("%d",b[i][j]);
    }
    printf("\n");
    }
}
