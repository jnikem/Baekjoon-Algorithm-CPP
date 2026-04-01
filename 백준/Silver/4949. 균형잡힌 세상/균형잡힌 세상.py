while True:
    sentence = input()
    stack = []
    balanced = True
    if sentence == '.':
        break
    for i in range(len(sentence)):
        if sentence[i] == '(' or sentence[i] == '[':
            stack.append(sentence[i])
        elif sentence[i] == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                balanced = False
                break
        elif sentence[i] == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                balanced = False
                break
    if (balanced == True and not stack):
        print('yes')
    else:
        print('no')