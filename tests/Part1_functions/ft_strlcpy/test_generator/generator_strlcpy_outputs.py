from pathlib import Path

OUTDIR = Path('tests/Part1_functions/ft_strlcpy')
OUTDIR.mkdir(parents=True, exist_ok=True)

def py_strlcpy(dest, src, size):
    src_b = src.encode('ascii')
    if size > 0:
        copy_len = min(len(src_b), size - 1)
        dest[:copy_len] = src_b[:copy_len]
        dest[copy_len] = 0
    return len(src_b)

def run_case(arg):
    dest = bytearray(15)
    memset_val = ord('r')
    for i in range(6):
        dest[i] = memset_val
    
    if arg == 1:
        ret = py_strlcpy(dest, "lorem", 15)
    elif arg == 2:
        ret = py_strlcpy(dest, "", 15)
    elif arg == 3:
        ret = py_strlcpy(dest, "lorem ipsum", 3)
    elif arg == 4:
        ret = py_strlcpy(dest, "lorem ipsum dolor sit amet", 15)
    elif arg == 5:
        ret = py_strlcpy(dest, "lorem ipsum dolor sit amet", 0)
    elif arg == 6:
        ret = py_strlcpy(dest, "hello", 1)
    elif arg == 7:
        ret = py_strlcpy(dest, "abc", 2)
    elif arg == 8:
        ret = py_strlcpy(dest, "abcd", 4)
    else:
        raise ValueError(f"unknown test {arg}")
    return ret, dest

def main():
    for i in range(1, 9):
        ret, dest = run_case(i)
        path = OUTDIR / f'test{i:02d}.output'
        with open(path, 'wb') as f:
            f.write(str(ret).encode('ascii'))
            f.write(b'\n')
            f.write(dest)

if __name__ == "__main__":
    main()
