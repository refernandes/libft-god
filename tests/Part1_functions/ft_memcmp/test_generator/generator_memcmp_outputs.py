from pathlib import Path

OUTDIR = Path("output/memcmp_expected")
OUTDIR.mkdir(parents=True, exist_ok=True)

def sign(n: int) -> bytes:
    if n > 0:
        return b"1"
    if n < 0:
        return b"-1"
    return b"0"

def c_memcmp(b1: bytes, b2: bytes, n: int) -> int:
    for i in range(n):
        x = b1[i]
        y = b2[i]
        if x != y:
            return 1 if x > y else -1
    return 0

tests = {
    1:  (b"salut",       b"salut",       5),
    2:  (b"t\x80",       b"t\x00",       2),
    3:  (b"testss",      b"test\x00",    5),
    4:  (b"test",        b"tEst",        4),
    5:  (b"\x00\x00\x00\x00", b"test",   4),
    6:  (b"test",        b"\x00\x00\x00\x00", 4),
    7:  (b"abcdefghij",  b"abcdefgxyz",  7),
    8:  (b"abcdefgh",    b"abcdwxyz",    6),
    9:  (b"zyxbcdefgh",  b"abcdefgxyz",  0),
    10: (b"abc\x00def",  b"abc\x00xyz",  4),
    11: (b"abc\x00def",  b"abc\x00xyz",  7),
    12: (b"abc",         b"abd",         2),
    13: (b"abc",         b"abd",         3),
    14: (b"\x80",        b"\x81",        1),
    15: (b"\x81",        b"\x80",        1),
    16: (b"\xff",        b"\x00",        1),
    17: (b"\x00\x01",    b"\x00\x02",    2),
    18: (b"\x00\x02",    b"\x00\x01",    2),
    19: (b"abcdx",       b"abcdy",       4),
    20: (b"abcdx",       b"abcdy",       5),
}

for i in range(1, 21):
    s1, s2, n = tests[i]
    (OUTDIR / f"test{i:02d}.output").write_bytes(sign(c_memcmp(s1, s2, n)))