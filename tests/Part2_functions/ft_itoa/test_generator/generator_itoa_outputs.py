from pathlib import Path


OUTDIR = Path('output/itoa_expected')
OUTDIR.mkdir(parents=True, exist_ok=True)


def run_case(arg):
    if arg == 1:
        out = "0"
    elif arg == 2:
        out = "9"
    elif arg == 3:
        out = "-9"
    elif arg == 4:
        out = "10"
    elif arg == 5:
        out = "-10"
    elif arg == 6:
        out = "8124"
    elif arg == 7:
        out = "-9874"
    elif arg == 8:
        out = "543000"
    elif arg == 9:
        out = "-2147483648"
    elif arg == 10:
        out = "2147483647"
    elif arg == 11:
        out = "1"
    elif arg == 12:
        out = "-1"
    elif arg == 13:
        out = "1000"
    elif arg == 14:
        out = "-1000"
    elif arg == 15:
        out = "-100100"
    else:
        raise ValueError(f"unknown test {arg}")
    return out.encode("ascii")


def main():
    for i in range(1, 16):
        out = run_case(i)
        path = OUTDIR / f"test{i:02d}.output"
        with open(path, "wb") as f:
            f.write(out)


if __name__ == "__main__":
    main()