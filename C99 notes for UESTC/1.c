/*
  转义字符为无法输入的字符和不可见字符提供了一种通用机制
  \t 制表符  一个dos窗口默认25行80列, 一个\t, 它会跳到下一个8的倍数的整数列上，所以一个制表符并不能确定等于多少个空格，根据实际情况而定
  \b 回退符 等于键盘的backspace ，一个\b删除掉前面已经进缓冲区的一个字符
  format control string execrise
  %c %s %% %d %o %x %f
  %6f six places at least 默认前补空格右对齐（+） 左对齐右补空格的话（-）
  %.2f keep 2 decimal places  %m.nf 一共m位 n个小数位 
*/
# include <stdio.h>
/* 
  # define set the symbol const ==> UPPER TYPE
  符号常量在编译时会用本来的值 替换掉 所有符号存在的地方
*/  

// # define START 0.0
// # define END 300.0
// # define STEP 20.0
// main(){
//     float fahr, celsius;
//     // float step = 20.0, start = 0.0, end = 300.0;
//     printf("%6s\t%6s\n", "fahr", "celsius");
//     fahr = START;//start;
//     while(fahr <= END/*end*/){
//         celsius = 5 * (fahr - 32) / 9;
//         printf("%6.1f \t%6.1f\n", fahr, celsius);
//         fahr += STEP;//step;
//     }
// }

/* -------------------------------------------------- */
/* 
    EOF = ENF OF FILE 
    getchar()在没有输入时，返回一个特殊值（与任何字符的值均不同）
    全1的 FFFFFFFF EOF作为符号常量定义在stdio.h文件中
    get/put char方法会将变量以char形式输出
    getchar使用时 开int 否则32位的EOF用char装不下
    开int 的原因，一方面EOF标志是32位的，一方面，不确定使用的是什么字符集，所以开32位

    异步+非阻塞  异步：不同步，不等待，进程发出IO请求之后，不管底层的硬件设备/设备驱动器是否
    反馈结果，都先行返回；底层存储设备完成请求之后，通过回调或者是一些标志变量，通知进程完成了IO
    同步+阻塞    同步==等待 进程一直等到IO请求完成并返回之后，再接着进行
    除了异步非阻塞可以解决这个等待问题之外，还有就是 多线程+同步  只有一个线程阻塞等待并不影响整个进程的执行

    windows的EOF为ctrl+z，但是终端内在末尾加ctrl+z是没有用的，因为之前有字符，就不认为会有EOF接在后面，因为EOF是getchar返回的，ctrl+z根本不会进
    输入缓冲区；想要终止的话，一行中只能有ctrl+z；
*/
// main(){
//     int c;
//     printf("%x\n", EOF);
//     while((c=getchar()) != EOF)
//         putchar(c);
// }



// int power(int m, int n); // 原型描述大概框架就行  比如也可以写成 int power(int , int )
// // 函数声明，没有实现，C/C++不同于Java，函数的调用也必须符合*先声明再调用*  函数原型
// // C/c++编译时 遇到的标识符进符号表 使用时检查是否在符号表 调用前必须声明
// // Java的methods都是以Object.<methods>来调用，使用对象前，成员都已经知道了

// main(){
//   int i;
//   for (i = 0; i < 10; ++i)
//   printf("%5d %5d %5d\n", i, power(2,i), power(3,i));
//   return 0;
// }

// int power(int base, int n){
//   int i, p;
//   p = 1;
//   for (i = 1; i <= n; ++i)
//   p = p * base;
//   return p;
// }

// C/C++ 值传递，并不改变原来的值本身；将副本加载到新的函数栈里去；可以传指针/地址来改变原本的值
// However, array is different;数组名是首地址，传数组名进调用函数，改的其本身；

// void tmp(int a[]){
//   a[1] = 0;
// }
// int main(){
//   int a[] = {1,2,3};
//   tmp(a);
//   printf("a[1] is : %d", a[1]);
// }

// a[1] is : 0

// main(){
//   printf("int : %d", sizeof('\0'));
//   printf("%x", '\0');
// }
 
/*
    为什么局部变量优先级高于全局变量？ 编译器在编译时，将变量存储在符号表中，符号表中是分hierarchy的
    static关键词  
    静态全局变量（全局变量默认是auto的，作用域是整个项目，也就是不限于本文件，别的文件可以通过extern获得该变量的引用
    静态全局则限制变量的范围在本文件内，只能被本文件的函数访问；extern时冲突报错；）
    静态局部变量（在函数内部设置static变量；即可以被该函数的多个运行次数实例共有；多次执行函数 静态局部不会被重新初始化，是上一次的值）
    extern关键词
    如果是extern在函数内扩展变量范围，则是将原本这个函数看不到的变量扩展进这个函数内（不常用）
    extern在别的文件中，则是将其他文件中的全局变量引进该文件，返回引用；
*/

/*
    C变量内存分配
    只读区域：Read only
        代码区（二进制代码）
        常量区（代码中的直接出现的数字、字符串、符号常量等）
    读写区：
        静态区+全局区：静态和全局是存在∩的关系，初始化的放在一起，未初始化的放在一起；
        栈：局部
        堆：malloc/calloc（malloc开辟不初始化，直接返回首地址指针；calloc会初始化为0；二者参数也不一样）free
        [命令行参数空间]
    
    编译期间分配内存：编译期间规划好了这些变量的内存使用方案
*/
/*
    全局变量、静态变量默认值都是0
    局部变量默认是随机值，具体多少取决于原来这块内存空间存的什么数
*/
// NULL = (void*)0 与内存0地址应该区分开，操作系统不会允许访问0地址



// 字符数组 表示 字符串
# define MAXLINE 1000

// 获取字符串，读到给定的字符数组中，返回长度；数组做参为指针传递
int getline(char *, int);
// copy到临时变量
void copy(char [], char []);

main(){
  int len;
  int max;
  char maxline[MAXLINE];  /* maxline of a string */
  char tmp[MAXLINE]; // 声明变量并在栈上开辟空间，内容随机
  
  max = 0;
  while( (len = getline(tmp, MAXLINE)) > 0 )
  {
    if(len > max)
    { max = len;copy(maxline, tmp);}
  }
  if (max > 0) printf("%s", maxline);
}

// char*和char []是一致的 本质上都是首元素的地址
 int getline(char *s, int lim){  
    int c, i;
    for( i=0;i<=lim-1 && (c=getchar()) != EOF && c != '\n';i++){
        s[i] = c;
    }
    if(c=='\n'){
      s[i] = c;
      i++;
    }
    s[i] = '\0';
    return i;
 }
 // 参数直接指向数组，不需要返回
 // 字符数组表示的字符串末尾是'\0'并也占一个比特的空间
void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\0'){
      i++;
    }
}

// extern 声明一般存在于 函数原型 和 函数之间  ；或者是通过h文件，include进来，在头部extern进来



