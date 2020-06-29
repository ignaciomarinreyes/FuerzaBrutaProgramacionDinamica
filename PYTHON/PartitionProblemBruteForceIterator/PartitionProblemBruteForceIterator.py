from IteratorCombinaciones import *
import time
import argparse
import sys

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

def canPartition(num):
  if sum(num) % 2 != 0:
    return False
  else:
  	return True

def can_partition_Iterator(num):
    combination = []
    s = int (sum(num) / 2)
    found = False
    it = IteratorCombinaciones(len(num))
    while not it.endOfCombinations():
        combination = it.nextCombination()
        if it.searchedCombination(num, s):
            found = True
    return found

if __name__ == '__main__':
  # Command line library implementation
  parser = argparse.ArgumentParser(description = "Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same. For further information, use the option '-h'.")
  parser.add_argument('-di', '--input', action='store_true', help='Display input data')
  parser.add_argument('-do', '--output', action='store_true', help='Display output data')
  parser.add_argument('-dt', '--time', action='store_true', help='Display taken time in seconds')
  parser.add_argument('-f', '--folder', metavar='', type=str, required=True, help='Read elements from a file')
  args = parser.parse_args()

  vector = []
  readFile(vector)
  if canPartition(vector):
  	initial=time.time()
  	found= can_partition_Iterator(vector)
  	final=time.time()
  else:
  	print("\nVector can not be partitioned")

  # Control of options
  if args.input: printInput(vector)
  if args.output: printOutput(vector, found)
  if args.time: printTime(initial, final, vector)
        
