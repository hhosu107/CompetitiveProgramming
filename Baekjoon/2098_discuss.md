두 가지 memoization 방법이 있다.
하나는: `dp[city][visited]`에 남은 unvisited cities를 거쳐 starting city까지
가는 최소 거리를 저장하는 것이고,
다른 하나는: `dp[city][visited]`에 현재까지 온 거리의 최소값을 저장하는 것이다.
첫 번째 방법은 smaller problem을 먼저 풀기 때문에 fast return이 가능하고,
두 번째 방법은 larger problem을 먼저 풀기 때문에 fast return이 불가능하다.
그 차이인가?
