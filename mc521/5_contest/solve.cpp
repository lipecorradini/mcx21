#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Point 
{ 
    public:
    int p, q, r, s, t, u; 
}; 

double EPS = 1e-4;

void read_conj(Point *conj, int p, int q, int r, 
int s, int t, int u){
    conj->p = p;
    conj->q = q;
    conj->r = r;
    conj->s = s;
    conj->t = t;
    conj->u = u;
}

double solve_eq(Point *conj, double x){
    double ans = conj->p * exp(-x) + conj->q * sin(x) +
         conj->r * cos(x) + conj->s * tan(x) + 
         conj->t * x * x + conj->u;
    return ans;
}


double bisseccao(double x1, double x2, Point *conj) {

    double v1 = solve_eq(conj, x1);
    double v2 = solve_eq(conj, x2);
    double valor = v1 - v2;
    if (fabs(valor) < EPS)
        return (x1 + x2) / 2;
    else if (valor > 0.0)
        return bisseccao(x1, (x1 + x2) / 2, conj);
    return bisseccao((x1 + x2) / 2, x2, conj);
}


int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
    
    unique_ptr<Point> conj(new Point());
    int p, q, r, s, t, u;

    while (cin >> p >> q >> r >> s >> t >> u) {
        
        cout << "aq\n";
        read_conj(conj.get(), p, q, r, s, t, u);
        double max_x = 1.000;
        double min_x = 0.000;
        double x = bisseccao(min_x, max_x, conj.get());
        cout << x << '\n';


    }


}
