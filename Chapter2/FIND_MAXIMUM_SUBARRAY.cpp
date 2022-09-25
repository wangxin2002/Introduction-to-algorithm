//采用分治策略解决最大子数组问题,下面给出的是伪代码

FIND_MAXIMUM_SUBARRAY(int* A,int low, int high)  //寻找数组中的最大子数组
{
    if(high==low) return (low,high,A[low]);   
    int mid=(low+high)/2;
    (left-low,left-high,left-sum)=FIND_MAXIMUM_SUBARRAY(A,low,mid);  //全在左子数组中的最大连续子数组
    (right-low,right-high,right-sum)=FIND_MAXIMUM_SUBARRAY(A,mid+1,high);//全在右子数组中的最大连续子数组
    (cross-low,cross-high,cross-sum)=FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high);//横跨左右数组的最大连续子数组
    if(left-sum>=right-sum and left-sum>=cross-sum) return(left-low,left-high,left-sum);
    else if(right-sum>=left-sum and right-sum>=cross-sum) return(right-low,right-high,right-sum);
    else return(cross-low,cross-high,cross-sum); 
}

FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high);//找出横跨左右数组的最大连续子数组
{
    left-sum=-999999999999999;
    sum=0;
    for(int i=mid;i>=low;--i)
    {
        sum+=A[i];
        if(sum>left-sum) 
        {
            left-sum=sum;
            max-left=i;
        }
    }

    right-sum=-99999999999999;
    sum=0;
    for(int j=mid+1;j<=high;++j)
    {
        sum+=A[j];
        if(sum>right-sum)
        {
            right-sum=sum;
            max_right=j;
        }
    }
    return(max_left,max_right,left-sum+right-sum);
}

//下面为最大子数组问题的一种线性非递归算法，见算法导论4.1-5.
LinearTime_MaximumSubArray(int* array,int low,int high)
{
    int sum=INT_MIN;
    int leftIndex=low;
    int rightIndex=low;
    int subArraySum=0;
    int subLeftIndex=low;
    for(int i=low;i<=high;++i)
    {
        subArraySum+=array[i];
        if(subArraySum>sum)
        {
            sum=subArraySum;
            leftIndex=subLeftIndex;
            rightIndex=i;
        }
        if(subArraySum<0)
        {
            subArraySum=0;
            subLeftIndex=i+1;
        }
    }

    return(leftIndex,rightIndex,sum);
}