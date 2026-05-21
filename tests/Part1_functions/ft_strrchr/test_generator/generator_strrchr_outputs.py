from pathlib import Path

OUTDIR = Path('output/strrchr_expected')
OUTDIR.mkdir(parents=True, exist_ok=True)


def ft_strrchr_expected(s, ch):
    target = ch & 0xFF
    last = None
    data = s.encode('latin1') + b'\x00'
    for i, b in enumerate(data):
        if b == target:
            last = i
    if last is None:
        return None
    if target == 0:
        return ''
    return s[last:]


def run_case(arg):
    str2 = 'bonjour'

    if arg == 1:
        s, ch, base, expect = str2, ord('b'), str2, 0
    elif arg == 2:
        s, ch, base, expect = str2, ord('o'), str2, 4
    elif arg == 3:
        s, ch, base, expect = 'bonjourno', ord('o'), 'bonjourno', 8
    elif arg == 4:
        s, ch, base, expect = str2, ord('j'), str2, 3
    elif arg == 5:
        s, ch, base, expect = str2, ord('s'), None, None
    elif arg == 6:
        s, ch, base, expect = str2, 0, str2, 7
    elif arg == 7:
        s, ch, base, expect = '', 0, '', 0
    elif arg == 8:
        s, ch, base, expect = str2[2:], ord('b'), None, None
    elif arg == 9:
        s, ch, base, expect = 'aaaaa', ord('a'), 'aaaaa', 4
    elif arg == 10:
        s, ch, base, expect = 'a', ord('a'), 'a', 0
    elif arg == 11:
        s, ch, base, expect = '', ord('a'), None, None
    elif arg == 12:
        s, ch, base, expect = 'abcabcabc', ord('b'), 'abcabcabc', 7
    elif arg == 13:
        s, ch, base, expect = 'abcabcabc', 0, 'abcabcabc', 9
    elif arg == 14:
        s, ch, base, expect = str2[1:], ord('o'), str2[1:], 3
    else:
        raise ValueError(f'unknown test {arg}')

    res = ft_strrchr_expected(s, ch)
    if res is None:
        return b'NULL'

    out = bytearray(res.encode('latin1'))
    if base is not None:
        actual_index = len(base) - len(res)
        if actual_index != expect:
            out.extend(b'\nReturn value is false')
    return bytes(out)


def main():
    for i in range(1, 15):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))


if __name__ == '__main__':
    main()