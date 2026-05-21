#!/usr/bin/env python3

from pathlib import Path

OUTPUTS = {
    1: "OK: maps all nodes into a new list\n",
    2: "OK: NULL list returns NULL\n",
    3: "OK: NULL f handled safely\n",
    4: "OK: NULL del handled safely\n",
    5: "OK: allocation failure clears partial new list\n",
    6: "OK: new contents are duplicated\n",
    7: "OK: original list unchanged\n",
    8: "OK: NULL content in first node handled\n",
    9: "OK: maps from middle node onward\n",
    10: "OK: single tail node mapping\n",
    11: "OK: f called once per node\n",
}


def main() -> None:
    for test_number, content in OUTPUTS.items():
        Path(f"test{test_number:02d}.output").write_text(content, encoding="utf-8")
    print(f"Generated {len(OUTPUTS)} files.")


if __name__ == "__main__":
    main()