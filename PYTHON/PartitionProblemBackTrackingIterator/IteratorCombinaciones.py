import sys

def totalValues(combination, num):
        suma=0
        for i in range(0, len(num)):
            if combination[i] == 1:
                suma= suma + num[i]
        return suma

def isValidCombination(combination, num, sum):
        return totalValues(combination, num) <= sum

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

    def nextCombination(self, num, suma, found):
        for i in range(0, len(self.combination)):
            if self.combination[i] == self.valorMaximo:
                self.combination[i] = self.valorMinimo
            else:
                self.combination[i] = self.combination[i] + 1
                if isValidCombination(self.combination, num, suma):
                    return True
                else:
                    self.combination[i] = self.valorMinimo
        return False           

    def searchedCombination(self, num, previousSum):
        actualSum = totalValues(self.combination, num)
        if actualSum == previousSum:
            return True