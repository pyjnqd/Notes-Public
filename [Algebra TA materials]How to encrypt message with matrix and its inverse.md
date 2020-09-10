#### How to encrypt message with matrix and its inverse?
 对于消息加密使用矩阵和逆矩阵，原理非常简单，用于给2020级大一新生线性代数助教课上作为例子介绍。
  Example：
  I have a message and need to transfer on internet, so encryption is required.
  message M : THE EAGLE HAS LANDED
  encoding matrix : ![coding m](https://www.austincc.edu/lrosen/1314/webact2/Image98.gif)

mechanism is simple : $AM=X$为加密过程；$M=A^{-1}X$为解密过程  

实现双方需要知道秘钥，即$M$矩阵

如果认为A是1 B是2 C是3 white space为0的话，message可以被编码为：

$20, 8 ,5, 0, 5, 1, 7, 12, 5, 0, 8, 1, 19, 0, 12, 1, 14, 4, 5, 4$

需要保证的是，M矩阵的行数和A矩阵的维度保持一致，A矩阵为方阵，且保证有逆

加密消息矩阵第一列：![encryption-col1](https://www.austincc.edu/lrosen/1314/webact2/Image99.gif)

依次类推，可以获得整个消息矩阵的加密结果（消息矩阵元素不够维度要求的话，末尾补0表示多几个空格）

$A^{-1}$:![inverse -A](https://www.austincc.edu/lrosen/1314/webact2/Image101.gif)

解密encrypted 矩阵第一列：![anti-encrypted-col1](https://www.austincc.edu/lrosen/1314/webact2/Image102.gif)

