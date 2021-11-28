# Various vector methods

- sort({begin}, {end}, {comparator}) : sorts
- vec.erase(iter): erase element at iter location.
- vec.erase(start, end): erase [start, end) elements.
- std::unique(iterable.begin(), iterable.end()): Eliminates all except the first
    element from every consecutive group of equivalent elements from the range
    [first, last), and returns a past-the-end iterator for the new logical end
    of the range.
    Here, logical means: after the logical end, values are not cleaned; they are
    indeterminate values.
    Thus, we have to perform vec.erase(unique(vec.begin(), vec.end()),
    vec.end()) to erase indeterminate values.
