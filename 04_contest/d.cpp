// Foram utilizados os códigos do slide da disciplina para resolver o problema

#include <bits/stdc++.h>

using namespace std;

#define MAXDIGITS 100 /* maximum length bignum */
#define PLUS 1 /* positive sign bit */
#define MINUS -1 /* negative sign bit */

typedef long long ll;
typedef struct {
    char digits[MAXDIGITS]; /* represent the number */
    int signbit; /* 1 if positive, -1 if negative */
    int lastdigit; /* index of high-order digit */
} bignum;

void add_bignum(bignum *a, bignum *b, bignum *c);

void ll_to_bignum(ll s, bignum *n) {
    int i; /* counter */
    ll t; /* auxiliary */
    if (s >= 0) n->signbit = PLUS;
    else n->signbit = MINUS;

    for (i = 0; i < MAXDIGITS; i++) n->digits[i] = (char) 0;
    n->lastdigit = -1;

    // absolute value
    t = (s >= 0) ? s : -s;
    while (t > 0) {
        n->lastdigit++;
        n->digits[n->lastdigit] = (char) (t % 10);
        t = t / 10;
    }

    if (s == 0) n->lastdigit = 0;
}

void zero_justify(bignum *n) {
    while ((n->lastdigit > 0) && (n->digits[n->lastdigit] == 0))
        n->lastdigit--;

    if ((n->lastdigit == 0) && (n->digits[0] == 0))
        n->signbit = PLUS; /* hack to avoid -0 */
}

void digit_shift(bignum *n, int d) { /* multiply n by 10^d */
    int i; /* counter */

    if ((n->lastdigit == 0) && (n->digits[0] == 0)) return;

    for (i = n->lastdigit; i >= 0; i--)
        n->digits[i + d] = n->digits[i];

    for (i = 0; i < d; i++) n->digits[i] = 0;

    n->lastdigit = n->lastdigit + d;
}

int compare_bignum(bignum *a, bignum *b) {
    int i; /* counter */

    if ((a->signbit == MINUS) && (b->signbit == PLUS)) return (PLUS);
    if ((a->signbit == PLUS) && (b->signbit == MINUS)) return (MINUS);

    if (a->lastdigit > b->lastdigit) return (MINUS * a->signbit);
    if (b->lastdigit > a->lastdigit) return (PLUS * a->signbit);

    for (i = a->lastdigit; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) return (MINUS * a->signbit);
        if (b->digits[i] > a->digits[i]) return (PLUS * a->signbit);
    }

    return 0;
}

void initialize_bignum(bignum *c){
    c = new bignum();
    }

void subtract_bignum(bignum *a, bignum *b, bignum *c) {
    int borrow; /* has anything been borrowed? */
    int v; /* placeholder digit */
    int i; /* counter */

    initialize_bignum(c);

    // if a number is negative, invert its sign and sum.
    if ((a->signbit == MINUS) || (b->signbit == MINUS)) {
        b->signbit = -1 * b->signbit;
        add_bignum(a, b, c);
        b->signbit = -1 * b->signbit;
        return;
    }

    // place as first bignum the largest one (in magnitude)
    if (compare_bignum(a, b) == PLUS) {
        subtract_bignum(b, a, c);
        c->signbit = MINUS;
        return;
    }

    c->lastdigit = std::max(a->lastdigit, b->lastdigit);
    borrow = 0;

    // subtract the number implementing the borrowing system.
    for (i = 0; i <= (c->lastdigit); i++) {
        v = (a->digits[i] - borrow - b->digits[i]);
        if (a->digits[i] > 0) borrow = 0;
        if (v < 0) {
            v = v + 10;
            borrow = 1;
        }
        c->digits[i] = (char) v;
    }
    zero_justify(c);
}

void add_bignum(bignum *a, bignum *b, bignum *c) {
    int i, carry; /* carry digit */
    initialize_bignum(c);

    if (a->signbit == b->signbit) c->signbit = a->signbit;
    else {
        if (a->signbit == MINUS) {
            a->signbit = PLUS;
            subtract_bignum(b, a, c);
            a->signbit = MINUS;
        } else {
            b->signbit = PLUS;
            subtract_bignum(a, b, c);
            b->signbit = MINUS;
        }
        return;
    }

    c->lastdigit = std::max(a->lastdigit, b->lastdigit) + 1;
    carry = 0;

    for (i = 0; i <= (c->lastdigit); i++) {
        c->digits[i] = (char) (carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }
    zero_justify(c);
}


void multiply_bignum(bignum *a, bignum *b, bignum *c) {
    bignum row; /* represents shifted row */
    bignum tmp; /* placeholder bignum */
    int i, j; /* counters */

    initialize_bignum(c);

    row = *a;

    for (i = 0; i <= b->lastdigit; i++) {
        for (j = 1; j <= b->digits[i]; j++) {
            add_bignum(c, &row, &tmp);
            *c = tmp;
        }
        digit_shift(&row, 1);
    }

    c->signbit = a->signbit * b->signbit;
    zero_justify(c);
}

void divide_bignum(bignum *a, bignum *b, bignum *c) {
    bignum row; /* represents shifted row */
    bignum tmp; /* placeholder bignum */
    int asign, bsign; /* temporary signs */
    int i, j; /* counters */

    initialize_bignum(c);
    initialize_bignum(&row);
    initialize_bignum(&tmp);

    c->lastdigit = a->lastdigit;
    c->signbit = a->signbit * b->signbit;
    asign = a->signbit; a->signbit = PLUS;
    bsign = b->signbit; b->signbit = PLUS;

    for (i = a->lastdigit; i >= 0; i--) {
        digit_shift(&row, 1);
        row.digits[0] = a->digits[i];
        c->digits[i] = 0;
        while (compare_bignum(&row, b) != PLUS) {
            c->digits[i]++;
            subtract_bignum(&row, b, &tmp);
            row = tmp;
        }
    }
    zero_justify(c);
    a->signbit = asign;
    b->signbit = bsign;
}

void string_to_bignum(string s, bignum *a){
    int tam = s.length();
    int index_Str = tam - 1;
    for(int i = 0; i < tam; i++){
        a->digits[i] = (char) s[index_Str];
        index_Str --;
    }
    a->lastdigit = tam;
    a->signbit = PLUS;
}

void print_bignum(bignum *a){
    for(int i = 0 ; i < a->lastdigit; i++){
        cout << a->digits[i];
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;

    while(q--){
        bignum *a = new bignum();
        bignum *b = new bignum();
        bignum *c;
        bignum *d;

        string p;
        long long n;

        cin >> n;
        cin >> p;

        ll_to_bignum(n, b);
        string_to_bignum(p, a);

        divide_bignum(a, b, c);
        cout << "2nd\n";
        multiply_bignum(b, c, d); // d é o produto de a e c
        subtract_bignum(d, a, b); // b tem o resto

        print_bignum(b);

    }

}