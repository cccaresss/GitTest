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
            cout<<"�����Ķ�Ϊ��/n";  
            one.display(  );  
            cout<<"���ж������Ժ�Ϊ��/n";  
            one.heapSort(  );  
            one.display(  );  
            cout<<"�����Ƕ�һ��������ж�����/n";  
            int a[  ]={7,9,8,6,10,11};  
            cout<<"�����������Ϊ:/n";  
            for(i=0;i<6;++i )  
                cout<<a[ i ]<<" ";  
            cout<<endl;  
            cout<<"���ж������Ժ�Ϊ:/n";  
            Heap<int> two;  
            two.array_heapSort(a,6 );  
             for(i=0;i<6;++i )  
                cout<<a[ i ]<<" ";  
             cout<<endl;  
               
           return 0;  
              
        }  