Procedure dijkstra (G, l, s)
Input: Graph G = (V, E), directed or undirected; l: E -> R+ weight function; s: V source vertex
Output: for all vertices u reachable from s, dist(u) is set to the distance from s to u

for all u in V do
    dist(u) = infinity
    prev(u) = nil
dist(s) = 0

H = makequeue(V) // using dist-values as keys. Note that this queue is priority queue (min-heap)
while H is not empty do
    u = deletemin(H)
    for all edges (u, v) in E do
        if dist(v) > dist(u) + l(u, v) then
            dist(v) = dist(u) + l(u, v)
            prev(v) = u
            decreasekey(H, v)
```

```python
