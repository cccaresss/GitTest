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
            m_array[ 1 ]=m_array[m_size];   //β������  
            --m_size;                                        //���ȼ�һ  
            locate_down(1,m_size);                 //�µ�����֤�ѽṹ  
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
            if( m_size>m_lenght )      //�ж��Ƿ�����  
           {  
               std::cerr<<"the heap has FULL/n";  
              this->~Heap(  );  
               return 0;  
           }    
            ++m_size;                      //��m_array[ 1 ]��ʼ������,�����Ƚ���++m_size  
            m_array[ m_size ]=item;  
              
            locate_up(1,m_size);                 //�ϵ���֤�ѽṹ  
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
    void Heap<T>::array_heapSort(T* array ,int size)   //array[  ]��array[ 0 ]��ʼ�������  
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
                     
                    locate_down( 1,i-1 );    //locate_down() ���1~i-1����������ųɶ�  
                      
                }  
        }  