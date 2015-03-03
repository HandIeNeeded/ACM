__builtin_ffs(unsigned int x) //返回右起第一个‘1’的位置.x==0,返回0
__builtin_clz(unsigned int x) //返回左起第一个‘1’之前0的个数.x==0,返回unsigned int的位数
__builtin_ctz(unsigned int x) //返回右起第一个‘1’之后的0的个数.X==0,返回unsigned int的位数
__builtin_popcount(unsigned int x) //返回'1'的个数
__builtin_parity(unsigned int x) //返回'1'的个数的奇偶性

//所有函数后加一个l,就可以计算unsigned long类型,加ll,就可以计算long long类型.


