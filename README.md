# ft_containers
42 project to understand how vector, stack and map work under the hood in C++  
## Getting started
### Template prototype
```
template<
    class T,
    class Allocator = std::allocator<T>
> class vector;

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > # DO NOT omit the const keyword
> class map;

template<
    class T,
    class Container = ft::vector<T> # according to subject, default container is ft::vector
> class stack;

```
### Member types
Example for vector  
How member types are written in the MAN  
```
value_type 	        T
allocator_type 	    Allocator
iterator	        a random access iterator to value_type	convertible to const_iterator
const_iterator	    a random access iterator to const value_type
size_type 	        Unsigned integer type (usually std::size_t) 
```
How member types are re-written the code  
```
typedef	T							value_type;
typedef Alloc						allocator_type;
typedef ft::iterator< T >			iterator;
typedef ft::iterator< const T >		const_iterator;
typedef size_t						size_type;
```
Extra: to check, difference between typedef and typename  

### Member functions
How member functions are written in the MAN  
```
size_type size() const; # https://cplusplus.com/reference/vector/vector/size/
```
How member functions are re-written the code  
```
size_type				size() const					{		return _size; 	    };
```
### Non-Member Functions
Writing non-member functions _inside_ the template class
```
```
Writing non-member functions _outside_ the template class
