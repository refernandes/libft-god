#!/usr/bin/env python3
from pathlib import Path

OUTPUTS = {
    1: "OK: applies function to all nodes\n",
    2: "OK: NULL list handled safely\n",
    3: "OK: NULL f handled safely\n",
    4: "OK: single tail node iteration\n",
    5: "OK: iterates from middle node onward\n",
    6: "OK: NULL content node tolerated by callback\n",
    7: "OK: does not modify list links\n",
    8: "OK: f called once per node\n",
    9: "OK: content modified in place\n",
    10: "OK: repeatable traversal\n",
    11: "OK: single node head iteration\n",
}

for test_number, content in OUTPUTS.items():
    Path(f"test{test_number:02d}.output").write_text(content, encoding="utf-8")
print(f"Generated {len(OUTPUTS)} files.")