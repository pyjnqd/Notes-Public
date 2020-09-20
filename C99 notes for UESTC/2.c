/*
    基本数据类型
    char
    int: usually stand for the natural size of a integer in one PC
    float
    double
    限定符：short & long
    short/long (int)  formmer maybe 16 bits latter maybe 32 bits 
    int 16/32bit
    long double 更高精度浮点数，精度不会低于double
    signed and unsigned 可修饰char或者整型
    signed char -128~127  un- char 0-255
    un- >= 0

    常量的修饰：直接在常量后面 整数 L UL 浮点数 F L:long double
    八进制 0开头 十六进制 0x开头
    转义字符  
    一个字符可以表示八进制数 或者是 十六进制数
    \ooo o是八进制数字  \xhh 十六进制
    \577 实际上是127 也就是八进制\177 一个八进制数3bit 一个\ooo就是一个字符 占用8bit 那么最高位就会被截断
    同理\xhh 也是8个bit 一个h是4bit正好可以表示一个十六进制数
*/
// #include <string.h>
// #include <stdio.h>
// int main(){
    
//     //printf("%d=%d", sizeof()); 
//     enum Day{Mon=0,Tues,Wed,Thurs,Fri};
//     enum Day day;
//     printf();
// }
/*
    enum 枚举类型 创建一个“数据”类型 枚举元素的排序值从0开始，以此类推 如果没指定值的话
    从前一个有值的地方依次+1
    或者分别全部挨个指定值
    初始化枚举变量时，enum关键字表明枚举本身 Day表明哪个枚举类型 day指示枚举变量
    枚举变量在一个时刻代表一个元素/元素对应的数值
    枚举变量声明后，变量的值为null/0

    C语言不存在布尔型变量 非0true
*/
/*
 \r return oldline begin  回车 回到当前行的开头（口语回车被误用）
 \n newline begin  下一行的开头
 windows系统下每一行的结尾是\r\n 
 Unix下只用\n Mac机只用\r  作为换行 因此linux和mac机器的文本文件在windows下打开会变成一行
 两个字符串常量 “123”中间不加任何运算符“456”即可实现拼接 或者是使用strcat()

 C99 引入了long long 用来表示64位整数  C89中 int是机器中整数的自然长度 
 long short作为修饰 分别<=int >=int 也就是可能16位或者是32位 而32位的整数 仅仅是-32768~32767
 C99的long long比long更长 也就是64位
 
 size_t类型：用来表示对象大小的类型 看上去是一个正整数 为8字节 主要是为了解决unsigned int（32bits）最大65536
 也不能足够空间表示某些对象的字节数的情况 

 printf("%d%d", sizeof(" "),strlen(" ")); 21 sizeof对象字节数 一个空格+\0=2 strlen字符串长度不含\0=1
 sizeof(NULL) =8 (void *)0 指针类型 not point anywhere

 大端：一个对象多个字节，这些字节在内存中如何排放，对象字节的高地址在内存的低地址
 小端：对象字节的高地址在内存的高地址
 x86是小端，很多也是小端，x86的栈向下生长，并且高地址在高处（内存高地址是内核空间）低地址在低处
*/



// #include <stdio.h>
// int main(){
//     char s[] = "3256452";
//     int n = 0;
//     for(int i=0;s[i]>='0'&&s[i]<='9';i++)
//         n = n*10 + (s[i]-'0');
//     printf("%d", n);
// }
/*
    const 常量修饰符，常：固定的不变的，一旦确定不可改变，底层实现时，会将其
    放在只读区 写会发生read-only错误
*/

// #include <stdio.h>
// int main(){
//     int i = 278;
//     char c = 3;
//     c = i;
//     i = c;
//     printf("%d", i);//22 int超出8bit的部分被直接截取
    // float f = 23.49999151263199988877;
    // double d = 23.49999151263199988877;
    // f = d;
    // printf("%.18f", f);
// }
/*
    double的64位标准下能表示15位的有效数字（含整数部分）float只有7位有效数字（含整数）
    double赋float时候，超过有效位数的精度直接被截断或者四舍五入，看具体实现
*/

/*
    一个有意思的例子
    -1L和1U比较，按理说是-1L<1U，比较时，先看long int 能不能把unsigned int覆盖（u肯定不会覆盖l）
    老式的机器上，int16位，long32位，long int +-31位完全可以覆盖unsigned int，那么unsigned int变成了long int
    因为比较时要转换成一种数值类型；
    但是现代的机器都是int和long 32位的，所以；long int自然不能覆盖unsigned int，因此两种数据类型互相不能覆盖，那就
    都升级为更高的同一种数据类型 unsigned long；-1L是0xFFFFFFFF自然比1U的0x00000001大

    强制转换生成一个强制类型的临时变量，原本的变量的值并没有变

    += 与 =  + 的区别，显式上一个调用了1次，一个调用了2次，的确如此，但是一般编译器都会优化掉
    但是用户自定义的数据类型 可能区别就比较大了
*/

// 

