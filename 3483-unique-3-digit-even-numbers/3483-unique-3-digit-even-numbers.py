class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        numbers = set()
        n = len(digits)

        for i in range(n):
            # Hundreds digit cannot be 0
            if digits[i] == 0:
                continue

            for j in range(n):
                if j == i:
                    continue

                for k in range(n):
                    if k == i or k == j:
                        continue

                    # Last digit must be even
                    if digits[k] % 2 != 0:
                        continue

                    num = digits[i] * 100 + digits[j] * 10 + digits[k]
                    numbers.add(num)

        return len(numbers)