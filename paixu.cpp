#include "paixu.h"

/**
排序算法经过了很长时间的演变，产生了很多种不同的方法。对于初学者来说，对它们进行整理便于理解记忆显得很重要。
每种算法都有它特定的使用场合，很难通用。因此，我们很有必要对所有常见的排序算法进行归纳。

排序大的分类可以分为两种：内排序和外排序。在排序过程中，全部记录存放在内存，则称为内排序，
如果排序过程中需要使用外存，则称为外排序。下面讲的排序都是属于内排序。

内排序有可以分为以下几类：

　　(1)、插入排序：直接插入排序、二分法插入排序、希尔排序。

　　(2)、选择排序：直接选择排序、堆排序。

　　(3)、交换排序：冒泡排序、快速排序。

　　(4)、归并排序

　　(5)、基数排序

表格版

排序方法	时间复杂度（平均）	时间复杂度（最坏)	时间复杂度（最好)	空间复杂度	稳定性	复杂性
直接插入排序	O(n2)O(n2)	O(n2)O(n2)	O(n)O(n)	O(1)O(1)	稳定	简单
希尔排序	O(nlog2n)O(nlog2n)	O(n2)O(n2)	O(n)O(n)	O(1)O(1)	不稳定	较复杂
直接选择排序	O(n2)O(n2)	O(n2)O(n2)	O(n2)O(n2)	O(1)O(1)	不稳定	简单
堆排序	O(nlog2n)O(nlog2n)	O(nlog2n)O(nlog2n)	O(nlog2n)O(nlog2n)	O(1)O(1)	不稳定	较复杂
冒泡排序	O(n2)O(n2)	O(n2)O(n2)	O(n)O(n)	O(1)O(1)	稳定	简单
快速排序	O(nlog2n)O(nlog2n)	O(n2)O(n2)	O(nlog2n)O(nlog2n)	O(nlog2n)O(nlog2n)	不稳定	较复杂
归并排序	O(nlog2n)O(nlog2n)	O(nlog2n)O(nlog2n)	O(nlog2n)O(nlog2n)	O(n)O(n)	稳定	较复杂
基数排序	O(d(n+r))O(d(n+r))	O(d(n+r))O(d(n+r))	O(d(n+r))O(d(n+r))	O(n+r)O(n+r)	稳定	较复杂

① 插入排序
•思想：每步将一个待排序的记录，按其顺序码大小插入到前面已经排序的字序列的合适位置，直到全部插入排序完为止。
•关键问题：在前面已经排好序的序列中找到合适的插入位置。
•方法：
–直接插入排序
–二分插入排序
–希尔排序

(1)直接插入排序（从后向前找到合适位置后插入）

1、基本思想：每步将一个待排序的记录，按其顺序码大小插入到前面已经排序的字序列的合适位置（从后向前找到合适位置后），
直到全部插入排序完为止。


(2)二分法插入排序（按二分法找到合适位置插入）

1、基本思想：二分法插入排序的思想和直接插入一样，只是找合适的插入位置的方式不同，这里是按二分法找到合适的位置，
可以减少比较的次数。

(3)希尔排序

1、基本思想：先取一个小于n的整数d1作为第一个增量，把文件的全部记录分成d1个组。所有距离为d1的倍数
的记录放在同一个组中。先在各组内进行直接插入排序；然后，取第二个增量d2

② 选择排序
•思想：每趟从待排序的记录序列中选择关键字最小的记录放置到已排序表的最前位置，直到全部排完。
•关键问题：在剩余的待排序记录序列中找到最小关键码记录。
•方法：
–直接选择排序
–堆排序

(1)直接选择排序

1、基本思想：在要排序的一组数中，选出最小的一个数与第一个位置的数交换；然后在剩下的数当中再找最小
的与第二个位置的数交换，如此循环到倒数第二个数和最后一个数比较为止。

(2)堆排序

1、基本思想：

　　堆排序是一种树形选择排序，是对直接选择排序的有效改进。

　　堆的定义下：具有n个元素的序列 （h1,h2,…,hn),当且仅当满足（hi>=h2i,hi>=2i+1）或
（hi<=h2i,hi<=2i+1） (i=1,2,…,n/2)时称之为堆。在这里只讨论满足前者条件的堆。由堆的定义可以看出，
堆顶元素（即第一个元素）必为最大项（大顶堆）。完全二叉树可以很直观地表示堆的结构。堆顶为根，其它为左子树、右子树。

　　思想：初始时把要排序的数的序列看作是一棵顺序存储的二叉树，调整它们的存储序，
使之成为一个堆，这时堆的根节点的数最大。然后将根节点与堆的最后一个节点交换。
然后对前面(n-1)个数重新调整使之成为堆。依此类推，直到只有两个节点的堆，并对它们作交换，
最后得到有n个节点的有序序列。从算法描述来看，堆排序需要两个过程，一是建立堆，
二是堆顶与堆的最后一个元素交换位置。所以堆排序有两个函数组成。一是建堆的渗透函数，二是反复调用渗透函数实现排序的函数。

(1)冒泡排序

1、基本思想：在要排序的一组数中，对当前还未排好序的范围内的全部数，自上而下对相邻的两个数依次
进行比较和调整，让较大的数往下沉，较小的往上冒。即：每当两相邻的数比较后发现它们的排序与排序要求相反时，
就将它们互换。

(2)快速排序

1、基本思想：选择一个基准元素,通常选择第一个元素或者最后一个元素,通过一趟扫描，
将待排序列分成两部分,一部分比基准元素小,一部分大于等于基准元素,此时基准元素在其排好序后的正确位置,
然后再用同样的方法递归地排序划分的两部分。

④ 归并排序
1、基本思想:归并（Merge）排序法是将两个（或两个以上）有序表合并成一个新的有序表，即把待排序序列
分为若干个子序列，每个子序列是有序的。然后再把有序子序列合并为整体有序序列。

⑤ 基数排序
1、基本思想：将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零。然后，
从最低位开始，依次进行一次排序。这样从最低位排序一直到最高位排序完成以后,数列就变成一个有序序列。
  */


