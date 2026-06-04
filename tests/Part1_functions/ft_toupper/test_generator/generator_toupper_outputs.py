from pathlib import Path

OUTDIR = Path('tests/Part1_functions/ft_toupper')
OUTDIR.mkdir(parents=True, exist_ok=True)


def ft_toupper_expected(c):
    if 97 <= c <= 122:
        return c - 32
    return c


def to_byte(v):
    return v & 0xFF


def run_case(arg):
    out = bytearray()

    if arg == 1:
        i = 0
        while i <= 47:
            out.append(to_byte(ft_toupper_expected(i)))
            i += 1
    elif arg == 2:
        i = ord('0')
        while i <= ord('9'):
            out.append(to_byte(ft_toupper_expected(i)))
            i += 1
    elif arg == 3:
        i = 58
        while i <= 64:
            out.append(to_byte(ft_toupper_expected(i)))
            i += 1
    elif arg == 4:
        i = ord('A')
        while i <= ord('Z'):
            out.append(to_byte(ft_toupper_expected(i)))
            i += 1
    elif arg == 5:
        i = 91
        while i <= 96:
            out.append(to_byte(ft_toupper_expected(i)))
            i += 1
    elif arg == 6:
        i = ord('a')
        while i <= ord('z'):
            out.append(to_byte(ft_toupper_expected(i)))
            i += 1
    elif arg == 7:
        i = 123
        while i <= 127:
            out.append(to_byte(ft_toupper_expected(i)))
            i += 1
    elif arg == 8:
        out.append(to_byte(ft_toupper_expected(-1)))
    elif arg == 9:
        out.append(to_byte(ft_toupper_expected(128)))
    elif arg == 10:
        out.append(to_byte(ft_toupper_expected(255)))
    else:
        raise ValueError(f'unknown test {arg}')

    return bytes(out)


def main():
    for i in range(1, 11):
        path = OUTDIR / f'test{i:02d}.output'
        path.write_bytes(run_case(i))


if __name__ == '__main__':
    main()