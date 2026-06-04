
from pathlib import Path

OUTDIR = Path('tests/Additional_functions/ft_itoa_base')
OUTDIR.mkdir(parents=True, exist_ok=True)

def itoa_base(n, base):
    if base < 2 or base > 16:
        return None
    
    digits = "0123456789abcdef"
    if n == 0:
        return "0"
    
    res = ""
    neg = False
    if n < 0:
        if base == 10:
            neg = True
            n = -n
        else:
            # Em bases não decimais, tratamos como unsigned de 32 bits (padrão comum)
            # ou apenas convertemos o valor absoluto. 
            # Mas ft_itoa_base da 42 geralmente só lida com sinal em base 10.
            # Vamos assumir o comportamento que os testes existentes parecem esperar.
            # Olhando o main.c original, ele passa -arg, etc.
            # Se for base 10, põe sinal. Se não, depende da implementação.
            # Vamos usar uma lógica comum:
            n = (1 << 64) + n if n < 0 else n # Para 64 bits se for LL
            # Simplificando para o que o teste original espera:
            # Se n < 0 e base != 10, muitas vezes ignora-se o sinal ou faz-se algo específico.
            # VAMOS COMPARAR COM O MAIN.C: ft_itoa_base(-arg, arg+1)
            # Se arg=1 (base 2), ft_itoa_base(-1, 2).
            pass
            
    # Na verdade, o generator original não existia. 
    # Vou implementar uma versão que reflita o ft_itoa_base padrão da 42.
    
    def to_base(num, b):
        if num == 0: return "0"
        res = ""
        is_neg = False
        if num < 0:
            if b == 10:
                is_neg = True
                num = -num
            else:
                # Caso especial para bases != 10 e números negativos
                # Frequentemente na 42, ft_itoa_base trata apenas base 10 com sinal.
                # Para outras bases, o comportamento varia. 
                # Se usarmos unsigned 32 bits:
                num = 0xffffffff + num + 1
        
        while num > 0:
            res = digits[num % b] + res
            num //= b
        if is_neg:
            res = "-" + res
        return res
    
    s = to_base(n, base)
    return s.upper()

def run_case(arg):
    if arg <= 15:
        base = arg + 1
        res = ""
        res += itoa_base(0, base) + "\n"
        res += itoa_base(arg, base) + "\n"
        res += itoa_base(-arg, base) + "\n"
        res += itoa_base(arg + 1, base) + "\n"
        res += itoa_base(-(arg + 1), base) + "\n"
        res += itoa_base(8124, base) + "\n"
        res += itoa_base(-9874, base) + "\n"
        res += itoa_base(543000, base) + "\n"
        res += itoa_base(-2147483648, base) + "\n"
        res += itoa_base(2147483647, base) + "\n"
        return res.encode('ascii')
    elif arg == 16:
        return b"NULL\n"
    elif arg == 17:
        return b"NULL\n"
    elif arg == 18:
        return b"NULL\n"
    return b""

def main():
    for i in range(1, 19):
        (OUTDIR / f'test{i:02d}.output').write_bytes(run_case(i))

if __name__ == "__main__":
    main()
