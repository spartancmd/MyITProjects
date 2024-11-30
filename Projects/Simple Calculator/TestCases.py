from main import *

class TestCases:
    def test_calculate_expression(self):
        expression = "2 * 2"
        parse_input(expression)
        expected_res = 4
        assert calculate_expression(expression) == expected_res # Returned wrong result

        expression = "(22 + 1) * (2 - 1)"
        parse_input(expression)
        expected_res = 23
        assert calculate_expression(expression) == expected_res # Returned wrong result

        expression = "2"
        parse_input(expression)
        expected_res = 2
        assert calculate_expression(expression) == expected_res # Returned wrong result

    def start_test(self):
        self.test_calculate_expression()