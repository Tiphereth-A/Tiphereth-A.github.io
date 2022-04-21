---
title: 「线段树的扩展之浅谈zkw线段树」一文的测试代码、数据、详细测试结果与生成器
tags:
  - 程序设计
  - 洛谷日报
  - 测试
date: 2018-08-08 13:05:56
comments: false
---

## 测试代码

<!--more-->

> 注意: 因为笔者脑抽并没有调用 fread

### 递归线段树

```cpp
#include<cstdio>
#include<fstream>
#include<sys/time.h>
#include<string>
#include<sstream>

#define fp(i,l,r) for(register uint64_t i=(l);i<=(r);++i)
#define fr(a) freopen((a),"r",stdin)
#define fw(a) freopen((a),"w",stdout)
#define fc fclose(stdin),fclose(stdout)
#define il inline
#define ls rt<<1
#define rs rt<<1|1
#define Mid uint64_t m=((r-l)>>1)+l
#define tpn typename
#define MAXN 10000005
#define MAXBUF 140000000

using i64 = int64_t;
using u64 = uint64_t;

il char gc() {
    static char buf[MAXBUF],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXBUF,stdin),p1==p2)?EOF:*p1++;
}
template <tpn A> il void read(A &x){
    char c;
    do{
        c=getchar();
    }while (c<'0'||c>'9');
    x=0;
    do{
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    } while (c>='0'&&c<='9');
}
template <tpn A,tpn B> il void read(A &a,B &b){
read(a),read(b);}
template <tpn A,tpn B,tpn C> il void read(A &a,B &b,C &c){
read(a),read(b),read(c);}

u64 sum[MAXN << 2], add[MAXN << 2], a[MAXN];
const std::string str1("data"),str3(".in"),str4(".out");
std::stringstream tmp;
std::string str2;
std::ofstream fout("test1.txt");
struct timeval start,end;

il void PushUp(const u64 &rt) {
    sum[rt] = sum[ls] + sum[rs];
}
il void PushDown(const u64 &rt, const u64 &ln, const u64 &rn) {
    add[ls] += add[rt];
    sum[ls] += add[rt] * ln;
    add[rs] += add[rt];
    sum[rs] += add[rt] * rn;
    add[rt] = 0;
}
void Build(const u64 &l, const u64 &r, const u64 &rt) {
    if (l == r) {
        sum[rt] = a[l];
        return;
    }
    Mid;
    Build(l, m, ls);
    Build(m+1, r, rs);
    PushUp(rt);
}
void Update(const u64 &L, const u64 &R, const u64 &c, const u64 &l, const u64 &r, const u64 &rt) {
    if (L <= l && r <= R) {
        sum[rt] += c * (r - l + 1);
        add[rt] += c;
        return;
    }
    Mid;
    PushDown(rt, m-l+1, r-m);
    if (L <= m)
        Update(L, R, c, l, m, ls);
    if (R > m)
        Update(L, R, c, m+1, r, rs);
    PushUp(rt);
}
u64 Query(const u64 &L, const u64 &R, const u64 &l, const u64 &r, const u64 &rt) {
    u64 ans = 0;
    if (L <= l && r <= R)
        return sum[rt];
    Mid;
    PushDown(rt, m-l+1, r-m);
    if (L <= m)
        ans += Query(L, R, l, m, ls);
    if (R > m)
        ans += Query(L, R, m+1, r, rs);
    return ans;
}
int main() {
    fp(j,1,16) {
        tmp.clear();
        tmp << j;
        tmp >> str2;
        std::string file(str1+str2+str3);
        fr(file.c_str());
        file=str1+str2+str4;
        fw(file.c_str());
        gettimeofday(&start, NULL);
        u64 n=0, m=0;
        read(n, m);
        fp(i, 1, n) read(a[i]);
        Build(1, n, 1);
        u64 o=0, x=0, y=0, k=0;
        while (m--) {
            read(o,x,y);
            if (o&1) {
                read(k);
                Update(x, y, k, 1, n, 1);
            } else printf("%llu\n", Query(x, y, 1, n, 1));
        }
        gettimeofday(&end, NULL);
        fout << "data#" << j << ":" << std::endl;
        fout << "\tstart:" <<  start.tv_sec << "." << start.tv_usec << std::endl;
        fout << "\tend:" << end.tv_sec << "." << end.tv_usec << std::endl;
        fc;
    }
    fout.close();
    return 0;
}
```

### zkw 线段树

```cpp
#include<cstdio>
#include<fstream>
#include<sys/time.h>
#include<string>
#include<sstream>

#define fp(i,l,r) for(register uint64_t (i)=(l);(i)<=(r);(i)++)
#define fd(i,l,r) for(register uint64_t i=l;i>=r;--i)
#define fr(a) freopen((a),"r",stdin)
#define fw(a) freopen((a),"w",stdout)
#define fc fclose(stdin),fclose(stdout)
#define il inline
#define tpn typename
#define MAXN 10000005
#define MAXBUF 140000000

using u64 = uint64_t;

il char gc() {
    static char buf[MAXBUF],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXBUF,stdin),p1==p2)?EOF:*p1++;
}
template <tpn A> il void read(A &x){
    char c;
    do{
        c=getchar();
    }while (c<'0'||c>'9');
    x=0;
    do{
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    } while (c>='0'&&c<='9');
}
template <tpn A,tpn B> il void read(A &a,B &b){
read(a),read(b);}
template <tpn A,tpn B,tpn C> il void read(A &a,B &b,C &c){
read(a),read(b),read(c);}

u64 tree[MAXN<<2],add[MAXN<<2];
u64 n,N=1,m;
const std::string str1("data"),str3(".in"),str4(".out");
std::stringstream tmp;
std::string str2;
std::ofstream fout("test2.txt");
struct timeval start,end;

il void build() {
  read(n, m);
  for(; N <= n+1; N <<= 1);
  fp(i, N+1, N+n) read(tree[i]);
  fd(i, N-1, 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
il void update(u64 &s,u64 &t,u64 &k) {
    u64 lNum=0,rNum=0,nNum=1;
    for(s=N+s-1,t=N+t+1;s^t^1;s>>=1,t>>=1,nNum<<=1) {
        tree[s]+=k*lNum;
        tree[t]+=k*rNum;
        if(~s&1) {add[s^1]+=k; tree[s^1]+=k*nNum; lNum+=nNum;}
        if( t&1) {add[t^1]+=k; tree[t^1]+=k*nNum; rNum+=nNum;}
    }
    for(;s;s>>=1,t>>=1) {
        tree[s]+=k*lNum;
        tree[t]+=k*rNum;
    }
}
il u64 query(u64 &s,u64 &t){
    u64 lNum=0,rNum=0,nNum=1;
    u64 ans=0;
    for(s=N+s-1,t=N+t+1;s^t^1;s>>=1,t>>=1,nNum<<=1){
        if(add[s]) ans+=add[s]*lNum;
        if(add[t]) ans+=add[t]*rNum;
        if(~s&1) {ans+=tree[s^1]; lNum+=nNum;}
        if( t&1) {ans+=tree[t^1]; rNum+=nNum;}
    }
    for(;s;s>>=1,t>>=1){
        ans+=add[s]*lNum;
        ans+=add[t]*rNum;
    }
    return ans;
}
int main() {
    fp(j,1,16) {
        tmp.clear();
        tmp << j;
        tmp >> str2;
        std::string file(str1+str2+str3);
        fr(file.c_str());
        file=str1+str2+str4;
        fw(file.c_str());
        gettimeofday(&start, NULL);
        build();
        char c=0;
        u64 x=0,y=0,k=0;
        while(m--) {
            read(c, x, y);
            if(c&2) printf("%llu\n",query(x,y));
            else {
                u64 k;
                read(k);
                update(x,y,k);
            }
        }
        gettimeofday(&end, NULL);
        fout << "data#" << j << ":" << std::endl;
        fout << "\tstart:" <<  start.tv_sec << "." << start.tv_usec << std::endl;
        fout << "\tend:" << end.tv_sec << "." << end.tv_usec << std::endl;
        fc;
    }
    fout.close();
    return 0;
}
```

### 树状数组

```cpp
#include<cstdio>
#include<fstream>
#include<sys/time.h>
#include<string>
#include<sstream>

#define fp(i,l,r) for(register uint64_t i=(l);i<=(r);++i)
#define lowbit(x) ((x)&-(x))
#define fr(a) freopen((a),"r",stdin)
#define fw(a) freopen((a),"w",stdout)
#define fc fclose(stdin),fclose(stdout)
#define il inline
#define tpn typename
#define MAXN 10000005
#define MAXBUF 140000000

using u64 = uint64_t;

il char gc() {
    static char buf[MAXBUF],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXBUF,stdin),p1==p2)?EOF:*p1++;
}
template <tpn A> il void read(A &x){
    char c;
    do{
        c=getchar();
    }while (c<'0'||c>'9');
    x=0;
    do{
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    } while (c>='0'&&c<='9');
}
template <tpn A,tpn B> il void read(A &a,B &b){read(a);read(b);}
template <tpn A,tpn B,tpn C> il void read(A &a,B &b,C &c){read(a);read(b);read(c);}

u64 n, m, c1[MAXN], c2[MAXN], num[MAXN];
const std::string str1("data"),str3(".in"),str4(".out");
std::stringstream tmp;
std::string str2;
std::ofstream fout("test3.txt");
struct timeval start,end;

void il add(u64 *r, u64 pos, const u64 &v) {for(; pos <= n; pos += lowbit(pos)) r[pos] += v;}
u64 il query(u64 *r, u64 pos) {
 u64 ans(0);
 for(; pos; pos -= lowbit(pos)) ans += r[pos];
 return ans;
}
int main() {
 fp(j,1,16) {
        tmp.clear();
        tmp << j;
        tmp >> str2;
        std::string file(str1+str2+str3);
        fr(file.c_str());
        file=str1+str2+str4;
        fw(file.c_str());
        gettimeofday(&start, NULL);
  u64 op, x, y, k, sum1, sum2;
  read(n, m);
  fp(i, 1, n) {
   read(num[i]);
   add(c1, i, num[i]-num[i-1]);
   add(c2, i, (i-1)*(num[i]-num[i-1]));
  }
  while(m--) {
   read(op,x,y);
   if(op&1) {
    read(k);
    add(c1,x,k);add(c1,y+1,-k);
    add(c2,x,k*(x-1));add(c2,y+1,-k*y);
   } else {
    sum1=(x-1)*query(c1,x-1)-query(c2,x-1);
    sum2=y*query(c1,y)-query(c2,y);
    printf("%llu\n",sum2-sum1);
   }
  }
  gettimeofday(&end, NULL);
        fout << "data#" << j << ":" << std::endl;
        fout << "\tstart:" <<  start.tv_sec << "." << start.tv_usec << std::endl;
        fout << "\tend:" << end.tv_sec << "." << end.tv_usec << std::endl;
        fc;
    }
    fout.close();
 return 0;
}
```

## 详细评测结果#1（以秒为单位）

```text
test#1:
time#1 = 3.447280
time#2 = 3.696011
time#3 = 3.683904
time#4 = 3.648302
time#5 = 3.296298
time#6 = 7.708645
time#7 = 7.082259
time#8 = 7.126166
time#9 = 6.963065
time#10 = 7.756587
time#11 = 51.682691
time#12 = 48.633226
time#13 = 47.932671
time#14 = 105.835116
time#15 = 113.755264
time#16 = 158.988079
Ave:
3.554359
7.327344
49.416196
126.192820

test#2:
time#1 = 2.511897
time#2 = 1.695306
time#3 = 2.118245
time#4 = 2.079538
time#5 = 1.934902
time#6 = 4.719447
time#7 = 4.817881
time#8 = 4.623501
time#9 = 5.097146
time#10 = 5.355650
time#11 = 34.865590
time#12 = 34.907769
time#13 = 32.463151
time#14 = 74.738552
time#15 = 73.855234
time#16 = 74.000259
Ave:
2.067978
4.922725
34.078837
74.198015

test#3:
time#1 = 2.060278
time#2 = 1.992258
time#3 = 2.002796
time#4 = 1.820297
time#5 = 1.964742
time#6 = 4.490217
time#7 = 4.383801
time#8 = 4.159582
time#9 = 4.358566
time#10 = 4.404194
time#11 = 26.816804
time#12 = 26.666548
time#13 = 26.862968
time#14 = 57.438784
time#15 = 57.584326
time#16 = 57.433181
Ave:
1.968074
4.359272
26.782107
57.485430

```

## 详细评测结果#2（以秒为单位）

```text
test#1:
time#1 = 3.723513
time#2 = 4.895209
time#3 = 4.096053
time#4 = 3.921210
time#5 = 3.291190
time#6 = 6.779961
time#7 = 7.278650
time#8 = 7.048792
time#9 = 6.539919
time#10 = 7.330734
time#11 = 45.730535
time#12 = 45.291213
time#13 = 45.184196
time#14 = 99.981685
time#15 = 99.947381
time#16 = 99.487397
Ave:
3.985435
6.995611
45.401981
99.805488

test#2:
time#1 = 1.830346
time#2 = 2.099576
time#3 = 2.085104
time#4 = 2.171504
time#5 = 2.239576
time#6 = 4.618806
time#7 = 3.836848
time#8 = 4.119962
time#9 = 4.149363
time#10 = 4.619962
time#11 = 29.606656
time#12 = 29.431768
time#13 = 29.710447
time#14 = 67.893993
time#15 = 66.520776
time#16 = 68.217186
Ave:
2.085221
4.268988
29.582957
67.543985

test#3:
time#1 = 1.943302
time#2 = 2.128660
time#3 = 2.122796
time#4 = 1.828443
time#5 = 1.882570
time#6 = 3.893438
time#7 = 4.130842
time#8 = 3.821628
time#9 = 3.872965
time#10 = 4.239745
time#11 = 25.007103
time#12 = 25.088401
time#13 = 25.442503
time#14 = 54.489850
time#15 = 54.187768
time#16 = 54.235232
Ave:
1.981154
3.991724
25.179336
54.304283
```

[回到原文](..)
