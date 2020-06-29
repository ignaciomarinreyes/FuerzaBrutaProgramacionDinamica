import time
import argparse
import sys

class Auxiliar:
  vector = []
  found = False
  s = 0
  combination = []
  size = 0

def readFile(v):
  try:
    file = args.folder
  except Exception as e:
    print(e)
    sys.exit("Directory Not Found, for help use the -h option")
  try:
    f = open(file, 'r')
    N = int (f.readline())
    for j in range (N):
      element = f.readline()
      v.append(int(element))
  except Exception as e:
    print(e)
    sys.exit("Vector is not named in the correct way, for help use the -h option")
  finally:
    f.close()

def printInput(v):
  print("\nVector is: ", v)

def printTime(initial, final, vector):
  n = str (len(vector))
  runtime = final - initial
  print("For", n, "elements -> Taken time: ", str(runtime) + " s.")

def printOutput(v, found):
  if found: 
    print("\nVector can be partitioned")
    print("Results: ", int ((sum(v))/2))
  else:
    print("\nVector can not be partitioned")

def partitionProblem(num):
  size = len(num)
  found=False
  combination = [False for i in range(size)]

def searchedCombination():
  actualSum=0
  for i in range(0, Auxiliar.size):
    if combination[i] == True:
      actualSum = actualSum + Auxiliar.vector[i]
  if actualSum == Auxiliar.s:                  
      Auxiliar.found=True

def canPartition(num):
  if sum(num) % 2 != 0:
    return False
  else:
    return True

def can_partition_Recursive(pos):
    if pos == 0:
      searchedCombination()
    else:
      combination[pos] = True
      can_partition_Recursive(pos - 1)
      combination[pos] = False
      can_partition_Recursive(pos - 1)
    return Auxiliar.found

if __name__ == '__main__':
  # Command line library implementation
  parser = argparse.ArgumentParser(description = "Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same. For further information, use the option '-h'.")
  parser.add_argument('-di', '--input', action='store_true', help='Display input data')
  parser.add_argument('-do', '--output', action='store_true', help='Display output data')
  parser.add_argument('-dt', '--time', action='store_true', help='Display taken time in seconds')
  parser.add_argument('-f', '--folder', metavar='', type=str, required=True, help='Read elements from a file')
  args = parser.parse_args()

  readFile(Auxiliar.vector)
  Auxiliar.s = int (sum(Auxiliar.vector)/2)
  Auxiliar.size = len(Auxiliar.vector)
  combination = [False for i in range(Auxiliar.size)]
  if canPartition(Auxiliar.vector):
    initial=time.time()
    found=can_partition_Recursive(Auxiliar.size - 1)
    final=time.time()
  else:
    print("Vector can not be partitioned")

  # Control of options
  if args.input: printInput(Auxiliar.vector)
  if args.output: printOutput(Auxiliar.vector, found)
  if args.time: printTime(initial, final, Auxiliar.vector)
