
// Imprime un __int128 (con signo)
void print128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

// Lee un __int128 desde cin (maneja signo)
__int128 read128() {
    string s;
    cin >> s;
    __int128 res = 0;
    int i = 0;
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }
    for (; i < (int)s.size(); i++) {
        res = res * 10 + (s[i] - '0');
    }
    if (neg) res = -res;
    return res;
}

// Multiplicación modular segura usando __int128
__int128 mulmod128(__int128 a, __int128 b, __int128 mod) {
    __int128 res = (a * b) % mod;
    if (res < 0) res += mod;
    return res;
}

// Potenciación modular: (base^exp) % mod
__int128 binpow128(__int128 base, __int128 exp, __int128 mod) {
    __int128 res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = mulmod128(res, base, mod);
        base = mulmod128(base, base, mod);
        exp >>= 1;
    }
    return res;
}

// Suma modular segura
__int128 addmod128(__int128 a, __int128 b, __int128 mod) {
    __int128 res = (a + b) % mod;
    if (res < 0) res += mod;
    return res;
}
