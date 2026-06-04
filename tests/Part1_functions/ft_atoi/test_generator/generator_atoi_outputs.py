from pathlib import Path
import ctypes

OUTDIR = Path('tests/Part1_functions/ft_atoi')
OUTDIR.mkdir(parents=True, exist_ok=True)


def c_atoi_like(s: bytes) -> int:
    i = 0
    n = len(s)
    while i < n and s[i] in b' \t\n\r\x0b\x0c':
        i += 1
    sign = 1
    if i < n and s[i] == ord('-'):
        sign = -1
        i += 1
    elif i < n and s[i] == ord('+'):
        i += 1
    acc = 0
    while i < n and 48 <= s[i] <= 57:
        acc = acc * 10 + (s[i] - 48)
        i += 1
    return ctypes.c_int(sign * acc).value


def out_int(n: int) -> bytes:
    return str(n).encode('ascii')


def run_case(arg):
    tests = {
        1: b'0',
        2: b'546:5',
        3: b'-4886',
        4: b'+548',
        5: b'054854',
        6: b'000074',
        7: b'+-54',
        8: b'-+48',
        9: b'--47',
        10: b'++47',
        11: b'+47+5',
        12: b'-47-5',
        13: b'\x1b475',
        14: b'\t\n\r\x0b\x0c  469 \n',
        15: b'-2147483648',
        16: b'2147483647',
        17: b'\t\n\r\x0b\x0cd469 \n',
        18: b'\n\n\n  -46\x089 \n5d6',
        19: b'',
        20: b'+',
        21: b'-',
        22: b'+ 42',
        23: b'- 42',
        24: b' \t\n\r\x0b\x0c',
        25: b'   abc123',
        26: b'2147483648',
        27: b'-2147483649',
        28: b' \t\v\n\r\f-123',
        29: b' \f\r\n\v\t456',
        30: b' +123',
        31: b' -123',
        32: b'\t\t\t\n\n\n123',
        33: b'-0',
        34: b'+0',
        35: b'   + 123',
        36: b'   - 123',
        37: b'+-123',
        38: b'-+123',
        39: b'2147483647',
        40: b'-2147483648',
        41: b'0000000000000000000000000000000000000000042',
        42: b'99999999999999999999999999999999999999',
        43: b'-99999999999999999999999999999999999999',
        44: b'100000000000000000000000000000000000000',
    }
    return out_int(c_atoi_like(tests[arg]))


def main():
    for i in range(1, 45):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))


if __name__ == '__main__':
    main()