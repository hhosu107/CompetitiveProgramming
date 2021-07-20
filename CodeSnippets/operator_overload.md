# Operator Overloading

Unary operators are overloaded in the struct/class as:

```cpp
<return_type> operator@() { blahblah }
```

which is implemented outside of the struct as:

```cpp
<return_type> U::operator@(U x) { blahblah }
```

Similar as binary operator; but here `const` takes place and we need to instantiate a new struct/class object to return:
```cpp
<return_type> operator@(const U &rhs) const {blahblah}
```

and

```cpp
<return_type> Type::operator@(U lhs, const U &rhs) const {blahblah}
```
