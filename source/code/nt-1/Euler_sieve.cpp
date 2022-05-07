void Euler_sieve(int n) {
    for(int i = 2; i <= n; ++i) {
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1;j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = true;
            // 换言之, i 之前被 prime[j] 筛过了
            // 由于 prime 里面质数是从小到大的, 所以 i 乘上其他的质数的结果一定也
            // 是 prime[j] 的倍数 它们都被筛过了, 就不需要再筛了, 所以这里直接
            // break 掉就好了
            if(i % prime[j] == 0) break;
        }
    }
}
