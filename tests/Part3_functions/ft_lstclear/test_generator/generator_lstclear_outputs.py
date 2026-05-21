#!/usr/bin/env python3

from pathlib import Path

OUTPUTS = {
    1: "OK: NULL list pointer target\n",
    2: "OK: single node cleared\n",
    3: "OK: two nodes cleared\n",
    4: "OK: four nodes cleared\n",
    5: "OK: clear from middle node onward\n",
    6: "OK: NULL content nodes cleared\n",
    7: "OK: NULL lst handled safely\n",
    8: "SKIP: NULL del is undefined for libft testers\n",
    9: "OK: head pointer reset to NULL\n",
    10: "OK: does not require original head\n",
    11: "OK: repeatable after becoming NULL\nOK: second clear on NULL safe\n",
}


def main() -> None:
    for test_number, content in OUTPUTS.items():
        Path(f"test{test_number:02d}.output").write_text(content, encoding="utf-8")
    print(f"Generated {len(OUTPUTS)} files.")


if __name__ == "__main__":
    main()