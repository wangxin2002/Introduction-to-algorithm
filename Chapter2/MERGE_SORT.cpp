void MERGE_SORT(int* array,int p, int r)//归并排序算法, p、r分别为首尾位置.递归实现
{
    if(p<r)
    {
        int q=(p+r)/2;
        MERGE_SORT(array,p,q);
        MERGE_SORT(array,q+1,r);
        MERGE(array,p,q,r);
    }
}

void MERGE(int* array,int p,int q,int r)//归并算法，将排好序的左右两部分合并;可看作两幅牌，每次取出两个顶部中最小的那张
{
    int n1=q-p+1;  //左边数组长度
    int n2=r-q;    //右边数组长度
    int Larray[n1+1];
    int Rarray[n2+1];
    for(int i=0;i<n1;++i) Larray[i]=array[p+i];
    for(int j=0;j<n2;++j) Rarray[j]=array[q+1+j];
    Larray[n1]=9999999999999;
    Rarray[n2]=9999999999999;  //作为哨兵位置
    int i=0,j=0;
    for(int k=p;k<=r;++p)
    {
        if(Larray[i]<=Rarray[j])
        {
            array[k]=Larray[i];
            i+=1;
        }
        else
        {
            array[k]=Rarray[j];
            j+=1;
        }
    }
}