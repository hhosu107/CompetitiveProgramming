# Ignore newline ('\n') while using getline right after cin >> x where x is not a string

Right after `cin >> x;`, use

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```
