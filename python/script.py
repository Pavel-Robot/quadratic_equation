# Скрипт на Python для сравнения ответов с sympy
import sympy 
from math import sqrt
def QuadEquation(a, b, c):
    ans = [] # Конечный результат будет здесь
    if a != 0: 
        if b != 0 and c != 0: # Если ур-е полное
            D = b * b - 4 * a * c
            if D > 0: ans = ans + [(-b + sqrt(D)) / (2*a), (-b - sqrt(D)) / (2*a)]
            elif D == 0: ans.append(-b  / (2*a))
            elif D < 0: ans = ans + [-b / (2*a), sqrt(-D) / (2*a), b / (2*a), -sqrt(-D) / (2*a)]
        else: #Если ур-е неполное
            if b == 0 and c != 0:
                if -c / a > 0: ans = ans + [sqrt(-c / a), -sqrt(-c / a)]
                if -c / a < 0: ans = ans + [0, sqrt(c / a), 0, -sqrt(c / a)]
            elif c == 0 and b != 0: ans = ans + [0, -b / a]
            elif c == 0 and b == 0: ans.append(0)
    else: print("Ошибка: уравнение не квадратичное!")
    return ans

a,b,c = -1, 1, 1

x = sympy.symbols('x')
equation = a*x**2 + b*x + c
solution = sympy.solve(equation, x)

s = []
for sol in solution:
    numerical_sol = sol.evalf()
    s.append(numerical_sol)


print(QuadEquation(a,b,c))
print(s)
