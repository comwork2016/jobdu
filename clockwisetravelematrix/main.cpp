#include <stdio.h>
#include <stdlib.h>

/*
   输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵：
   1 2 3 4
   5 6 7 8
   9 10 11 12
   13 14 15 16
   则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
   输入：
   输入可能包含多个测试样例，对于每个测试案例，
   输入的第一行包括两个整数m和n(1<=m,n<=1000)：表示矩阵的维数为m行n列。
   接下来的m行，每行包括n个整数，表示矩阵的元素，其中每个元素a的取值范围为(1<=a<=10000)。
   输出：
   对应每个测试案例，输出一行，
   按照从外向里以顺时针的顺序依次打印出每一个数字，每个数字后面都有一个空格。
 */
int main()
{
        int **m;
        int row,col;
        while(scanf("%d %d",&row,&col) != EOF)
        {
                m = (int**)malloc(sizeof(int*)*row);
                int i;
                for(i = 0; i < row; i++)
                {
                        m[i] =(int*)malloc(sizeof(int)*col);
                }
                for(i = 0; i < row; i++)
                {
                        int j;
                        for(j = 0; j < col; j++)
                        {
                                scanf("%d",&m[i][j]);
                        }
                }
                int up = 0;
                int right = col-1;
                int down = row-1;
                int left = 0;
                while(up <= down && left <= right)
                {
                        int j;
                        // left to right
                        if(up <= down)
                        {
                                for(j = left; j <= right; j++)
                                {
                                        printf("%d ",m[up][j]);
                                }
                                up++;
                        }
                        // up to down
                        if(left <= right)
                        {
                                for(j = up; j <= down; j++)
                                {
                                        printf("%d ",m[j][right]);
                                }
                                right--;
                        }
                        // right to left
                        if(up <= down)
                        {
                                for(j = right; j >= left; j--)
                                {
                                        printf("%d ",m[down][j]);
                                }
                                down--;
                        }
                        // down to up
                        if(left <= right)
                        {
                                for(j = down; j >= up; j--)
                                {
                                        printf("%d ",m[j][left]);
                                }
                                left++;
                        }
                }
                printf("\n");
        }
        return 0;
}
