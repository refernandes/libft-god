from pathlib import Path

OUTDIR = Path("output/strncmp_expected")
OUTDIR.mkdir(parents=True, exist_ok=True)

def c_strncmp(s1: bytes, s2: bytes, n: int) -> int:
    if n == 0:
        return 0
    i = 0
    while i < n:
        c1 = s1[i] if i < len(s1) else 0
        c2 = s2[i] if i < len(s2) else 0
        if c1 != c2:
            return 1 if c1 > c2 else -1
        if c1 == 0 or c2 == 0:
            return 0
        i += 1
    return 0

def out(v: int) -> bytes:
    if v > 0:
        return b"1"
    if v < 0:
        return b"-1"
    return b"0"

tests = {
    1:  (b"salut",      b"salut",    5),
    2:  (b"test",       b"testss",   7),
    3:  (b"testss",     b"test",     7),
    4:  (b"test",       b"tEst",     4),
    5:  (b"",           b"test",     4),
    6:  (b"test",       b"",         4),
    7:  (b"abcdefghij", b"abcdefgxyz", 3),
    8:  (b"abcdefgh",   b"abcdwxyz", 4),
    9:  (b"zyxbcdefgh", b"abcdwxyz", 0),
    10: (b"abcdefgh",   b"",         0),
    11: (b"test\x80",   b"test\x00", 6),
    12: (b"abc",        b"abd",      2),
    13: (b"abc",        b"abd",      3),
    14: (b"abc",        b"abc",      10),
    15: (b"abc\x00z",   b"abc\x00a", 5),
    16: (b"\x80",       b"\x81",     1),
    17: (b"\x81",       b"\x80",     1),
    18: (b"ab",         b"abc",      3),
    19: (b"abc",        b"ab",       3),
}

for i in range(1, 20):
    s1, s2, n = tests[i]
    (OUTDIR / f"test{i:02d}.output").write_bytes(out(c_strncmp(s1, s2, n)))