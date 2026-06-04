from pathlib import Path

OUTDIR = Path('tests/Part1_functions/ft_strlcat')
OUTDIR.mkdir(parents=True, exist_ok=True)


def c_strnlen(buf, size):
    limit = min(size, len(buf))
    for i in range(limit):
        if buf[i] == 0:
            return i
    return size


def py_strlcat(dest, src, size):
    src_b = src.encode('ascii')
    dlen = c_strnlen(dest, size)
    if dlen == size:
        return size + len(src_b)
    if size > dlen + 1:
        copy_len = min(len(src_b), size - dlen - 1)
        dest[dlen:dlen + copy_len] = src_b[:copy_len]
        dest[dlen + copy_len] = 0
    return dlen + len(src_b)


def init_dest():
    dest = bytearray(15)
    for i in range(6):
        dest[i] = ord('r')
    return dest


def run_case(arg):
    dest = init_dest()

    if arg == 1:
        dest[11] = ord('a')
        ret = py_strlcat(dest, 'lorem', 15)
    elif arg == 2:
        ret = py_strlcat(dest, '', 15)
    elif arg == 3:
        dest[0] = 0
        dest[11] = ord('a')
        ret = py_strlcat(dest, 'lorem ipsum', 15)
    elif arg == 4:
        dest[14] = ord('a')
        ret = py_strlcat(dest, 'lorem ipsum dolor sit amet', 15)
    elif arg == 5:
        dest[10] = ord('a')
        ret = py_strlcat(dest, 'lorem ipsum dolor sit amet', 0)
    elif arg == 6:
        dest[10] = ord('a')
        ret = py_strlcat(dest, 'lorem ipsum dolor sit amet', 1)
    elif arg == 7:
        dest = bytearray(b'r' * 15)
        ret = py_strlcat(dest, 'lorem ipsum dolor sit amet', 5)
    elif arg == 8:
        dest[10] = ord('a')
        ret = py_strlcat(dest, 'lorem ipsum dolor sit amet', 6)
    elif arg == 9:
        for i in range(14):
            dest[i] = ord('r')
        ret = py_strlcat(dest, 'lorem ipsum dolor sit amet', 15)
    elif arg == 10:
        dest[:4] = b'abc\x00'
        ret = py_strlcat(dest, 'de', 6)
    elif arg == 11:
        dest[:4] = b'abc\x00'
        ret = py_strlcat(dest, 'de', 5)
    elif arg == 12:
        dest[:7] = b'abcdef\x00'
        ret = py_strlcat(dest, 'X', 4)
    elif arg == 13:
        dest[0] = 0
        ret = py_strlcat(dest, 'abc', 1)
    elif arg == 14:
        dest[:4] = b'abc\x00'
        ret = py_strlcat(dest, '', 4)
    elif arg == 15:
        dest[:4] = b'abc\x00'
        ret = py_strlcat(dest, 'defgh', 4)
    elif arg == 16:
        dest[:5] = b'abcd\x00'
        ret = py_strlcat(dest, 'Z', 5)
    elif arg == 17:
        dest[:5] = b'abcd\x00'
        ret = py_strlcat(dest, 'Z', 4)
    elif arg == 18:
        dest = bytearray(b'x' * 15)
        dest[3] = 0
        ret = py_strlcat(dest, 'yz', 15)
    elif arg == 19:
        dest = bytearray(b'a' * 15)
        dest[14] = 0
        ret = py_strlcat(dest, 'b', 15)
    elif arg == 20:
        dest[0] = 0
        ret = py_strlcat(dest, '', 15)
    elif arg == 21:
        dest[:4] = b'abc\x00'
        ret = py_strlcat(dest, 'def', 3)
    elif arg == 22:
        dest[:4] = b'abc\x00'
        ret = py_strlcat(dest, 'def', 2)
    elif arg == 23:
        dest[:4] = b'abc\x00'
        ret = py_strlcat(dest, 'def', 0)
    elif arg == 24:
        dest = bytearray(b'a' * 15)
        dest[5] = 0
        ret = py_strlcat(dest, 'def', 15)
    elif arg == 25:
        dest = bytearray(b'a' * 15)
        # Não nulo-terminado nos primeiros 10 bytes
        ret = py_strlcat(dest, 'lorem', 10)
    else:
        raise ValueError(f'unknown test {arg}')

    return ret, dest


def main():
    for i in range(1, 26):
        ret, dest = run_case(i)
        path = OUTDIR / f'test{i:02d}.output'
        with open(path, 'wb') as f:
            f.write(str(ret).encode('ascii'))
            f.write(b'\n')
            f.write(dest)


if __name__ == '__main__':
    main()