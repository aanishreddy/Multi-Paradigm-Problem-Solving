from collections import Counter

class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def calculate_mean(self):
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        mid = n // 2
        if n % 2 == 0:
            return (sorted_data[mid - 1] + sorted_data[mid]) / 2
        else:
            return sorted_data[mid]

    def calculate_mode(self):
        counter = Counter(self.data)
        max_freq = max(counter.values())
        return [num for num, freq in counter.items() if freq == max_freq]

if __name__ == "__main__":
    data = [1, 3, 3, 6, 7, 8, 9]
    calc = StatisticsCalculator(data)
    print(f"Mean: {calc.calculate_mean():.2f}")
    print(f"Median: {calc.calculate_median():.2f}")
    print(f"Mode(s): {calc.calculate_mode()}")
