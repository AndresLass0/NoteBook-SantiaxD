

const ll MOD = 1000000000000000003LL;

// Suma modular: (a + b) % MOD
ll suma_mod(ll a, ll b, ll mod = MOD) {
    ll res = (a + b) % mod;
    if (res < 0) res += mod;
    return res;
}

// Resta modular: (a - b) % MOD
ll resta_mod(ll a, ll b, ll mod = MOD) {
    ll res = (a - b) % mod;
    if (res < 0) res += mod;
    return res;
}

// Multiplicación modular: (a * b) % MOD
ll mul_mod(ll a, ll b, ll mod = MOD) {
    __int128 res = (__int128)a * b % mod;
    if (res < 0) res += mod;
    return (ll)res;
}

// Potenciación modular: (base^exp) % MOD
ll binpow_mod(ll base, ll exp, ll mod = MOD) {
    ll res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = mul_mod(res, base, mod);
        base = mul_mod(base, base, mod);
        exp >>= 1;
    }
    return res;
}

// Extendido de Euclides para inverso modular
ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

// Calcula inverso modular de a mod m (si existe)
ll modinv(ll a, ll m = MOD) {
    ll x, y;
    ll g = egcd(a, m, x, y);
    if (g != 1) return -1; // No existe inverso
    x %= m;
    if (x < 0) x += m;
    return x;
}
