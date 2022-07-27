def diff_from_z(val: str):
    if 'A' <= val and val <= 'Z':
        return ord('Z') - ord(val)
    return 26 + ord('9') - ord(val)
def diff_from_0(val: str):
    if 'A' <= val and val <= 'Z':
        return 10 + ord(val) - ord('A')
    return ord(val) - ord('0')
def index_to_char(val: int):
    if val < 10:
        return f'{val}'
    return chr(ord('A') + val - 10)

class charOcc:
    def __init__(self, char: str):
        self.char = char
        self.digit_occ = [0] * 51
    def add_char_occ(self, digit: int):
        self.digit_occ[digit] += 1
    def increments(self):
        inc = 0
        base = 1
        for i in range(51):
            inc += base * diff_from_z(self.char) * self.digit_occ[i]
            base *= 36
        return inc

character_occ = {}
num_strings = int(input())
strings = [input() for _ in range(num_strings)]
top_k = int(input())

for s in strings:
    for idx, char in enumerate(s[::-1]):
        if char not in character_occ:
            character_occ[char] = charOcc(char)
        character_occ[char].add_char_occ(idx)

character_increments = {}
for char in character_occ:
    character_increments[char] = character_occ[char].increments()
character_increments_top_k = sorted(character_increments.items(), key=lambda x: x[1], reverse = True)
for i in range(min(top_k, len(character_increments_top_k))):
    for j in range(len(strings)):
        strings[j] = strings[j].replace(character_increments_top_k[i][0], 'Z')

updated_val = 0
for s in strings:
    base = 1
    for idx, char in enumerate(s[::-1]):
        updated_val += base * diff_from_0(char)
        base *= 36

updated_str = ""
if updated_val == 0:
    print(0)
else:
    while updated_val > 0:
        curr_val = (updated_val % 36)
        curr_char = index_to_char(curr_val)
        updated_str = curr_char + updated_str
        updated_val //= 36
    print(updated_str)
