from pathlib import Path

OUTDIR = Path('output/calloc_expected')
OUTDIR.mkdir(parents=True, exist_ok=True)


def run_case(arg):
    if arg == 1:
        return b'OK'
    elif arg == 2:
        return b'OK'
    elif arg == 3:
        return b'OK'
    elif arg == 4:
        return b'OK'
    elif arg == 5:
        return b'OK'
    elif arg == 6:
        return b'OK'
    elif arg == 7:
        return b'NULL'
    elif arg == 8:
        return b'NULL'
    else:
        raise ValueError(f'unknown test {arg}')


def main():
    for i in range(1, 9):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))


if __name__ == '__main__':
    main()