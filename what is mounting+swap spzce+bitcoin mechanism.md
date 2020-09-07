#### what is mounting ?

mounting 是将一个外部文件系统挂载到一个已存在、可访问的文件系统当中的过程。

The mount point is the directory (usually an empty one) in the currently accessible filesystem to which a additional filesystem is mounted. It becomes the root directory of the added directory tree, and that tree becomes accessible from the directory to which it is mounted. 

#### swap space

for virtual memory which is simulating additional main memory

set up when installing OS 

usually a dedicated partition

we can touch a new swap file using command mkswap in spite of unrecommendation of swap file use.

recommend 2 times larger than main M

##### Does swapfiles and swap partition have a different performance?

  No, for linux kernel 2.6, when OS need to transfer some data to swap, it will bypass the currently existing filesystem and directly access blocks to which swap file resides on. Similarly, if you have a swap partition, kernel will do same thing (directly access). So , it looks like a different performance between swap file and partiton( usually hold the view that partition is more closer to low hierarchy of SSD/HDD) , but actually it's opposite.

#### bitcoin : a peer-to-peer electronic cash system

每一个分布式节点都有自己的私钥和公钥，并维护着区块链的副本。

区块链中的每一个区块的区块头记录着上一个区块的哈希值

哈希值可以输入一段message以及私钥获得一段256比特的01序列（加入采用SHA256加密）

哈希指针，不断向前指向区块链的创世区块

这也就保证不可篡改性，更改任何一个区块的内容（比如交易信息）那么都会改变该区块的哈希值使得整条链一分为二，如果重新连起来，还需要更改下一个区块的哈希指针，进而又得改变下一个区块的随机数使得哈希值满足前N个比特为0的下一个区块哈希值特征，以此类推，要改变中间一个区块的内容，那么就得改掉之后所有相连接区块的内容，这对于目前的算力而言，不可实现。

##### 是否能伪造别人给自己转账（也就是伪装成别人来记录区块信息）？

不可实现，私钥和公钥机制，因为私钥只存在于区块拥有者手中，这样代替别人伪造的区块信息内容是不被其他分布式节点所接受的，也就不可能加入。

##### 如何知道这个人是否有足够的钱进行转账（也就是该用户的鉴权操作）

鉴权在中央（非分布式）的体系下，是由可信任的第三方进行的；在分布式系统中，每一个节点，在要记录这笔账目时，都会回溯之前所有与之相关的区块内容，来计算鉴权对于该笔交易是否有效。鉴权部分交给了每一个分布式节点，如果节点计算认为是有效的，那么，将会进行记账。



同时计算出新区块，遵循最长链原则

SHA256加密是不可逆的，虽然目前没有严谨的证明，根据加密出的内容，再反推出message信息是一件困难的事情，但是事实是，目前没有方法可以实现逆向反推。

bitcoin规定每个区块存储2400个交易信息，因此交易是缓慢的；

##### 运行网络的步骤

新交易向全部节点广播

每个节点将新交易都收集到一个新的区块

每个节点为这个区块（实际上，目前这个区块还没有连接到链上）寻找工作量证明proof of work 也就是计算该区块的随机数的数值，如果哪个节点先算出来了，那么就会向所有节点广播这个区块（如果多个节点同时算出，最长链原则）

（如果哪个节点计算出该区块，那么它将获得一笔奖励，从最初的50BTC折半递减，同时这也是增加整个比特币数量的唯一方式）

各个节点在检查该区块内所有的交易是有效的，且之前没有被支付的情况下，接收这个区块

接收区块的方式：将区块链中最后一个区块的哈希值写入此区块头，即可加入区块链



每个不包含交易的区块头大约80字节，每十分钟新产生一个区块，一年增加的区块的大小约为4.2MB，因此区块链中大部分内容都是交易信息，下载挖矿软件，需要先同步整条链的信息，目前大约有10GB；

区块链做到了去中心化，不需要一个可信任的第三方，即可实现交易的正常进行，原先的第三方信任机制被转换成了算力证明（这也是唯一可以攻击区块链的方式，即掌握算力优势）；

根据区块链的机制，攻击者只能够将自己钱通过交易所变现，然后获得真金白银之后，伪造没有发生这比支出交易的信息，并在所有人之前，算出包含该信息的区块随机数，这笔支出将变得没有发生。

区块链可以做到的是，每个主主体（人，机器，机构等）都可以不需要第三方认证的情况下，直接进行敏感操作，且不会被别人伪装成自己发出这种敏感操作，其余的主体根据回溯进行鉴权；所以特点就是绝对的不可抵赖性。鉴权操作根据业务不同而异：交易、政府政务etc

**参考资料**

1- bitcoin : a peer-to-peer electronic cash system

2- 3B1B https://www.youtube.com/watch?v=bBC-nXj3Ng4

3- paperclip https://www.bilibili.com/video/av83366647/

