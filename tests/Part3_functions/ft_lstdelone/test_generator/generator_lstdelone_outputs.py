#!/usr/bin/env python3

from pathlib import Path

OUTPUTS = {
    1: "OK: single node calls del once\n",
    2: "OK: does not free next node\n",
    3: "OK: middle node content passed to del\n",
    4: "OK: last node can be deleted\n",
    5: "OK: NULL content passed to del\n",
    6: "OK: NULL node handled safely\n",
    7: "SKIP: NULL del is undefined for libft testers\n",
    8: "OK: next pointer not traversed or freed\n",
    9: "OK: node freed exactly once\n",
    10: "OK: deleting node does not require list head\n",
    11: "OK: tail node deletion isolated\n",
}


def main() -> None:
    for test_number, content in OUTPUTS.items():
        Path(f"test{test_number:02d}.output").write_text(content, encoding="utf-8")
    print(f"Generated {len(OUTPUTS)} files.")


if __name__ == "__main__":
    main()