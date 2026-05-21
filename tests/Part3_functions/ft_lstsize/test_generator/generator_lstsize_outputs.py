#!/usr/bin/env python3

from pathlib import Path

OUTPUTS = {
    1: "OK: NULL list\n",
    2: "OK: single node\n",
    3: "OK: two nodes\n",
    4: "OK: four nodes\n",
    5: "OK: five nodes\n",
    6: "OK: count from middle node\n",
    7: "OK: NULL content ignored\n",
    8: "OK: does not modify single node list\n",
    9: "OK: does not modify multi node list\n",
    10: "OK: last node as head\n",
    11: "OK: repeatable result\n",
}


def main() -> None:
    for test_number, content in OUTPUTS.items():
        Path(f"test{test_number:02d}.output").write_text(content, encoding="utf-8")
    print(f"Generated {len(OUTPUTS)} files.")


if __name__ == "__main__":
    main()