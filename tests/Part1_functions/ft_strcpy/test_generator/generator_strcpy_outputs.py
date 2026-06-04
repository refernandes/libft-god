#!/usr/bin/env python3
from pathlib import Path

OUTDIR = Path('tests/Part1_functions/ft_strcpy')
OUTDIR.mkdir(parents=True, exist_ok=True)

OUTPUTS = {
    1: b"OK: basic copy short string\n",
    2: b"OK: basic copy longer string\n",
    3: b"OK: empty string copy\n",
    4: b"OK: copies terminating null byte\n",
    5: b"OK: stops writing after null terminator\n",
    6: b"OK: exact fit buffer\n",
    7: b"OK: returns exact dest pointer\n",
    8: b"OK: copies bytes not source pointer\n",
    9: b"OK: single character copy\n",
    10: b"OK: multiple sequential bytes copy\n",
    11: b"OK: same source and destination pointer\n",
    12: b"SKIP: NULL src is undefined behavior for strcpy\n",
    13: b"SKIP: NULL dest is undefined behavior for strcpy\n",
}

for i, out in OUTPUTS.items():
    with open(OUTDIR / f"test{i:02d}.output", "wb") as f:
        f.write(out)
print(f"Generated {len(OUTPUTS)} files in {OUTDIR}")