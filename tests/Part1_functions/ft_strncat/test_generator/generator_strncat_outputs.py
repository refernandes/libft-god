from pathlib import Path

OUTDIR = Path('output/strncat_expected')
OUTDIR.mkdir(parents=True, exist_ok=True)


def c_strlen(buf):
    i = 0
    while i < len(buf) and buf[i] != 0:
        i += 1
    return i


def py_strncat(dest, src, n):
    dlen = c_strlen(dest)
    src_b = src.encode('latin1')
    copy_len = min(len(src_b), n)
    dest[dlen:dlen + copy_len] = src_b[:copy_len]
    if dlen + copy_len < len(dest):
        dest[dlen + copy_len] = 0
    return dest


def init_dest():
    dest = bytearray(15)
    for i in range(6):
        dest[i] = ord('r')
    return dest


def run_case(arg):
    dest = init_dest()

    if arg == 1:
        dest[8] = ord('a')
        py_strncat(dest, 'lorem', 2)
    elif arg == 2:
        dest[11] = ord('a')
        py_strncat(dest, 'lorem', 9)
    elif arg == 3:
        py_strncat(dest, '', 3)
    elif arg == 4:
        py_strncat(dest, 'lorem ipsum', 0)
    elif arg == 5:
        dest[0] = 0
        dest[10] = ord('a')
        py_strncat(dest, 'lorem ipsum', 10)
    elif arg == 6:
        py_strncat(dest, 'lorem', 1)
    elif arg == 7:
        dest[7] = ord('a')
        py_strncat(dest, 'lo', 2)
    elif arg == 8:
        dest[7] = ord('a')
        py_strncat(dest, 'lo', 5)
    elif arg == 9:
        dest[0] = 0
        py_strncat(dest, '', 5)
    elif arg == 10:
        dest[0] = 0
        py_strncat(dest, 'abc', 1)
    elif arg == 11:
        dest[0] = 0
        py_strncat(dest, 'abc', 3)
    elif arg == 12:
        dest = bytearray(b'x' * 15)
        dest[3] = 0
        py_strncat(dest, 'yz', 2)
    elif arg == 13:
        dest = bytearray(15)
        dest[:4] = b'abc\x00'
        py_strncat(dest, 'def', 2)
    elif arg == 14:
        dest = bytearray(15)
        dest[:4] = b'abc\x00'
        py_strncat(dest, 'def', 3)
    else:
        raise ValueError(f'unknown test {arg}')

    return bytes(dest)


def main():
    for i in range(1, 15):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))


if __name__ == '__main__':
    main()