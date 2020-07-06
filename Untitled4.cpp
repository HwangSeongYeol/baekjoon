#include<stdio.h>
typedef long long ll;
 
int n, m, a, b, c, parent[100001],cnt;
ll wei[100001];
char ch;
 
int find(int a) {
    if (a == parent[a])return a;
    int prev = find(parent[a]);
    wei[a] += wei[parent[a]];
    return parent[a] = prev;
}
 
int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)return 0;
        cnt++;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            wei[i] = 0;
        }
        while (m--) {
            scanf(" %c", &ch);
            if (ch == '!') {
                scanf("%d %d %d", &a, &b, &c);
                int l = find(a);
                int r = find(b);
                if (l != r) {
                    parent[l] = r;
                    wei[l] = wei[b] - wei[a] + c;
                }
            }
            else {
                scanf("%d %d", &a, &b);
                int l = find(a);
                int r = find(b);
                if (l != r) {
                    printf("UNKNOWN\n");
                    continue;
                }
                else printf("%lld\n", wei[a] - wei[b]);
            }
        }
    }
}

