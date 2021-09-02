// O(N*log(log(N)))

bitset <N> prime;

void Sieve ()
{
    prime.set();
    for (int i = 4; i <= N; i += 2) prime[i] = 0;
    int limit = sqrt(N + 1);
    for (int i = 3; i <= limit; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) prime[j] = 0;
        }
    }
}
