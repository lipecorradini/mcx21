import math

class Point:
    def __init__(self):
        self.p = 0
        self.q = 0
        self.r = 0
        self.s = 0
        self.t = 0
        self.u = 0

EPS = 1e-4

def read_conj(conj, p, q, r, s, t, u):
    conj.p = p
    conj.q = q
    conj.r = r
    conj.s = s
    conj.t = t
    conj.u = u

def solve_eq(conj, x):
    ans = conj.p * math.exp(-x) + conj.q * math.sin(x) + \
          conj.r * math.cos(x) + conj.s * math.tan(x) + \
          conj.t * x * x + conj.u
    return ans

def bisseccao(x1, x2, conj):
    v1 = solve_eq(conj, x1)
    v2 = solve_eq(conj, x2)

    valor = (v1 - v2)//2
    x_med = (x1 + x2)//2
    v_med = solve_eq(conj, x_med)

    if abs(valor) < EPS:
        return (x1 + x2) / 2
    elif valor > 0.0:
        return bisseccao(x1, (x1 + x2) / 2, conj)
    return bisseccao((x1 + x2) / 2, x2, conj)

def main():
    conj = Point()
    while True:
        try:
            p, q, r, s, t, u = map(int, input().split())
            print("aq")
            read_conj(conj, p, q, r, s, t, u)
            max_x = 1.000
            min_x = 0.000
            x = bisseccao(min_x, max_x, conj)
            print(f"{x:.4f}")
        except EOFError:
            break

if __name__ == "__main__":
    main()
