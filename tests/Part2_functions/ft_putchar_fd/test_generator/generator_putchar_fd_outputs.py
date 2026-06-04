from pathlib import Path


OUTDIR = Path('tests/Part2_functions/ft_putchar_fd')
OUTDIR.mkdir(parents=True, exist_ok=True)


def write_range(start, end):
    return bytes(range(start, end + 1))


def run_case(arg):
    if arg == 1:
        return write_range(0, 47)
    elif arg == 2:
        return b"0123456789"
    elif arg == 3:
        return write_range(58, 64)
    elif arg == 4:
        return b"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    elif arg == 5:
        return write_range(91, 96)
    elif arg == 6:
        return b"abcdefghijklmnopqrstuvwxyz"
    elif arg == 7:
        return write_range(123, 127)
    elif arg == 8:
        return b"\x00"
    elif arg == 9:
        return b"A\nB"
    elif arg == 10:
        return bytes([255])
    elif arg == 11:
        return b""
    elif arg == 12:
        return b""
    else:
        raise ValueError(f"unknown test {arg}")


def main():
    for i in range(1, 13):
        out = run_case(i)
        path = OUTDIR / f"test{i:02d}.output"
        with open(path, "wb") as f:
            f.write(out)


if __name__ == "__main__":
    main()