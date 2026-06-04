import os
from pathlib import Path

def generate_is_outputs(func_name):
    OUTDIR = Path(f'tests/Part1_functions/ft_{func_name}')
    OUTDIR.mkdir(parents=True, exist_ok=True)
    # Todas retornam 0 para -1 (EOF) exceto comportamentos específicos (mas na libft padrão é 0)
    (OUTDIR / 'test17.output').write_text("0", encoding='utf-8')

for f in ['isalnum', 'isalpha', 'isdigit', 'isprint', 'isascii']:
    generate_is_outputs(f)
