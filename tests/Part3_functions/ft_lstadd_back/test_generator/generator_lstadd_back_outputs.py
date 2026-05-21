#!/usr/bin/env python3

from pathlib import Path

OUTPUTS = {
    1: "OK: empty list + one node\n",
    2: "OK: one node list\n",
    3: "OK: multi node list preserves order\n",
    4: "OK: several pushes to back\n",
    5: "OK: head unchanged after append\n",
    6: "OK: lst == NULL did not crash\n",
    7: "OK: new == NULL handled safely\n",
    8: "OK: new == NULL does not alter existing list\n",
    9: "OK: appends whole chain when new has next\n",
    10: "OK: node with NULL content\n",
    11: "OK: old tail now points to new\n",
}


def main() -> None:
    for test_number, content in OUTPUTS.items():
        Path(f"test{test_number:02d}.output").write_text(content, encoding="utf-8")
    print(f"Generated {len(OUTPUTS)} files.")


if __name__ == "__main__":
    main()