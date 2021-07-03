Iterable data structures:

## map

- Defined in `#include<map>`
- Use with : `map<T1, T2>`; `T1` is key type, `T2` is value type
- Iterator of map instance: `map<T1, T2>::iterator it = map_instance.begin()`
- Iterating on map: `for(map<T1, T2>::iterator it = map_instance.begin(); it != map_instance.end(); it++)`
- Since iterator is a pointer to an element of a map,
  - Key of iterator: `it->first` (`(*it).first`)
  - value of iterator: `it->second`
- size: `<instance>.size()`
- find: `<instance>.find(key)`. It returns iterator of the type; to validate, use `it != <instance>.end()`

## unordered map

- Similar methods from map also works on map.