# Binary search trick

When you try to find this: maximum value of minimum values: use binary search.

ex) Make a predicate s.t. (`metric < border_value` ? restriction++ : get_next_metric), where border_value is set by binary search from [1, MAX]
