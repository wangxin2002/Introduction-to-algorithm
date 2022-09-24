#include <iostream>
using namespace std;

void insertion_sort(int x[],int length) //插入排序算法
{
    for(int i=1;i<length;++i)
    {
        int key=x[i];
        int j=i-1;
        while (j>=0 and x[j]>key)
        {
            x[j+1]=x[j];
            j=j-1;
        }
        x[j+1] = key;
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int j=0;j<n;++j) cin>>array[j];
    insertion_sort(array,n);
    for(int i=0;i<n;++i) cout<<array[i]<<' ';
    cout<<endl;
    return 0;
}