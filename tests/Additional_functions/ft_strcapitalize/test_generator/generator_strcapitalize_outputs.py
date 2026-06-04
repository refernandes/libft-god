from pathlib import Path

OUTDIR = Path('tests/Additional_functions/ft_strcapitalize')
OUTDIR.mkdir(parents=True, exist_ok=True)

def py_strcapitalize(s):
    res = list(s.lower())
    new_word = True
    for i in range(len(res)):
        if res[i].isalnum():
            if new_word:
                if 'a' <= res[i] <= 'z':
                    res[i] = res[i].upper()
                new_word = False
        else:
            new_word = True
    return "".join(res)

def run_case(arg):
    if arg == 1:
        return py_strcapitalize("  lorem IPsuM dOlor sit amet  ")
    elif arg == 2:
        return py_strcapitalize(" \n\tlorem 4ipsum DOLOR s\nit aMeT ")
    elif arg == 3:
        return py_strcapitalize("salut, comment tu vas ? unitmots trente-deux; vingt+et+un")
    elif arg == 4:
        return py_strcapitalize("123abcDEF GHIjkl")
    elif arg == 5:
        return py_strcapitalize("   hello   world   ")
    return ""

def main():
    for i in range(1, 6):
        (OUTDIR / f'test{i:02d}.output').write_text(run_case(i), encoding='utf-8')

if __name__ == "__main__":
    main()
