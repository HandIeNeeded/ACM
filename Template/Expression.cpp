const int N = 1e5 + 5;
char s[N];
struct Exp{
    bool error;
    int tot, top, num[N];
    char op[N];

    void init() {
        error = false;
        tot = 0, top = 1;
        op[1] = '(';
    }

    bool priority(char a, char b) {
        if (b == '+' || b == '-') {
            return a != '(';
        }
        return a == '*' || a == '/';
    }

    int calc(char c, int a, int b) {
        if (c == '+') return a + b;
        if (c == '-') return a - b;
        if (c == '*') return a * b;
        if (c == '/' && b != 0) return a / b;
        error = 1;
        return 0;
    }

    int solve(char *s, int len) {//len = strlen(s)
        s[len++] = ')';
        REP(i, len) {
            if (s[i] == '(') op[++top] = s[i];
            else if (s[i] == ')') {
                while (top > 0 && op[top] != '(') {
                    num[tot - 1] = calc(op[top], num[tot - 1], num[tot]);
                    tot--, top--;
                }
                top--;
            }
            else if (s[i] == '-' && (i == 0 || s[i - 1] == '(')) { //处理负号
                num[++tot] = 0;
                op[++top] = '-';
            }
            else if (isdigit(s[i])) {
                int t = s[i] - '0';
                for (i++; isdigit(s[i]); i++) {
                    t = t * 10 + s[i] - '0';
                }
                num[++tot] = t;
                i--;
            }
            else {
                while (top > 0 && priority(op[top], s[i])) {
                    num[tot - 1] = calc(op[top], num[tot - 1], num[tot]);
                    tot--, top--;
                }
                op[++top] = s[i];
            }
        }
        return num[1];
    }
}expre;
