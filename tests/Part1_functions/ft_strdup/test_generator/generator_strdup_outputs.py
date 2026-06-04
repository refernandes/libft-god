from pathlib import Path


OUTDIR = Path('tests/Part1_functions/ft_strdup')
OUTDIR.mkdir(parents=True, exist_ok=True)



def c_strdup(src):
    return src.encode('ascii') + b''



def run_case(arg):
    if arg == 1:
        dup = c_strdup('lorem ipsum dolor sit amet')
    elif arg == 2:
        dup = c_strdup('')
    elif arg == 3:
        dup = c_strdup('a')
    elif arg == 4:
        dup = c_strdup('   ')
    elif arg == 5:
        dup = c_strdup('Hello, world!')
    elif arg == 6:
        str2 = bytearray(b'abc')
        dup = bytes(str2)
        str2[0] = ord('z')
    else:
        raise ValueError(f'unknown test {arg}')

    return dup



def main():
    for i in range(1, 7):
        dup = run_case(i)
        path = OUTDIR / f'test{i:02d}.output'
        with open(path, 'wb') as f:
            f.write(dup)



if __name__ == '__main__':
    main()