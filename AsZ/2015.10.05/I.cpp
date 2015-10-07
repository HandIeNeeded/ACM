//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int mp[30][30][40];
vector<string> str;

int main()
{
#ifdef HOME
    freopen("I.in", "r", stdin);
#endif
    freopen("i18n.in", "r", stdin);
    freopen("i18n.out", "w", stdout);
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            string word = "";
            int num = 0;
            while (isalpha(ch) || isdigit(ch))
            {
                word = word + ch;
                if (isdigit(ch))
                    num = num * 10 + ch - '0';
                ch = getchar();
            }
            int fi = tolower(word[0]) - 'a';
            int la = tolower(word[word.size() - 1]) - 'a';
            if (num)
            {
                if (mp[fi][la][num] > 0)
                {
                    int k = mp[fi][la][num] - 1;
                    if (isupper(word[0]))
                    {
                        if (isupper(word[word.size() - 1]))
                        {
                            for (int i = 0; i < str[k].size(); i++)
                                cout << (char)toupper(str[k][i]);
                        } else
                        {
                            cout << (char)toupper(str[k][0]);
                            for (int i = 1; i < str[k].size(); i++)
                                cout << str[k][i];
                        }
                    } else
                        cout << str[k];
                } else
                    cout << word;
            } else
            {
                num = word.size() - 2;
                int k = mp[fi][la][num];
                if (!k)
                {
                    str.push_back(word);
                    mp[fi][la][num] = str.size();
                    k = str.size() - 1;
                    for (int i = 0; i < str[k].size(); i++)
                        str[k][i] = tolower(str[k][i]);
                } else
                {
                    k--;
                    if (k >= 0 && word.size() == str[k].size())
                    {
                        bool flag = true;
                        for (int i = 0; i < word.size(); i++)
                            if (tolower(word[i]) != str[k][i])
                                flag = false;
                        if (!flag)
                            mp[fi][la][num] = -1;
                    } else
                        mp[fi][la][num] = -1;
                }
                cout << word;
            }
        }
        cout << ch;
    }
    return 0;
}
