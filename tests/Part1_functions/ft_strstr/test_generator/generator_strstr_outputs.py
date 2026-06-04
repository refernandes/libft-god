from pathlib import Path

OUTDIR = Path('tests/Part1_functions/ft_strstr')
OUTDIR.mkdir(parents=True, exist_ok=True)


def ft_strstr_expected(haystack, needle):
    if needle == '':
        return haystack
    n = len(needle)
    for i in range(len(haystack) - n + 1):
        if haystack[i:i + n] == needle:
            return haystack[i:]
    return None


def run_case(arg):
    if arg == 1:
        res = ft_strstr_expected('lorem ipsum dolor sit amet', 'lorem')
    elif arg == 2:
        res = ft_strstr_expected('lorem ipsum dolor sit amet', 'ipsum')
    elif arg == 3:
        res = ft_strstr_expected('lorem ipsum dolor sit lorem ipsum dolor', 'ipsum')
    elif arg == 4:
        res = ft_strstr_expected('lorem ipsum dolor sit amet', '')
    elif arg == 5:
        res = ft_strstr_expected('lorem ipsum dolor sit amet', 'ipsumm')
    elif arg == 6:
        res = ft_strstr_expected('lorem ipsum dolor sit amet', 'dol')
    elif arg == 7:
        res = ft_strstr_expected('lorem ipsum dolor sit amet', 'consectetur')
    elif arg == 8:
        res = ft_strstr_expected('lorem ipsum dolor sit amet', 'amet')
    elif arg == 9:
        res = ft_strstr_expected('', '')
    elif arg == 10:
        res = ft_strstr_expected('', 'a')
    elif arg == 11:
        res = ft_strstr_expected('a', '')
    elif arg == 12:
        res = ft_strstr_expected('abc', 'abcd')
    elif arg == 13:
        res = ft_strstr_expected('aaaaa', 'aa')
    elif arg == 14:
        res = ft_strstr_expected('abababc', 'ababc')
    else:
        raise ValueError(f'unknown test {arg}')
    return b'NULL' if res is None else res.encode('ascii')


def main():
    for i in range(1, 15):
        path = OUTDIR / f'test{i:02d}.output'
        path.write_bytes(run_case(i))


if __name__ == '__main__':
    main()