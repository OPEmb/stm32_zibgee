hex_str="41  88  01  66  33  FF  FF  11  11  50  69  6E  67  00  00  ED  CB  6A  02"
hex_l = ["0x"+x for x in hex_str.split("  ")]
hex_arr = "{" + ",".join(hex_l) + "}"
print(hex_arr)