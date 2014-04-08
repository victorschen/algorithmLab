说明：
本项目是针对算法导论/微软100题系列/Unix网络编程中出现经典案例的进行编程实践和探讨
项目中目录说明如下：
algo_intro - 对应算法导论
ms_seq - 微软100题系列
uni_seq - Unix网络编程系列
c_test - C的特性一些测试

项目中所有源码经过gcc编译通过
编译环境：Ubuntu12.04_i386 + gcc

更新说明：

20140408
========
实现带头双链表的插入，删除操作,包括头插法和尾插法
实现无头双链表的插入，删除操作,包括头插法和尾插法

问题与启发：
1.变量尤其指针变量，务必养成声明时即初始化的好习惯，否则很容易导致Segmentation fault (core dumped)的问题
    如创建双链表头指针head后未初始化为NULL，显然它的值就不为NULL，这时若判断不为NULL而执行head->next将core dumped
    如创建一个指针变量，而这时若未用malloc为指针开辟空间,而后又对它进行赋值，则将core dumped
2.当程序出现core dumped时，该如何调试
    一般core dumped会产生core文件，如果没有产生，使用命令
        vic@vic-PC$ ulimit -c unlimited
    即可设置为不限制生成core文件的大小
    然后使用命令
        gcc -g -o test test.c
    生成gdb调试符号,再在gdb中调试core dumped产生的位置
        gdb -c core test

    
