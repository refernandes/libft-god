from pathlib import Path


OUTDIR = Path('output/putstr_fd_expected')
OUTDIR.mkdir(parents=True, exist_ok=True)


def run_case(arg):
    if arg == 1:
        return b"lorem ipsum dolor sit amet"
    elif arg == 2:
        return b"  lorem\nipsum\rdolor\tsit amet  "
    elif arg == 3:
        return b""
    elif arg == 4:
        return b"lorem ipsum do"
    elif arg == 5:
        return b"a"
    elif arg == 6:
        return b"\n"
    elif arg == 7:
        return b"     "
    elif arg == 8:
        return b""
    elif arg == 9:
        return b""
    elif arg == 10:
        return b"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    else:
        raise ValueError(f"unknown test {arg}")


def main():
    for i in range(1, 11):
        out = run_case(i)
        path = OUTDIR / f"test{i:02d}.output"
        with open(path, "wb") as f:
            f.write(out)


if __name__ == "__main__":
    main()