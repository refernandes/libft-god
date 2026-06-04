#!/usr/bin/env python3
from pathlib import Path

OUTDIR = Path('tests/Part3_functions/ft_lstnew')
OUTDIR.mkdir(parents=True, exist_ok=True)

OUTPUTS = {
    1: b"OK: string content\n",
    2: b"OK: int pointer content\n",
    3: b"OK: NULL content\n",
    4: b"OK: char pointer content\n",
    5: b"OK: empty string content\n",
    6: b"OK: content is not copied\n",
    7: b"OK: struct pointer content\n",
    8: b"OK: binary buffer pointer\n",
    9: b"OK: string literal pointer\n",
    10: b"OK: distinct node allocations\n",
    11: b"OK: preserves exact pointer identity\n",
    12: b"OK: single byte local variable\n",
}

for i, out in OUTPUTS.items():
    with open(OUTDIR / f"test{i:02d}.output", "wb") as f:
        f.write(out)
print(f"Generated {len(OUTPUTS)} files in {OUTDIR}")