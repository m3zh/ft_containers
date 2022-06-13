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
### Member functions
### Non-Member Functions
