priority_queue<int> q;

void go(int id) {
    cin >> s[id];
    int len = s[id].size();
    reverse(s[id].begin(), s[id].end());
    REP(i, len) {
        a[id][i] = s[id][i] - '0';
    }
    REP(i, len) if (a[id][i] && a[id][i + 1]) q.push(i);
    while (!q.empty()) {
        int k = q.top(); q.pop();
        if (a[id][k] == 0 || a[id][k + 1] == 0) {
            continue;
        }
        a[id][k] = a[id][k + 1] = 0;
        a[id][k + 2] = 1;
        if (a[id][k + 3]) q.push(k + 2);
    }
}
