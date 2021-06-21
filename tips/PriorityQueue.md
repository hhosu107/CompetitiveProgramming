# Priority Queue

## in C++

`priority_queue<T, vector<T>, comparator<T>>`

## How to generate pq for custom type?

For struct, write this:
```cpp
struct a{
    int start;
    int end;
    int value;
};

bool operator<(a t, a u){
    return t.value < u.value;
}
```

When the operator is implemented that the left is smaller than the right,
then the pq pops the largest element.
To pop the smallest element first, make the right one is smaller.

# Reference
[Priority Queue](https://koosaga.com/9)
