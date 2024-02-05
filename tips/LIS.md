이분 탐색으로 LIS를 nlgn에 구할 수 있다.
어떻게?

sol) 처음에 -inf만 들어있는 벡터를 생성한다.
그 다음 매번 수열을 볼 때 마다 이분 탐색으로 해당 수열의 값이 들어갈 위치를 찾아서 넣는다. 이거는
lower_bound 로 찾기 때문에 logn이다.
(현재의 수열보다 크다면 맨 뒤에 붙이고 벡터 크기를 1 늘린다.)

lower_bound method는 iterable에 대해 동작하며, `#include<algorithm>` 으로 가져올 수 있다.
