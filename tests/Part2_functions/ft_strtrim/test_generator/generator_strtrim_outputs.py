from pathlib import Path



OUTDIR = Path('tests/Part2_functions/ft_strtrim')
OUTDIR.mkdir(parents=True, exist_ok=True)



def py_strtrim(s1, set_chars):
    trim_set = set(set_chars)
    start = 0
    end = len(s1)


    while start < end and s1[start] in trim_set:
        start += 1
    while end > start and s1[end - 1] in trim_set:
        end -= 1
    return s1[start:end]



def run_case(arg):
    if arg == 1:
        out = py_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " ")
    elif arg == 2:
        out = py_strtrim("lorem ipsum dolor sit amet", "te")
    elif arg == 3:
        out = py_strtrim(" lorem ipsum dolor sit amet", "l ")
    elif arg == 4:
        out = py_strtrim("lorem ipsum dolor sit amet", "tel")
    elif arg == 5:
        out = py_strtrim("          ", " ")
    elif arg == 6:
        out = py_strtrim("", " ")
    elif arg == 7:
        out = py_strtrim("abc", "")
    elif arg == 8:
        out = py_strtrim("xxxhelloxxx", "x")
    elif arg == 9:
        out = py_strtrim("xxxhello", "x")
    elif arg == 10:
        out = py_strtrim("helloxxx", "x")
    elif arg == 11:
        out = py_strtrim("xxhelloxxworldxx", "x")
    elif arg == 12:
        out = py_strtrim("abababab", "ab")
    elif arg == 13:
        out = py_strtrim("ababaHelloabab", "ab")
    elif arg == 14:
        out = py_strtrim("\t \nHello world\n \t", " \n\t")
    else:
        raise ValueError(f'unknown test {arg}')
    return out.encode('utf-8')  # NÃO adiciona \x00



def main():
    for i in range(1, 15):
        out = run_case(i)
        path = OUTDIR / f'test{i:02d}.output'
        with open(path, 'wb') as f:
            f.write(out)



if __name__ == '__main__':
    main()