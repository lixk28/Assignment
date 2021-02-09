class array {
  typedef int* pointer;
  typedef unsigned int size_t;
  typedef int data_type;
 
  pointer _data;  // int *_data
  size_t _size;   // unsigned int _isze
 
 public:
  // constructor
  array(size_t size);
  // destructor
  ~array();
  // Capacity
  // Return maximum size
  size_t max_size(void);
 
  // Element access
  // Access element
  // int& operator[](const int &i) {return data[i];}
  // Access element
  data_type& at(const data_type& i);
  // Access first element
  data_type& front();
  // Access last element
  data_type& back();
  // Get pointer to data
  pointer data();
 
  // Modifiers
  // Fill array with the same value
  void fill(const data_type& value);
  // Resize the array (newSize > oldSize)
  void resize(int newSize);
  // Sort the array in the section [from, to)
  void sort(int from, int to);
};

array::array(size_t size)
{
    _data = new data_type[size];
    _size = size;
}

array::~array()
{
    delete[] _data;
}

array::size_t array::max_size(void)
{
    return _size;
}

array::pointer array::data()
{
    return _data;
}

array::data_type& array::front()
{
    return _data[0];
}

array::data_type& array::back()
{
    return _data[_size - 1];
}

array::data_type& array::at(const data_type& i)
{
    return _data[i];
}

void array::fill(const data_type& value)
{
    for(int i = 0; i < _size; i++)
        _data[i] = value;
}

void array::resize(int newSize)
{
    int a[_size];
    for(int i = 0; i < _size; i++)
        a[i] = _data[i];
    delete[] _data;
    _size = newSize;
    _data = new data_type[newSize];
    for(int i = 0; i < _size; i++)
        _data[i] = a[i];
}

void array::sort(int from, int to)
{
    pointer p = data();
    for(int i = from; i < to - 1; i++)
    {
        for(int j = i + 1; j < to; j++)
        {
            if(p[j] < p[i])
            {
                data_type temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
            else 
                continue;
        }
    }
}




