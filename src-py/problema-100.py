#!/usr/bin/env  python3
# *-* encoding=utf8 *-*

def main ():
    casos = int(input())
    for _ in range(casos):
        n = int(input())
        contador = 0 ;
        while contador <= 7 and n != 6174:
            n = list(str(n))
            n.sort()
            i = int("".join(n[::-1]))
            n = int("".join(n))
            n = max(i, n) - min(i, n)
            contador += 1
        print(contador)

if __name__ == "__main__":
    main()
