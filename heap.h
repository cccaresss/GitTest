/*heap.h*/  
/*使用指向数组的指针来实现一个堆*/  
/*堆：是一棵完全二叉树，除了最低层之外，每一层都是慢的，最低层节点靠左放 
 *        满足堆次序属性，每个双亲节点都大于或者等于子女的数据项 
 *注意：在堆实现的内部数组，我从array[ 1 ]开始存放数据 
 * 
 *删除最大项的方法:把数组的第一个数据和最后一个数据进行交换， 
 *                           同时，数组长度减1，这时候，堆不再是标准堆，需要进行下调 
 *添加一个数据项:把数据添加到数组的末尾，这时可能不再是标准堆，需要进行上调 
 */  
#ifndef HEAP_SORT_H  
#define HEAP_SORT_H 1  
#include <iostream>  
#include <cstdlib>  
template<typename T>  
class Heap  
{  
public:  
    //默认构造函数  
    Heap(  ):m_array( 0 ),m_size( 0 ),m_lenght( 0 ) {}  
    //分配length长度的数组  
    Heap( int length );  
    //析构函数  
    ~Heap(  )  
        { delete [  ] m_array;}  
    //插入一个数据项  
    bool insert( T item );  
    //判断是否为空  
    bool empty(  );  
    //获得最大的数据，但不删除  
    T fetchMax(  );  
    //删除最大的数据也就是数组的第一个数据项  
    void deleteMax(  );  
    //显示堆的内容   
    void display(  );  
    //把一个类型T的数组转化成一个堆  
    void array_heapSort(T* array ,int size);  
    //对堆进行堆排序  
    //precondition:堆已经存在  
    void heapSort(  );  
      
        
      
private:  
    //下调，把[star,end]区间的二叉树进行堆化  
    void locate_down(int start,int end );  
    //上调，把[star,end]区间的二叉树进行堆化  
    void locate_up(int start,int end ) ;  
      
private:  
    T* m_array;      //指向一个数组的指针  
    int m_size;       //已经存放了数据的个数  
    int m_lenght;    //分配的空间的长度  
      
};  
#include "heap.cpp"  
#endif  