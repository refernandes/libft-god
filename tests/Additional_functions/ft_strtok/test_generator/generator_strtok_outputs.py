from pathlib import Path

OUTDIR = Path('tests/Additional_functions/ft_strtok')
OUTDIR.mkdir(parents=True, exist_ok=True)

def run_case(arg):
    if arg == 1:
        return b"abcdeflghijlkmnopqr"
    elif arg == 2:
        return b"abc,def;ghi,jkl.mno,pqr"
    elif arg == 3:
        return b"abcdefghijklmnopqr"
    elif arg == 4:
        return b"abcdef"
    elif arg == 5:
        return b"NULL"
    return b""

def main():
    for i in range(1, 6):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))

if __name__ == "__main__":
    main()
