#!/usr/bin/env python3
from pathlib import Path

OUTDIR = Path("output")
OUTDIR.mkdir(exist_ok=True)
MSG = b"dest's adress was not returned\n"


def base_state():
    src = bytearray(b"lorem ipsum dolor sit amet\x00")
    return src


def write_case(num, arg):
    src = base_state()
    dest_index = 1
    data = b''

    if arg == 1:
        ret_index = dest_index
        copied = b"consectetur"[:5]
        src[dest_index:dest_index + 5] = copied
        out = bytes(src[dest_index:dest_index + 22])
    elif arg == 2:
        ret_index = dest_index
        copied = b"con\x00sec\x00\x00te\x00tur"[:10]
        src[dest_index:dest_index + 10] = copied
        out = bytes(src[dest_index:dest_index + 22])
    elif arg == 3:
        ret_index = dest_index
        temp = bytes(src[0:8])
        src[dest_index:dest_index + 8] = temp
        out = bytes(src[dest_index:dest_index + 22])
    elif arg == 4:
        ret_index = 0
        temp = bytes(src[dest_index:dest_index + 8])
        src[0:8] = temp
        out = bytes(src[dest_index:dest_index + 22])
    elif arg == 5:
        ret_index = 0
        out = bytes(src[dest_index:dest_index + 22])
    elif arg == 6:
        ret_index = dest_index
        src[dest_index:dest_index + 1] = b"Z"
        out = bytes(src[dest_index:dest_index + 22])
    elif arg == 7:
        ret_index = dest_index
        copied = b"abcdefghijklmnopqrstuv"[:22]
        src[dest_index:dest_index + 22] = copied
        out = bytes(src[dest_index:dest_index + 22])
    elif arg == 8:
        ret_index = 0
        temp = bytes(src[0:10])
        src[0:10] = temp
        out = bytes(src[dest_index:dest_index + 22])
    else:
        return

    path = OUTDIR / f"test{num:02d}.output"
    path.write_bytes(data + out)


for i in range(1, 9):
    write_case(i, i)

hex_lines = []
for i in range(1, 9):
    p = OUTDIR / f"test{i:02d}.output"
    hex_lines.append(f"test{i:02d}.output: {p.read_bytes().hex()}")
(OUTDIR / "manifest_hex.txt").write_text("\n".join(hex_lines) + "\n", encoding="utf-8")