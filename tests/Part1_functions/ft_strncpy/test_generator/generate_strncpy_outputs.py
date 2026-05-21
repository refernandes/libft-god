#!/usr/bin/env python3
from pathlib import Path

OUTDIR = Path("output")
OUTDIR.mkdir(exist_ok=True)
MSG = b"dest's adress was not returned\n"


def do_strncpy(initial_fill_len, src, n):
    dest = bytearray(b'\x00' * 15)
    if initial_fill_len > 0:
        dest[:initial_fill_len] = b's' * initial_fill_len
    i = 0
    while i < n and i < len(src) and src[i] != 0:
        dest[i] = src[i]
        i += 1
    while i < n:
        dest[i] = 0
        i += 1
    return bytes(dest)


def write_case(num, initial_fill_len, src, n, bad_return=False):
    data = b''
    if bad_return:
        data += MSG
    data += do_strncpy(initial_fill_len, src, n)
    (OUTDIR / f"test{num:02d}.output").write_bytes(data)

write_case(1, 13, b"lorem", 6)
write_case(2, 13, b"lorem", 8)
write_case(3, 13, b"", 3)
write_case(4, 13, b"lorem ipsum", 3)
write_case(5, 13, b"lorem ipsum", 0)
write_case(6, 5, b"lorem ipsum", 10)
write_case(7, 13, b"lorem ipsum", 1)
write_case(8, 13, b"lorem", 5)
write_case(9, 13, b"lorem", 7)
write_case(10, 13, b"a", 10)

hex_lines = []
for i in range(1, 11):
    p = OUTDIR / f"test{i:02d}.output"
    hex_lines.append(f"test{i:02d}.output: {p.read_bytes().hex()}")
(OUTDIR / "manifest_hex.txt").write_text("\n".join(hex_lines) + "\n", encoding="utf-8")