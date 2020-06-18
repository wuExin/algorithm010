学习笔记
1.找重复元素问题想到hashMap
2.hashMap总结
3.树 ①前序遍历 根->左->右  ②中序遍历 左->根->右 ③后序遍历 左->右->根
4.二叉搜索树
5.堆：二叉堆，斐波那契堆
findMax or findMin : O(1) insert: O(log n) deleteMax or deleteMin O(log n)

二叉堆父节点找子节点  左：i*2 + 1 右： i*2+2
二叉堆子节点找父节点  floor((i-1)/2)