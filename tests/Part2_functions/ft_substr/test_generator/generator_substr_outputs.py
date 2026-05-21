from pathlib import Path

OUTDIR = Path('output/substr_expected')
OUTDIR.mkdir(parents=True, exist_ok=True)


def ft_substr_expected(s, start, length):
    if start >= len(s):
        return ''
    return s[start:start + length]


def run_case(arg):
    str_main = 'lorem ipsum dolor sit amet'

    if arg == 1:
        src, start, length = str_main, 0, 10
    elif arg == 2:
        src, start, length = str_main, 7, 10
    elif arg == 3:
        src, start, length = str_main, 7, 0
    elif arg == 4:
        src, start, length = str_main, 0, 0
    elif arg == 5:
        src, start, length = str_main, 400, 20
    elif arg == 6:
        src, start, length = str_main, 18, 50
    elif arg == 7:
        src, start, length = str_main, 26, 10
    elif arg == 8:
        src, start, length = str_main, 25, 10
    elif arg == 9:
        src, start, length = '', 0, 10
    elif arg == 10:
        src, start, length = str_main, 0, 100
    elif arg == 11:
        src, start, length = 'abcdef', 2, 3
    else:
        raise ValueError(f'unknown test {arg}')

    return ft_substr_expected(src, start, length).encode('ascii')


def main():
    for i in range(1, 12):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))


if __name__ == '__main__':
    main()