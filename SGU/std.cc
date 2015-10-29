#include <cstdio>
#include <stack>
#include <cctype>

using namespace std;

int main() {
    char ch;
    stack<char> sym;
    while ((ch = getchar()) != EOF) {
        while ((ch = getchar()) != '$') {
            if (ch == ' ') {
                continue;
            }
            if (isalpha(ch)) {
                if (sym.empty() || sym.top() == '{') {
                    printf ("<i>%c", ch);
                    sym.push('c');
                } else if (sym.top() == '^' || sym.top() == '_'){
                    printf ("<i>%c</i>%s", ch, (sym.top() == '^') ? "</sup>" : "</sub>");
                    sym.pop();
                } else {
                    putchar(ch);
                }
            } else {
                if (!sym.empty() && sym.top() == 'c') {
                    printf ("</i>");
                    sym.pop();
                }
                if (ch == '^' || ch == '_') {
                    sym.push(ch);
                    printf ("%s", ch == '^' ? "<sup>" : "<sub>");
                } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                    printf ("&nbsp;%c&nbsp;", ch);
                } else if (ch == '{') {
                    sym.push('{');
                } else if (ch == '}') {
                    sym.pop();
                    printf ("%s", sym.top() == '^' ? "</sup>" : "</sub>");
                    sym.pop();
                } else if (isdigit(ch)) {
                    putchar(ch);
                    if (!sym.empty() && (sym.top() == '^' || sym.top() == '_')) {
                        printf ("%s", (sym.top() == '^') ? "</sup>" : "</sub>");
                        sym.pop();
                    }
                } else {
                    putchar(ch);
                }
            }
        }
        if (!sym.empty()) {
            printf ("</i>");
            sym.pop();
        }
        putchar('\n');
        getchar();
    }
    return 0;
}
