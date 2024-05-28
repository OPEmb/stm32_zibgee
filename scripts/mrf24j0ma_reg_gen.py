import re

SHORT_REGS_H_FILE = "mrf24j0ma_short_regs.h"
LONG_REGS_H_FILE = "mrf24j0ma_long_regs.h"
LAYOUT_H_FILE = "mrf24j0ma_mem_layout.h"
SHORT_REGS_DEF_FILE = "short_regs.txt"
LONG_REGS_DEF_FILE = "long_regs.txt"

def gen_bits_rev(base,n,start = 0):
    return generate_bits(base,reversed(range(start,n)))

def generate_bits(base,suffixes):
    return [base + str(suffix) for suffix in suffixes]

def generate_regs(base,suffixes):
    return [[base + str(suffix)] for suffix in suffixes]


def R():
    r = R.count
    R.count += 1
    return r
R.count = 0

def Res():
    return ["R" + str(R())]

reg_bit_template = """
// {0}
typedef union{{
    struct{{
      uint8_t {2:<10} :1;
      uint8_t {3:<10} :1;
      uint8_t {4:<10} :1;
      uint8_t {5:<10} :1;
      uint8_t {6:<10} :1;
      uint8_t {7:<10} :1;
      uint8_t {8:<10} :1;
      uint8_t {9:<10} :1;
    }};
    uint8_t val;
}} {1}_t;
"""

reg_bitless_template = """
        {2:<20} {1:>20} ; // {0}"""

reg_named_template = """
        {2:<20} {1:>20} ; // {0}"""

def gen_reg(reg):
    return reg_bit_template.format(*reg)

def gen_reg_bitless(reg):
    return reg_bitless_template.format(reg[0])

def gen_layout(regs,f,name,size):
    union_start = """
typedef union{
    struct{"""
    f.write(union_start)

    for sr in regs:
        if len(sr) > 3:
            f.write(reg_named_template.format(sr[0],sr[1],sr[1]+"_t"))
        else:
            f.write(reg_bitless_template.format(sr[0],sr[1],"uint8_t"))

 
    union_end = """
    }}r;
    uint8_t regs[{0}];
}} mrf24j0ma_{1}_t;
""".format(size,name)
    f.write(union_end)

def cleanup_regs(f):
    pattern = r'\[\d+:\d+\]'
    l = [re.sub(pattern, '', x.rstrip().replace("-","_").replace("/","_")).split() for x in f]
    regs = []
    for x in l:
        regs.append(x)
    for i,lr in enumerate(regs):
        if "Reserved" in lr or "Unimplemented" in lr:
            regs[i] = [lr[0],*Res()]
        elif "r" in lr:
            regs[i] = [x.replace("r","") for x in lr]
        elif len(lr) == 2:
            regs[i] = lr[:-1]
    return regs

with open("long_regs.txt") as f,\
    open("short_regs.txt") as f1,\
    open(LONG_REGS_H_FILE,"w") as h,\
    open(SHORT_REGS_H_FILE,"w") as h1, \
    open(LAYOUT_H_FILE,"w") as h2:

    warning = "// Automatically generated file. DO NOT EDIT.\n\n"
    include = "#include <stdint.h>\n\n" 
    h.write(warning)
    h.write(include)

    h1.write(warning)
    h1.write(include)

    short_regs = cleanup_regs(f1)
    long_regs = cleanup_regs(f)

    for i,lr in enumerate(long_regs):
        if len(lr) > 3:
            h.write(gen_reg(lr))
    for i,sr in enumerate(short_regs):
        if len(sr) > 3:
            h1.write(gen_reg(sr))


    h2.write(warning)
    h2.write("#include \"mrf24j0ma_short_regs.h\"\n")
    h2.write("#include \"mrf24j0ma_long_regs.h\"\n")

    gen_layout(short_regs,h2,"short_regs",0x40)
    gen_layout(long_regs,h2,"long_regs",0x4D)
    

    # for i,lr in enumerate(long_regs):
    # if len(lr) > 3: 
    #     h2.write(reg_named_template.format(lr[0],lr[1]))
    # else:
    #     h2.write(reg_bitless_template.format(lr[0],lr[1]))


    