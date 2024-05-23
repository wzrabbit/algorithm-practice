board = input()
robot_pos = board.index('@')
box_pos = board.index('#')
goal_pos = board.index('!')

if robot_pos < box_pos < goal_pos or goal_pos < box_pos < robot_pos:
    print(abs(robot_pos - goal_pos) - 1)
else:
    print(-1)
