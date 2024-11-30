from TestCases import *
from Stack import *

def go_down_the_stack(nums_stack, opr_sym_stack):
    while opr_sym_stack.top() not in ('(', None):
        right_num = nums_stack.pop()
        left_num = nums_stack.pop()

        if opr_sym_stack.top() == '+':
            nums_stack.append(left_num + right_num)
        elif opr_sym_stack.top() == '-':
            nums_stack.append(left_num - right_num)
        elif opr_sym_stack.top() == '*':
            nums_stack.append(left_num * right_num)
        elif opr_sym_stack.top() == '/':
            if right_num == 0:
                raise ZeroDivisionError("Division through 0!")
            nums_stack.append(left_num / right_num)
        elif opr_sym_stack.top() == '^':
            nums_stack.append(left_num ** right_num)

        opr_sym_stack.pop()

def calculate_expression(expression): 
    stck_for_numbers = Stack()          # Creating stack frames
    stck_for_operation_sym = Stack()
    prioreties = {'+':1, '-':1, '*':2, '/':2, '^':3}

    for elm in expression:
        if elm in ('+', '-', '*', '/', '^') and stck_for_operation_sym is not None: # If the current element is a ariphmetic operation
            if prioreties[stck_for_operation_sym.top()] > prioreties[elm]:
                go_down_the_stack(stck_for_numbers, stck_for_operation_sym)
            else:
                stck_for_operation_sym.append(elm)
        else:   # If the current element is a number
            stck_for_numbers.append(elm)
    
    go_down_the_stack(stck_for_numbers, stck_for_operation_sym) # To clear the rest stack_frames in stck_for_operation_sym

    return stck_for_operation_sym.pop()


def get_input():    
    return input()

def parse_input(cmd): 
    if type(cmd) != list:
        cmd = cmd.split()

    for i in range(len(cmd)):
        if cmd[i] not in ('+', '-', '*', '/', '^'): # If i is a number
            cmd[i] = float(cmd[i])

def main():
    print("Calculator")

    while True:
        command = get_input("Type the expression:\n")
        parse_input(command)
        res = calculate_expression(command)

        print("Result:", res)

if __name__ == "__main__":
    TestCases.start_test()
    main()