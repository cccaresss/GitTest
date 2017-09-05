    /*test.cpp*/  
    #include "heap.h"  
    #include <iostream>  
    using std::cout;  
    using std::cin;  
    using std::endl;  
    int main(  )  
        {  
            int i;  
            Heap<int> one( 6 );  
            for( i=0;i<6;++i )  
                one.insert( i+1 );  
            cout<<"构建的堆为：/n";  
            one.display(  );  
            cout<<"进行堆排序以后为：/n";  
            one.heapSort(  );  
            one.display(  );  
            cout<<"下面是对一个数组进行堆排序：/n";  
            int a[  ]={7,9,8,6,10,11};  
            cout<<"待排序的数组为:/n";  
            for(i=0;i<6;++i )  
                cout<<a[ i ]<<" ";  
            cout<<endl;  
            cout<<"进行堆排序以后为:/n";  
            Heap<int> two;  
            two.array_heapSort(a,6 );  
             for(i=0;i<6;++i )  
                cout<<a[ i ]<<" ";  
             cout<<endl;  
               
           return 0;  
              
        }  