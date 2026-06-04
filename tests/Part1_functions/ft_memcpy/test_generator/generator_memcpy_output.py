#!/usr/bin/env python3
# Gera arquivos .output binários para os testes do ft_memcpy

from pathlib import Path

OUTDIR = Path("tests/Part1_functions/ft_memcpy")
OUTDIR.mkdir(exist_ok=True)

BASE = bytearray(b'j' * 30)
ADDR_MSG = b"dest's adress was not returned\n"

def apply_memcpy(src, n):
    buf = bytearray(BASE)
    if n > 0:
        buf[:n] = src[:n]
    return bytes(buf)

def write_case(num, src, n, bad_return=False):
    data = b''
    if bad_return:
        data += ADDR_MSG
    data += apply_memcpy(src, n)
    (OUTDIR / f"test{num:02d}.output").write_bytes(data)

# Casos do seu main + expansão até 12
write_case(1, b"zyxwvutsrqponmlkjihgfedcba", 14)
write_case(2, b"zyxwvutst", 0)
write_case(3, b"zy\x00xw\x00vu\x00\x00tsr", 11)
write_case(4, b"zyxwvutsrqponmlkjihgfedcba", 1)
write_case(5, b"zyxwvutsrqponmlkjihgfedcba", 5)
write_case(6, b"zyxwvutsrqponmlkjihgfedcba", 26)
write_case(7, b"zy\x00xw\x00vu\x00\x00tsr", 11)
write_case(8, b"", 0)
write_case(9, b"abcdefghijklmnop", 16)
write_case(10, b"1234567890", 10)
write_case(11, b"A", 1)
write_case(12, b"\n\t\r\x0b\x0c", 5)

def main():
    # Caso 13: NULL, NULL, 0
    (OUTDIR / "test13.output").write_bytes(b"NULL SAFE")

if __name__ == "__main__":
    main()

# Manifesto hexadecimal
hex_lines = []
for i in range(1, 14):

    p = OUTDIR / f"test{i:02d}.output"
    hex_lines.append(f"test{i:02d}.output: {p.read_bytes().hex()}")
(OUTDIR / "manifest_hex.txt").write_text("\n".join(hex_lines) + "\n", encoding="utf-8")