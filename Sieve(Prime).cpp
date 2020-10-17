// O(N*log(log(N)))

void Sieve (int n)
{
    prime[0] = prime[1] = 1;
    for (int i = 4; i <= n; i += 2) prime[i] = 1;
    int limit = sqrt(n + 1);
    for (int i = 3; i <= limit; i += 2) {
        if (prime[i] == 0) {
            for (int j = i * i; j <= n; j += i) prime[j] = 1;
        }
    }
}
