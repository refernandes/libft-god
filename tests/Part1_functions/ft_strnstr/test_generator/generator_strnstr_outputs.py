from pathlib import Path

OUTDIR = Path('tests/Part1_functions/ft_strnstr')
OUTDIR.mkdir(parents=True, exist_ok=True)

def py_strnstr(big, little, len_limit):
    if not little:
        return big
    n = len(little)
    for i in range(len_limit - n + 1):
        if i + n > len(big):
            break
        if big[i:i+n] == little:
            return big[i:]
    return None

def run_case(arg):
    big = "lorem ipsum dolor sit amet"
    
    if arg == 1:
        res = py_strnstr(big, "lorem", 15)
    elif arg == 2:
        res = py_strnstr(big, "ipsum", 15)
    elif arg == 3:
        res = py_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35)
    elif arg == 4:
        res = py_strnstr(big, "", 10)
    elif arg == 5:
        res = py_strnstr(big, "ipsumm", 30)
    elif arg == 6:
        res = py_strnstr(big, "dol", 30)
    elif arg == 7:
        res = py_strnstr(big, "consectetur", 30)
    elif arg == 8:
        res = py_strnstr(big, "sit", 10)
    elif arg == 9:
        res = py_strnstr(big, "dolor", 15)
    elif arg == 10:
        res = py_strnstr(big, "dolor", 0)
    elif arg == 11:
        res = py_strnstr(big, "ipsum", 10) # Ends at 11, should be NULL
    elif arg == 12:
        res = py_strnstr(big, "ipsum", 11) # Ends at 11, should be OK
    elif arg == 13:
        res = py_strnstr("aaaaa", "aa", 5)
    else:
        raise ValueError(f"unknown test {arg}")
    
    if res is None:
        return b"NULL"
    return res.encode('ascii')

def main():
    for i in range(1, 14):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))

if __name__ == "__main__":
    main()
