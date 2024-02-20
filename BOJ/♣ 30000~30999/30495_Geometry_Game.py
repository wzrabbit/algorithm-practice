def get_length(a, b):
    return abs(a["x"] - b["x"]) ** 2 + abs(a["y"] - b["y"]) ** 2


def is_same_length(a1, a2, b1, b2):
    return get_length(a1, a2) == get_length(b1, b2)


def get_gcd(a, b):
    if a % b == 0:
        return b

    return get_gcd(b, a % b)


def get_slope(a, b):
    if a["x"] == b["x"]:
        return "vertical"

    if a["y"] == b["y"]:
        return "horizontal"

    if a["x"] > b["x"]:
        a, b = b, a

    x_lead = b["x"] - a["x"]
    y_lead = b["y"] - a["y"]
    gcd = get_gcd(x_lead, y_lead)

    return (x_lead // gcd, y_lead // gcd)


def is_same_slope(a1, a2, b1, b2):
    return get_slope(a1, a2) == get_slope(b1, b2)


def is_90_angle(a, b, c):
    start_slope = get_slope(a, b)
    end_slope = get_slope(b, c)

    if [start_slope, end_slope] == ["horizontal", "vertical"] or [
        start_slope,
        end_slope,
    ] == ["vertical", "horizontal"]:
        return True

    if start_slope not in ("horizontal", "vertical") and end_slope not in (
        "horizontal",
        "vertical",
    ):
        return (start_slope[0] == -end_slope[1] and start_slope[1] == end_slope[0]) or (
            start_slope[0] == end_slope[1] and start_slope[1] == -end_slope[0]
        )

    return False


def is_square(a, b, c, d):
    return is_rectangle(a, b, c, d) and is_rhombus(a, b, c, d)


def is_rectangle(a, b, c, d):
    return is_90_angle(a, b, c) and is_90_angle(b, c, d) and is_90_angle(c, d, a)


def is_rhombus(a, b, c, d):
    return (
        is_same_length(a, b, b, c)
        and is_same_length(b, c, c, d)
        and is_same_length(c, d, d, a)
    )


def is_parallelogram(a, b, c, d):
    return is_same_slope(a, b, c, d) and is_same_slope(b, c, d, a)


def is_trapezium(a, b, c, d):
    return is_same_slope(a, b, c, d) or is_same_slope(b, c, d, a)


def is_kite(a, b, c, d):
    return (is_same_length(a, b, b, c) and is_same_length(c, d, d, a)) or (
        is_same_length(b, c, c, d) and is_same_length(d, a, a, b)
    )


points = []

for _ in range(4):
    x, y = map(int, input().split())
    points.append({"x": x, "y": y})

a, b, c, d = points

if is_square(a, b, c, d):
    print("square")
elif is_rectangle(a, b, c, d):
    print("rectangle")
elif is_rhombus(a, b, c, d):
    print("rhombus")
elif is_parallelogram(a, b, c, d):
    print("parallelogram")
elif is_trapezium(a, b, c, d):
    print("trapezium")
elif is_kite(a, b, c, d):
    print("kite")
else:
    print("none")
