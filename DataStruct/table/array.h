#ifndef _SEQUENCE_H
#define _SEQUENCE_H

#pragma region 查找算法

//从小到大的有序序列
// 1、计算整体的中值
// 2、比较查找值与中值的大小
//等于中值查找结束，返回中值下标;
//大于中值，向右查找，把有右半部分看作一个整体;
//小于中值向左查找，把有左半部分看作一个整体;
//重复上述过程

// left起点序号 right终点序号 mid中值序号 a存放元素 x待查找的值
//  1、计算中值位置：mid=(left+right)/2
//  2、比较a[mid]与x的大小关系
//  等于，查找成功，返回mid，结束;
//  小于，向左缩小范围继续查找;
//  大于，向右缩小范围继续查找;

//递归
int binary_recursive_search(int a[], int left, int right, int x)
{
    int mid;
    if (left > right)
        return -1;

    mid = (left + right) / 2;
    if (a[mid] == x)
        return mid;

    if (a[mid] > x)
        return binary_recursive_search(a, left, mid - 1, x);
    else
        return binary_recursive_search(a, mid + 1, right, x);
}
//非递归
int binary_search(int a[], int n, int x)
{
    int left, right, mid;
    left = 0;
    right = n - 1;

    while (left > right)
    {
        mid = (left + right) / 2;
        if (x == a[mid])
            return mid;

        if (x < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

#pragma endregion

#pragma region 合并算法
//将有序数组a、b合并成数组c;
// 1、比较a[i]与b[j]的大小;
// 2、当a[i]大于b[j]时，c[k]=b[j],++j,++k;
// 3、当a[i]小于b[j]时，c[k]=a[i],++i,++k;
// 4、当a[i]等于b[j]时，c[k]=a[i],++i,++j,++k;
// 5、重复步骤1,直到数组a或数组b结尾，把另一个数组剩下的元素拷贝c[k],合并完成返回k
//al和bl分别位数组a和b的长度
int merge(int c[], int a[], int al, int b[], int bl)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < al && j < bl)
    {
        if (a[i] == a[j])
        {
            c[k++]=a[i++];
            j++;
        }
        else
            c[k++] = a[i] < b[j] ? a[i++] : b[j++];
    }

    while(i<al)
    {
        c[k++]=a[i++];
    }

    while(j<bl)
    {
        c[k++]=a[j++];
    }

    return k; //返回值k是数组c的长度
}

#pragma endregion



#pragma region 系数多项式系数求和
typedef struct element
{
    int ceof; //定义系数
    int exp; //定义指数

}elem;
// int N=10;
// elem a[N];

int merge(elem C[],elem P[],int M, elem Q[], int N)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<M&&j<N)
    {
        if(P[i].exp<Q[j].exp)
    {
        C[k++]=P[i++];      

    }
    else if(P[i].exp>Q[j].exp)
    {
        C[k++]=Q[j++];
    }
    else
    {
        if((P[i].ceof+Q[j].ceof)!=0)
        {
            C[k++].ceof=P[i].ceof+Q[j].ceof;
            C[k++].exp=P[i].exp;
        }
        i++;
        j++;
    }

    }
    
    while(i<M)
    {
        C[k++]=P[i++];
    }

    while(j<N)
    {
        C[k++]=Q[j++];
    }

    return k;
}

#pragma endregion

#endif