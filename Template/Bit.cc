//找第k个空的位置 先全赋值1 然后每次加一个, update -1
int find(int k) {
    int ans = 0;
    for (int i = LOG; i >= 0; i--) {
        ans += 1 << i;
        if (ans > n || k <= s[ans]) ans -= 1 << i;
        else k -= s[ans];
    }
    return ans + 1;
}
