#!/usr/bin/env python3
# Gera arquivos .output binários para os testes do ft_memset

from pathlib import Path

OUTDIR = Path("output")
OUTDIR.mkdir(exist_ok=True)

BASE = bytearray(b'j' * 15)
ADDR_MSG = b"mem's adress was not returned\n"


def apply_memset(c, n):
    buf = bytearray(BASE)
    if n > 0:
        val = c & 0xFF
        buf[:n] = bytes([val]) * n
    return bytes(buf)


def write_case(num, c, n, bad_return=False):
    data = b''
    if bad_return:
        data += ADDR_MSG
    data += apply_memset(c, n)
    (OUTDIR / f"test{num:02d}.output").write_bytes(data)

# Casos equivalentes ao seu main atual
write_case(1, ord('c'), 5)
write_case(2, ord('c'), 14)
write_case(3, ord('\n'), 6)
write_case(4, 0, 1)
write_case(5, ord('c'), 15)
write_case(6, 0, 6)
write_case(7, ord('\t'), 5)
write_case(8, ord(' '), 10)
write_case(9, 1, 7)
write_case(10, 127, 4)
write_case(11, 255, 8)
write_case(12, -1, 5)
write_case(13, ord('A'), 1)
write_case(14, ord('Z'), 8)
write_case(15, ord('X'), 8)
write_case(16, ord('c'), 0)

# Arquivo auxiliar com versão hexadecimal para conferência visual
hex_lines = []
for i in range(1, 17):
    p = OUTDIR / f"test{i:02d}.output"
    hex_lines.append(f"test{i:02d}.output: {p.read_bytes().hex()}")
(OUTDIR / "manifest_hex.txt").write_text("\n".join(hex_lines) + "\n", encoding="utf-8")