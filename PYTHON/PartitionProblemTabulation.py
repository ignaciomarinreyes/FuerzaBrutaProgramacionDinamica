import time
import argparse
import sys

class Auxiliar:
  dp = [[]]

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

def printOutput(vector, found):
	if found:
		print("\nVector can be partitioned")
	else:
		print("\nVector can not be partitioned")
		exit()
	
	set1 = []
	set2 = []

	x = len(vector)
	currSum = int (sum(vector)/2)
	print("Results: ", currSum)

	while x > 0 and currSum >= 0:
		if Auxiliar.dp[x-1][currSum]:
			x = x - 1
			set1.append(vector[x])
		elif Auxiliar.dp[x-1][currSum-vector[x-1]]:
			x = x - 1
			currSum = currSum - vector[x]
			set2.append(vector[x])
  
	print("Set 1: ", set1)
	print("Set 2: ", set2)

def canPartition(num):
  if sum(num) % 2 != 0:
    return False
  else:
  	return True

def canPartitionTab(num):
  s = sum(num)
  s = int(s / 2)
  n = len(num)
  Auxiliar.dp = [[False for x in range(s+1)] for y in range(n+1)]

  for i in range(0, n+1):
    Auxiliar.dp[i][0] = True

  for j in range(1, s+1):
    Auxiliar.dp[0][j] = False

  for i in range(1, n+1):
    for j in range(1, s+1):
      if j < num[i-1]:
        Auxiliar.dp[i][j] = Auxiliar.dp[i - 1][j]
      else:
        Auxiliar.dp[i][j] = Auxiliar.dp[i-1][j] or Auxiliar.dp[i - 1][j - num[i-1]]

  return Auxiliar.dp[n][s]

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
  	found=canPartitionTab(vector)
  	final=time.time()
  else:
  	print("Vector can not be partitioned")

  # Control of options
  if args.input: printInput(vector)
  if args.output: printOutput(vector, found) 
  if args.time: printTime(initial, final, vector)
