class IteratorCombinaciones:

    def __init__(self, N):
        self.valorMaximo = 1
        self.valorMinimo = 0
        self.combination = []
        for i in range(N):
            self.combination.append(0)

    def endOfCombinations(self):
        for i in self.combination:
            if i == 0:
                return False
        return True

    def nextCombination(self):
        for i in range(0, len(self.combination)):
            if self.combination[i] == self.valorMaximo:
                self.combination[i] = self.valorMinimo
            else:
                self.combination[i] = self.combination[i] + 1
                return self.combination

    def searchedCombination(self, num, previousSum):
        actualSum=0
        for i in range(0, len(num)):
            if self.combination[i] == 1:
                actualSum= actualSum + num[i]
        if actualSum == previousSum:
            return True