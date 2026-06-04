from pathlib import Path

OUTDIR = Path("tests/Part2_functions/ft_strjoin")
OUTDIR.mkdir(parents=True, exist_ok=True)

def out_bytes(s1: str, s2: str) -> bytes:
    return (s1 + s2).encode("utf-8")

def run_case(arg: int) -> bytes:
    if arg == 1:
        return out_bytes("lorem ipsum", "dolor sit amet")
    elif arg == 2:
        return out_bytes("", "dolor sit amet")
    elif arg == 3:
        return out_bytes("lorem ipsum", "")
    elif arg == 4:
        return out_bytes("", "")
    elif arg == 5:
        return out_bytes("line1\nline2", "\ttabbed")
    elif arg == 6:
        return out_bytes("São ", "Paulo")
    elif arg == 7:
        return out_bytes("a" * 10000, "b" * 10000)
    elif arg == 8:
        s1 = "test"
        s2 = "123"
        joined = s1 + s2
        return b"OK" if len(joined) == 7 else b"FAIL"
    elif arg == 9:
        return b"OK EMPTY"
    elif arg == 10:
        return b"OK ABC"
    raise ValueError(f"unknown test {arg}")

def main() -> None:
    for i in range(1, 11):
        path = OUTDIR / f"test{i:02d}.output"
        path.write_bytes(run_case(i))

if __name__ == "__main__":
    main()