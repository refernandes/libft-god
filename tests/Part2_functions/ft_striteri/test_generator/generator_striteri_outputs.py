from pathlib import Path


OUTDIR = Path('tests/Part2_functions/ft_striteri')
OUTDIR.mkdir(parents=True, exist_ok=True)


def iter_func(i, c):
    if 'a' <= c <= 'z':
        return chr(ord(c) - 32)
    elif 'A' <= c <= 'Z':
        return chr(ord(c) + 32)
    return c


def py_striteri(s):
    chars = list(s)
    for i in range(len(chars)):
        chars[i] = iter_func(i, chars[i])
    return ''.join(chars)


def run_case(arg):
    if arg == 1:
        s = 'LoReM iPsUm'
    elif arg == 2:
        s = ''
    elif arg == 3:
        s = 'a'
    elif arg == 4:
        s = 'A'
    elif arg == 5:
        s = '1234!?$'
    elif arg == 6:
        s = 'abc'
    elif arg == 7:
        s = 'ABC'
    elif arg == 8:
        s = '   '
    elif arg == 9:
        s = 'aBcDeFgHiJ'
    elif arg == 10:
        s = '0123456789'
    elif arg == 11:
        s = 'abcdefghijklmnopqrstuvwxyz'
    elif arg == 12:
        s = 'ABCDEFGHIJ'
    else:
        raise ValueError(f'unknown test {arg}')
    return py_striteri(s).encode('utf-8')


def main():
    for i in range(1, 13):
        out = run_case(i)
        path = OUTDIR / f'test{i:02d}.output'
        with open(path, 'wb') as f:
            f.write(out)


if __name__ == '__main__':
    main()