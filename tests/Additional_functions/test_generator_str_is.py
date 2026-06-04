from pathlib import Path

def generate_outputs(name, base_tests, extra_tests):
    OUTDIR = Path(f'tests/Additional_functions/ft_{name}')
    OUTDIR.mkdir(parents=True, exist_ok=True)
    
    for i, res in enumerate(base_tests + extra_tests, 1):
        (OUTDIR / f'test{i:02d}.output').write_text(res, encoding='utf-8')

# ft_str_is_alpha
alpha_base = [
    "000000000000000000000000000000000000000000000000", # 1: 0-47 (48 zeros)
    "0000000000", # 2: 0-9 (10 zeros)
    "0000000", # 3: 58-64 (7 zeros)
    "11111111111111111111111111", # 4: A-Z (26 ones)
    "000000", # 5: 91-96 (6 zeros)
    "11111111111111111111111111", # 6: a-z (26 ones)
    "00000", # 7: 123-127 (5 zeros)
]
generate_outputs('str_is_alpha', alpha_base, ["1", "1", "0"])

# ft_str_is_lowercase
lower_base = [
    "000000000000000000000000000000000000000000000000",
    "0000000000",
    "0000000",
    "00000000000000000000000000", # A-Z are 0
    "000000",
    "11111111111111111111111111", # a-z are 1
    "00000",
]
generate_outputs('str_is_lowercase', lower_base, ["1", "1", "0"])

# ft_str_is_numeric
numeric_base = [
    "000000000000000000000000000000000000000000000000",
    "1111111111", # 0-9 are 1
    "0000000",
    "00000000000000000000000000",
    "000000",
    "00000000000000000000000000",
    "00000",
]
generate_outputs('str_is_numeric', numeric_base, ["1", "1", "0"])
