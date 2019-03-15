def counting_sort(A,B,k):
    C=[0 for x in range(0,k+1)]#创造出长度为k+1的列表,0->k
    for x in A:#计算A中各元素的个数
        C[x]+=1
    for i in range(1,k+1):#计算小于等于某数的个数
        C[i]+=C[i-1]
    for x in reversed(A):
        B[C[x]-1]=x#C[x]-1即x所处的顺序
        C[x]-=1#处理同样的值
A=[3,0,5,4,2,3]
B=[0,0,0,0,0,0]
counting_sort(A,B,5)
print(B)
#Time complexity:O(n+k) Space complexity:O(k)