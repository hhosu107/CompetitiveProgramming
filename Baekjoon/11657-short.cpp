#include<cstdio>
int n, m, a[6000], b[6000], c[6000], t[501], last;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d%d%d", a + i, b + i, c + i);
    for (int i = 2; i <= n; i++) t[i] = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (t[a[j]]<1e9&&t[b[j]]>t[a[j]] + c[j]) {
            t[b[j]] = t[a[j]] + c[j];
            last = i;
        }
    }
    if (last == n - 1) puts("-1");
    else for (int i = 2; i <= n; i++) printf("%d\n", t[i] < 1e9 ? t[i] : -1);
    return 0;
}
