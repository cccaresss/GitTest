    /*heap.cpp*/  
    template<typename T>  
    Heap<T>::Heap( int length )  
        {  
            m_array=new T[ length+1] ;  
            m_size=0;  
            m_lenght=length;  
        }  
    template<typename T>  
    T Heap<T>::fetchMax(  )  
        {  
            return m_array[ 1 ];  
        }  
      
    template<typename T>  
    bool Heap<T>::empty(  )  
        {  
            return m_size==0;  
        }  
    template<typename T>  
    void Heap<T>::locate_down(int start,int end )   
        {  
            int c=start*2;  
            int temp;  
            while( c<=end )  
                {  
                    if( c<end && m_array[ c ]<m_array[ c+1 ] )  
                        c=c+1;  
                    if( m_array[ start ]<m_array[ c ] )  
                        {  
                            temp=m_array[ start ];  
                            m_array[start]=m_array[ c ];  
                            m_array[ c ]=temp;  
                        }  
                       start=c;  
                       c=2*c;  
                }  
        }  
    template<typename T>  
    void Heap<T>::deleteMax(  )  
        {  
            m_array[ 1 ]=m_array[m_size];   //尾覆盖首  
            --m_size;                                        //长度减一  
            locate_down(1,m_size);                 //下调，保证堆结构  
        }  
    template<typename T>  
    void Heap<T>::locate_up(int start ,int end )  
        {  
            int loc=end;  
            int parent=end/2;  
            int temp;  
            while( parent>=start && m_array[ loc ] >m_array[ parent ])  
                {  
                    temp=m_array[ loc ];  
                    m_array[ loc ]=m_array[ parent ];  
                    m_array[ parent ]=temp;  
                    loc=parent;  
                    parent=loc/2;    
                }  
        }  
    template<typename T>  
    bool Heap<T>::insert(T item)  
        {  
            if( m_size>m_lenght )      //判断是否已满  
           {  
               std::cerr<<"the heap has FULL/n";  
              this->~Heap(  );  
               return 0;  
           }    
            ++m_size;                      //从m_array[ 1 ]开始放数据,所以先进行++m_size  
            m_array[ m_size ]=item;  
              
            locate_up(1,m_size);                 //上调保证堆结构  
            return 1;  
              
        }  
    template<typename T>  
    void Heap<T>::display( )  
        {  
            int i=1;  
            while( i<=m_size)  
           {  
               std::cout<<m_array[ i ]<<"  ";  
               ++i;  
           }  
            std::cout<<std::endl;  
        }  
    template<typename T>  
    void Heap<T>::array_heapSort(T* array ,int size)   //array[  ]从array[ 0 ]开始存放数据  
        {  
            int i;  
            m_lenght=size;  
            m_array=new T [ m_lenght+1 ];  
            for( i=1;i<=size;++i )  
                this->insert( array[ i-1 ]);  
            this->heapSort(  );  
            //write to the original array  
            for( i=1;i<=m_size;++i )  
              array[ i-1 ]=m_array[ i ];  
        }  
    template<typename T>  
    void Heap<T>::heapSort(  )  
        {  
            int i,temp;  
            for( i=m_size;i>=2;--i )  
                {  
                    temp=m_array[ 1 ];  
                    m_array[ 1 ]=m_array[ i ];  
                    m_array[ i ]=temp;  
                     
                    locate_down( 1,i-1 );    //locate_down() 会把1~i-1里面的数据排成堆  
                      
                }  
        }  