## This one replaces common 0-1 BFS code.

Prepare QX, QY. Suppose current node is u, and it reduces the distance to v
using (u, v). binary dijkstra does:
- if weight == X, put v in QX
- o.w., put v in QY.
Since putting v in queue requires O(1) time and update also requires O(1) time,
whole time complexity is O(V + E).

### Why QX and QY is always sorted according to the distance?

Use contradiction.
Suppose minimal distance change has been made on QX.
Let QX[-1] = v, QX[-2] = u.
Show that dist(QX[-2]) > dist(QX[-1]) is lie.

Suppose dist(u) > dist(v).
Since both node used 'X' weighted edge, pre(u) > pre(v).
both pre(u) and pre(v) are from QX or QY.
Since QX and QY were sorted, pre(u) and pre(v) cannot come from the same queue.
Thus u and v are located in the different queue.
Here, since u came first and v came second, pre(v) >= pre(u), but it contradicts
with our assumption (pre(u) > pre(v)).
Thus QX is sorted, and QY is also sorted vice versa.

## Pseudo Code
```

queue QX, QY  
push start S to QX
while one of the two queues is not empty:  
  u = pop minimal distant node among the two queue heads  

  for all edges e of form(u, v) :  
    if dist(v) > dist(u) + cost(e) :
      dist(v) = dist(u) + cost(e);
      if cost(e) == X :
        QX.push(dist(v), v);
      else :
        QY.push(dist(v), v);
```

## Reference
[Link](https://justicehui.github.io/2018/08/30/DijkstraOpt/)
