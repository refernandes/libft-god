from pathlib import Path


OUTDIR = Path('tests/Part2_functions/ft_split')
OUTDIR.mkdir(parents=True, exist_ok=True)


def py_split(s, c):
    if c == '\0':
        return [s] if s != "" else []
    out = []
    i = 0
    n = len(s)
    while i < n:
        while i < n and s[i] == c:
            i += 1
        start = i
        while i < n and s[i] != c:
            i += 1
        if start < i:
            out.append(s[start:i])
    return out


def render_case(tokens, empty_ok_mode=False):
    if empty_ok_mode:
        if len(tokens) == 0:
            return b"ok\n"
        return b"FAIL\n"
    out = b""
    for token in tokens:
        out += token.encode('utf-8') + b"\n"
    return out


def run_case(arg):
    if arg == 1:
        return render_case(py_split("          ", ' '), False)
    elif arg == 2:
        return render_case(py_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' '), False)
    elif arg == 3:
        return render_case(py_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' '), False)
    elif arg == 4:
        return render_case(py_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i'), False)
    elif arg == 5:
        return render_case(py_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z'), False)
    elif arg == 6:
        return render_case(py_split("", 'z'), True)
    elif arg == 7:
        return render_case(py_split("abc", ' '), False)
    elif arg == 8:
        return render_case(py_split("   abc", ' '), False)
    elif arg == 9:
        return render_case(py_split("abc   ", ' '), False)
    elif arg == 10:
        return render_case(py_split(",,,abc,,,def,,", ','), False)
    elif arg == 11:
        return render_case(py_split("aaaaaa", 'a'), True)
    elif arg == 12:
        return render_case(py_split("a", 'a'), True)
    elif arg == 13:
        return render_case(py_split("a", 'z'), False)
    elif arg == 14:
        return render_case(py_split("abc", '\0'), False)
    elif arg == 15:
        return render_case(py_split("\x01\x01abc\x01\x01def\x01\x01", '\x01'), False)
    elif arg == 16:
        return render_case(py_split("   lorem   ipsum   ", ' '), False)
    else:
        raise ValueError(f"unknown test {arg}")


def main():
    for i in range(1, 17):
        out = run_case(i)
        path = OUTDIR / f"test{i:02d}.output"
        with open(path, "wb") as f:
            f.write(out)


if __name__ == "__main__":
    main()