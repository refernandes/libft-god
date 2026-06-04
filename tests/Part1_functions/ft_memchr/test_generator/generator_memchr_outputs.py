from pathlib import Path

OUTDIR = Path('tests/Part1_functions/ft_memchr')
OUTDIR.mkdir(parents=True, exist_ok=True)


def memchr(buf: bytes, c: int, n: int):
    target = c & 0xFF
    limit = min(n, len(buf))
    for i in range(limit):
        if buf[i] == target:
            return i
    return None


def c_string_from(buf: bytes, idx):
    if idx is None:
        return b'NULL'
    end = idx
    while end < len(buf) and buf[end] != 0:
        end += 1
    return buf[idx:end]


def int_array_le_bytes(values):
    out = bytearray()
    for v in values:
        out.extend(int(v).to_bytes(4, byteorder='little', signed=True))
    return bytes(out)


def run_case(arg):
    if arg == 1:
        buf = b'bonjour\x00'
        return c_string_from(buf, memchr(buf, ord('b'), 4))
    elif arg == 2:
        buf = b'bonjour\x00'
        return c_string_from(buf, memchr(buf, ord('o'), 7))
    elif arg == 3:
        buf = b'bonjourno\x00'
        return c_string_from(buf, memchr(buf, ord('n'), 2))
    elif arg == 4:
        buf = b'bonjour\x00'
        return c_string_from(buf, memchr(buf, ord('j'), 6))
    elif arg == 5:
        buf = b'bonjour\x00'
        return c_string_from(buf, memchr(buf, ord('s'), 7))
    elif arg == 6:
        tab = int_array_le_bytes([-49, 49, 1, -1, 0, -2, 2])
        idx = memchr(tab, -1, 7)
        return c_string_from(tab, idx)
    elif arg == 7:
        buf = b'bonjour\x00'
        return c_string_from(buf, memchr(buf, ord('r'), 7))
    elif arg == 8:
        buf = b'bonjour\x00'
        return c_string_from(buf, memchr(buf, ord('r'), 6))
    elif arg == 9:
        buf = b'bonjour\x00'
        return c_string_from(buf, memchr(buf, 0, 8))
    elif arg == 10:
        buf = b'bonjour\x00'
        return c_string_from(buf, memchr(buf, 0, 7))
    elif arg == 11:
        buf = b'abc\x00def\x00'
        return c_string_from(buf, memchr(buf, 0, 7))
    elif arg == 12:
        buf = b'abc\x80def\x00'
        return c_string_from(buf, memchr(buf, 0x80, 7))
    elif arg == 13:
        buf = b'abc\x80def\x00'
        return c_string_from(buf, memchr(buf, 0x80, 3))
    elif arg == 14:
        buf = b'abc\x80def\x00'
        return c_string_from(buf, memchr(buf, 0x80, 4))
    elif arg == 15:
        buf = b'abc\x00'
        return c_string_from(buf, memchr(buf, ord('a'), 0))
    else:
        raise ValueError(f'unknown test {arg}')


def main():
    for i in range(1, 16):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))


if __name__ == '__main__':
    main()