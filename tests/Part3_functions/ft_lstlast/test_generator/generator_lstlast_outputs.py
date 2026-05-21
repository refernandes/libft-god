#!/usr/bin/env python3

from pathlib import Path

OUTPUTS = {
    1: "OK: NULL list\n",
    2: "OK: single node returns head\n",
    3: "OK: two nodes returns second\n",
    4: "OK: four nodes returns last\n",
    5: "OK: start from middle node\n",
    6: "OK: last node with NULL content\n",
    7: "OK: does not modify two node list\n",
    8: "OK: does not modify multi node list\n",
    9: "OK: returned node is true tail\n",
    10: "OK: repeatable result\n",
    11: "OK: single node content preserved\n",
}


def main() -> None:
    for test_number, content in OUTPUTS.items():
        Path(f"test{test_number:02d}.output").write_text(content, encoding="utf-8")
    print(f"Generated {len(OUTPUTS)} files.")


if __name__ == "__main__":
    main()