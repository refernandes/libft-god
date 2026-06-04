from pathlib import Path


OUTDIR = Path('tests/Part2_functions/ft_putnbr_fd')
OUTDIR.mkdir(parents=True, exist_ok=True)


def run_case(arg):
    if arg == 1:
        return b"0"
    elif arg == 2:
        return b"5"
    elif arg == 3:
        return b"-5"
    elif arg == 4:
        return b"42"
    elif arg == 5:
        return b"-57"
    elif arg == 6:
        return b"164189"
    elif arg == 7:
        return b"-987441"
    elif arg == 8:
        return b"2147483647"
    elif arg == 9:
        return b"-2147483648"
    elif arg == 10:
        return b"1"
    elif arg == 11:
        return b"-1"
    elif arg == 12:
        return b"10"
    elif arg == 13:
        return b"-10"
    elif arg == 14:
        return b"100100"
    elif arg == 15:
        return b"-100100"
    elif arg == 16:
        return b""
    elif arg == 17:
        return b""
    else:
        raise ValueError(f"unknown test {arg}")


def main():
    for i in range(1, 18):
        out = run_case(i)
        path = OUTDIR / f"test{i:02d}.output"
        with open(path, "wb") as f:
            f.write(out)


if __name__ == "__main__":
    main()