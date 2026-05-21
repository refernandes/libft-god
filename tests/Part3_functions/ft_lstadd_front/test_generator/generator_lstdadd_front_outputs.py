#!/usr/bin/env python3

from pathlib import Path

OUTPUTS = {
    1: "OK: empty list + one node\n",
    2: "OK: one node list\n",
    3: "OK: multi node list preserves order\n",
    4: "OK: several pushes to front\n",
    5: "OK: old head becomes new->next\n",
    6: "OK: lst == NULL did not crash\n",
    7: "OK: new == NULL handled safely\n",
    8: "OK: new == NULL does not alter existing list\n",
    9: "OK: new->next overwritten correctly\n",
    10: "OK: content preserved\n",
    11: "OK: node with NULL content\n",
}


def main() -> None:
    base = Path('.')
    for test_number, content in OUTPUTS.items():
        filename = base / f"test{test_number:02d}.output"
        filename.write_text(content, encoding="utf-8")
    print(f"Generated {len(OUTPUTS)} files.")


if __name__ == "__main__":
    main()