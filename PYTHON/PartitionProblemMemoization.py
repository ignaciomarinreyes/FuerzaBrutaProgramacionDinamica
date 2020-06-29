import time
import argparse

class Auxiliar:
  matriz = [[]]
  vector = []
  s = 0

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
    exit()

  set1 = []
  set2 = []

  x = len(v)
  currSum = int (sum(v)/2)

  while x > 0 and currSum >= 0:
    if Auxiliar.matriz[x-1][currSum]:
      x = x - 1
      set1.append(v[x])
    elif Auxiliar.matriz[x-1][currSum-v[x-1]]:
      x = x - 1
      currSum = currSum - v[x]
      set2.append(v[x])

  print("Set 1: ", set1)
  print("Set 2: ", set2)

def canPartitionRecursiveAux():
  Auxiliar.s = int (Auxiliar.s/2)
  Auxiliar.matriz = [[-1 for x in range(Auxiliar.s +1)] for y in range(len(Auxiliar.vector)+1)]
  for i in range(len(Auxiliar.vector) + 1 ):
    Auxiliar.matriz[i][0]= True
  for s in range(1, Auxiliar.s +1):
    Auxiliar.matriz[0][s] = False

def canPartition():
  if sum(Auxiliar.vector) % 2 != 0:
    return False
  else:
    return True

def canPartitionRecursive(i, s):
  if Auxiliar.matriz[i][s] != -1:
    return Auxiliar.matriz[i][s]
  
  if s <= 0: 
    return True

  if i == 0:
    return False

  if s < Auxiliar.vector[i-1]:
    Auxiliar.matriz[i][s]= canPartitionRecursive(i-1, s)
  else:
    Auxiliar.matriz[i][s]= canPartitionRecursive(i-1, s) or canPartitionRecursive(i -1, s- Auxiliar.vector[i -1])

  return Auxiliar.matriz[i][s]    
  
if __name__ == '__main__':
  # Command line library implementation
  parser = argparse.ArgumentParser(description = 'The program calculates the Partition Problemt. For further information, use the option -h')
  parser.add_argument('-di', '--input', action='store_true', help='Display input')
  parser.add_argument('-do', '--output', action='store_true', help='Display output')
  parser.add_argument('-dt', '--time', action='store_true', help='Display runtime of the program in seconds')
  parser.add_argument('-f', '--folder', metavar='', type=str, required=True, help='Read vectors from a folder')
  args = parser.parse_args()
  
  readFile(Auxiliar.vector)
  Auxiliar.s=sum(Auxiliar.vector)
  canPartitionRecursiveAux() 
  if canPartition():
    initial=time.time()
    found = canPartitionRecursive(len(Auxiliar.vector), Auxiliar.s)
    final=time.time()
  else:
    print("\nVector can not be partitioned")

  # Control of options
  if args.input: printInput(Auxiliar.vector)
  if args.output: printOutput(Auxiliar.vector, found)
  if args.time: printTime(initial, final, Auxiliar.vector)
