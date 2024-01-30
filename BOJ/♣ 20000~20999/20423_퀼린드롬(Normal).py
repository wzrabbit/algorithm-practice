MIRROR_LETTERS = {
    "A": "A",
    "E": "3",
    "H": "H",
    "I": "I",
    "M": "M",
    "O": "O",
    "S": "2",
    "T": "T",
    "U": "U",
    "V": "V",
    "W": "W",
    "X": "X",
    "Y": "Y",
    "Z": "5",
    "b": "d",
    "d": "b",
    "i": "i",
    "l": "l",
    "m": "m",
    "n": "n",
    "o": "o",
    "p": "q",
    "q": "p",
    "r": "7",
    "u": "u",
    "v": "v",
    "w": "w",
    "x": "x",
    "0": "0",
    "1": "1",
    "2": "S",
    "3": "E",
    "5": "Z",
    "7": "r",
    "8": "8",
}


def generate_mirror_handle(start, end):
    start += len(handle) + 1
    end += len(handle) + 1

    generated_mirror_handle = (
        [""] * (len(handle) + 1) + list(handle) + [""] * (len(handle) + 1)
    )

    while generated_mirror_handle[start] != "" or generated_mirror_handle[end] != "":
        if generated_mirror_handle[start] == "":
            upper_end = generated_mirror_handle[end].upper()
            lower_end = generated_mirror_handle[end].lower()

            if upper_end in MIRROR_LETTERS:
                generated_mirror_handle[start] = MIRROR_LETTERS[upper_end]
                generated_mirror_handle[end] = upper_end
                start -= 1
                end += 1
                continue

            if lower_end in MIRROR_LETTERS:
                generated_mirror_handle[start] = MIRROR_LETTERS[lower_end]
                generated_mirror_handle[end] = lower_end
                start -= 1
                end += 1
                continue

            return None

        if generated_mirror_handle[end] == "":
            upper_start = generated_mirror_handle[start].upper()
            lower_start = generated_mirror_handle[start].lower()

            if upper_start in MIRROR_LETTERS:
                generated_mirror_handle[start] = upper_start
                generated_mirror_handle[end] = MIRROR_LETTERS[upper_start]
                start -= 1
                end += 1
                continue

            if lower_start in MIRROR_LETTERS:
                generated_mirror_handle[start] = lower_start
                generated_mirror_handle[end] = MIRROR_LETTERS[lower_start]
                start -= 1
                end += 1
                continue

            return None

        upper_start = generated_mirror_handle[start].upper()
        lower_start = generated_mirror_handle[start].lower()
        upper_end = generated_mirror_handle[end].upper()
        lower_end = generated_mirror_handle[end].lower()

        if upper_start in MIRROR_LETTERS and MIRROR_LETTERS[upper_start] == upper_end:
            generated_mirror_handle[start] = upper_start
            generated_mirror_handle[end] = upper_end
            start -= 1
            end += 1
            continue

        if lower_start in MIRROR_LETTERS and MIRROR_LETTERS[lower_start] == lower_end:
            generated_mirror_handle[start] = lower_start
            generated_mirror_handle[end] = lower_end
            start -= 1
            end += 1
            continue

        return None

    result_mirror_handle = []

    for i in range(len(generated_mirror_handle)):
        if generated_mirror_handle[i] != "":
            result_mirror_handle.append(generated_mirror_handle[i])

    return "".join(result_mirror_handle)


handle = input()
answer = None

for i in range(len(handle) * 2):
    start = i // 2
    end = i - i // 2

    cur_handle = generate_mirror_handle(start, end)

    if cur_handle != None and (answer == None or len(cur_handle) < len(answer)):
        answer = cur_handle

if answer == None:
    print(-1)
else:
    print(answer)
