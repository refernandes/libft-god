from pathlib import Path


OUTDIR = Path('tests/Part2_functions/ft_strmapi')
OUTDIR.mkdir(parents=True, exist_ok=True)


def mapi(i, c):
    if 'a' <= c <= 'z':
        return chr(ord(c) - 32)
    elif 'A' <= c <= 'Z':
        return chr(ord(c) + 32)
    return c


def py_strmapi(s):
    return ''.join(mapi(i, c) for i, c in enumerate(s))


def run_case(arg):
    if arg == 1:
        s = 'LoReM iPsUm'
        out = py_strmapi(s)
    elif arg == 2:
        s = ''
        out = py_strmapi(s)
    elif arg == 3:
        s = 'a'
        out = py_strmapi(s)
    elif arg == 4:
        s = 'Z'
        out = py_strmapi(s)
    elif arg == 5:
        s = '1234!?$'
        out = py_strmapi(s)
    elif arg == 6:
        s = 'Ab1'
        out = py_strmapi(s)
    elif arg == 7:
        s = 'abcdefghijklmnopqrstuvwxyz'
        out = py_strmapi(s)
    elif arg == 8:
        s = 'ABCDEFGHIJ'
        out = py_strmapi(s)
    elif arg == 9:
        s = '   '
        out = py_strmapi(s)
    elif arg == 10:
        s = 'aBcDeFgHiJ'
        out = py_strmapi(s)
    elif arg == 11:
        s = '0123456789'
        out = py_strmapi(s)
    elif arg == 12:
        s = 'a'
        out = py_strmapi(s)
    elif arg == 13:
        s = 'A'
        out = py_strmapi(s)
    elif arg == 14:
        s = '---'
        out = py_strmapi(s)
    elif arg == 15:
        s = 'Hello World!'
        out = py_strmapi(s)
    else:
        raise ValueError(f'unknown test {arg}')
    return out.encode('utf-8')


def main():
    for i in range(1, 16):
        out = run_case(i)
        path = OUTDIR / f'test{i:02d}.output'
        with open(path, 'wb') as f:
            f.write(out)


if __name__ == '__main__':
    main()