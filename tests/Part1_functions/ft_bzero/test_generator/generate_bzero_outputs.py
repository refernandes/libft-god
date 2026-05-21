#!/usr/bin/env python3
# Gera arquivos .output binários para os testes do ft_bzero

from pathlib import Path

OUTDIR = Path("output")
OUTDIR.mkdir(exist_ok=True)

BASE = bytearray(b'e' * 5)

def apply_bzero(n):
    buf = bytearray(BASE)
    if n > 0:
        buf[:n] = b'\x00' * n
    return bytes(buf)

def write_case(num, n):
    data = apply_bzero(n)
    (OUTDIR / f"test{num:02d}.output").write_bytes(data)

# Casos para o seu main
write_case(1, 5)
write_case(2, 0)
write_case(3, 1)
write_case(4, 2)
write_case(5, 3)
write_case(6, 4)
write_case(7, 5)
write_case(8, 0)

# Manifesto hexadecimal
hex_lines = []
for i in range(1, 9):
    p = OUTDIR / f"test{i:02d}.output"
    hex_lines.append(f"test{i:02d}.output: {p.read_bytes().hex()}")
(OUTDIR / "manifest_hex.txt").write_text("\n".join(hex_lines) + "\n", encoding="utf-8")