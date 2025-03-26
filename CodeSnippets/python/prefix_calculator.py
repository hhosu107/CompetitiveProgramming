import operator
import math
import re

class PrefixCalculator:
    """
    사칙연산, 괄호, let 바인딩을 지원하는 Prefix Calculator 클래스.
    """
    def __init__(self):
        # 지원하는 연산자 정의
        self.ops = {
            '+': operator.add,
            '-': operator.sub,
            '*': operator.mul,
            '/': operator.truediv, # 실수 나눗셈 지원
        }

    def _tokenize(self, expression):
        """표현식 문자열을 토큰 리스트로 변환합니다."""
        # 괄호 주변에 공백 추가하여 분리 용이하게 함
        expression = expression.replace('(', ' ( ').replace(')', ' ) ')
        tokens = expression.split()
        return tokens

    def _parse_tokens(self, tokens):
        """토큰 리스트를 파싱하여 중첩 리스트 구조(AST)로 만듭니다."""
        if not tokens:
            raise ValueError("빈 표현식 또는 잘못된 괄호")

        token = tokens.pop(0)
        if token == '(':
            # 리스트 시작
            ast_list = []
            # 닫는 괄호가 나올 때까지 재귀적으로 파싱
            while tokens[0] != ')':
                ast_list.append(self._parse_tokens(tokens))
            tokens.pop(0) # ')' 제거
            return ast_list
        elif token == ')':
            raise ValueError("예상치 못한 ')'")
        else:
            # 숫자 또는 변수/키워드
            try:
                # 정수 또는 실수로 변환 시도
                return float(token) if '.' in token else int(token)
            except ValueError:
                # 변환 실패 시 문자열(변수 또는 키워드)로 처리
                return token

    def _evaluate_ast(self, ast, env):
        """파싱된 AST를 주어진 환경(env)에서 평가합니다."""
        if isinstance(ast, (int, float)):
            # 숫자일 경우 그 값을 반환
            return ast
        elif isinstance(ast, str):
            # 문자열(변수)일 경우 환경에서 찾아 반환
            if ast in env:
                return env[ast]
            else:
                raise NameError(f"정의되지 않은 변수: {ast}")
        elif isinstance(ast, list):
            # 리스트(표현식)일 경우
            if not ast:
                raise ValueError("빈 표현식 평가 불가")

            op_token = ast[0]

            if op_token == 'let':
                # (let var value body) 구조
                if len(ast) != 4:
                    raise SyntaxError("잘못된 let 형식: (let 변수 값 표현식)")

                var_name = ast[1]
                if not isinstance(var_name, str) or var_name in self.ops or var_name == 'let':
                     raise SyntaxError(f"잘못된 변수 이름: {var_name}")

                value_expr = ast[2]
                body_expr = ast[3]

                # value_expr 평가
                var_value = self._evaluate_ast(value_expr, env)

                # 새로운 환경 생성 (기존 환경 복사 + 새 변수 추가)
                # 중요: body 평가 시에만 이 변수가 유효하도록 새 사전을 만듦
                new_env = env.copy()
                new_env[var_name] = var_value

                # body_expr를 새로운 환경에서 평가
                return self._evaluate_ast(body_expr, new_env)

            elif op_token in self.ops:
                # 사칙연산 (+, -, *, /)
                op_func = self.ops[op_token]
                if len(ast) != 3:
                    raise SyntaxError(f"연산자 '{op_token}'는 두 개의 인수가 필요합니다.")

                # 피연산자들을 재귀적으로 평가
                try:
                    val1 = self._evaluate_ast(ast[1], env)
                    val2 = self._evaluate_ast(ast[2], env)
                except IndexError:
                     raise SyntaxError(f"연산자 '{op_token}'에 인수가 부족합니다.")

                # 연산 수행 (0으로 나누기 오류 처리)
                if op_token == '/' and val2 == 0:
                    raise ZeroDivisionError("0으로 나눌 수 없습니다.")
                return op_func(val1, val2)

            else:
                raise SyntaxError(f"알 수 없는 연산자 또는 키워드: {op_token}")
        else:
            raise TypeError(f"평가할 수 없는 타입: {type(ast)}")

    def calculate(self, expression):
        """주어진 prefix 표현식 문자열을 계산합니다."""
        try:
            tokens = self._tokenize(expression)
            if not tokens:
                return "입력이 없습니다."
            ast = self._parse_tokens(tokens)
             # 파싱 후 남은 토큰이 있다면 문법 오류
            if tokens:
                raise SyntaxError(f"잘못된 형식 또는 추가 토큰 발견: {tokens}")
            # 초기 환경(env)은 비어 있음
            result = self._evaluate_ast(ast, {})
            # 정수 결과는 정수로 표시
            if isinstance(result, float) and result.is_integer():
                return int(result)
            return result
        except (ValueError, SyntaxError, NameError, ZeroDivisionError, IndexError, TypeError) as e:
            return f"오류: {e}"

# 계산기 인스턴스 생성
calc = PrefixCalculator()

# 테스트 예제
print(f"(+ 1 2) => {calc.calculate('(+ 1 2)')}")
print(f"(* 3 (- 4 1)) => {calc.calculate('(* 3 (- 4 1))')}")
print(f"(/ 10 4) => {calc.calculate('(/ 10 4)')}")
print(f"(let x 5 (+ x 3)) => {calc.calculate('(let x 5 (+ x 3))')}")
print(f"(let a 10 (let b (* a 2) (/ b 4))) => {calc.calculate('(let a 10 (let b (* a 2) (/ b 4)))')}")
print(f"(let x 2 (* x (let x 3 (+ x x)))) => {calc.calculate('(let x 2 (* x (let x 3 (+ x x))))')}") # 스코프 테스트
print(f"(/ 1 0) => {calc.calculate('(/ 1 0)')}")
print(f"(+ 1) => {calc.calculate('(+ 1)')}")
print(f"(let y) => {calc.calculate('(let y)')}")
print(f"(+ x 1) => {calc.calculate('(+ x 1)')}")
print(f"() => {calc.calculate('()')}")
print(f"(+ 1 2 3) => {calc.calculate('(+ 1 2 3)')}")
print(f"(let 1 2 3) => {calc.calculate('(let 1 2 3)')}")
