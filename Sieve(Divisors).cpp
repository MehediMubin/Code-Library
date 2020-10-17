// O(N * ln(N))

vector <int> divisor[MAX + 5];
int divCnt[MAX + 5], SOD[MAX + 5]; // SOD = Sum of Divisors

void SieveDiv (int n) 
{
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisor[j].pb(i); //list of Divisors
            divCnt[j]++; // Number of Divisors
            SOD[j] += i; // Sum of Divisors
        }
    }
}
