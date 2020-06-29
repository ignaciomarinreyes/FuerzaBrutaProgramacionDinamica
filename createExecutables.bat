@echo off

echo Este script creara los ejecutables ".jar" y ".exe".
echo ---------INICIO--------

set projectsName[0]=PartitionProblemBackTrackingIterator
set projectsName[1]=PartitionProblemBackTrackingRecursive
set projectsName[2]=PartitionProblemBruteForceIterator
set projectsName[3]=PartitionProblemBruteForceRecursive
set projectsName[4]=PartitionProblemMemoization
set projectsName[5]=PartitionProblemTabulation

set projectsNamei[0]=partitionproblembacktrackingiterator
set projectsNamei[1]=partitionproblembacktrackingrecursive
set projectsNamei[2]=partitionproblembruteforceiterator
set projectsNamei[3]=partitionproblembruteforcerecursive
set projectsNamei[4]=partitionproblemmemoization
set projectsNamei[5]=partitionproblemtabulation

set exeNames[0]=pbtI
set exeNames[1]=pbtR
set exeNames[2]=pbfI
set exeNames[3]=pbfR
set exeNames[4]=pm
set exeNames[5]=pt

mkdir Executables

for /l %%x in (0,1,5) do (

	call cd CPP/%%projectsNamei[%%x]%%
	
	if %%x == 0 (
		call g++ -o ../../Executables/%%exeNames[%%x]%%.exe %%projectsName[%%x]%%.cpp BackTrackingIt.cpp ParserArgs.cpp ReadFile.cpp IteratorCombinations.cpp 
	) else if %%x == 1 (
		call g++ -o ../../Executables/%%exeNames[%%x]%%.exe %%projectsName[%%x]%%.cpp BackTrackingR.cpp ParserArgs.cpp ReadFile.cpp 
	) else if %%x == 2 (
		call g++ -o ../../Executables/%%exeNames[%%x]%%.exe %%projectsName[%%x]%%.cpp BruteForceIt.cpp ParserArgs.cpp ReadFile.cpp IteratorCombinations.cpp 
	) else if %%x == 3 (
		call g++ -o ../../Executables/%%exeNames[%%x]%%.exe %%projectsName[%%x]%%.cpp BruteForceR.cpp ParserArgs.cpp ReadFile.cpp 
	) else if %%x == 4 (
		call g++ -o ../../Executables/%%exeNames[%%x]%%.exe %%projectsName[%%x]%%.cpp Memoization.cpp ParserArgs.cpp ReadFile.cpp
	) else if %%x == 5 (
		call g++ -o ../../Executables/%%exeNames[%%x]%%.exe %%projectsName[%%x]%%.cpp Tabulation.cpp ParserArgs.cpp ReadFile.cpp 
	)

	call cd ../../JAVA/%%projectsName[%%x]%%/src

	call javac org/apache/commons/cli/*.java %%projectsNamei[%%x]%%/*.java
	call jar -cfe ../../../Executables/%%exeNames[%%x]%%.jar %%projectsNamei[%%x]%%.%%projectsName[%%x]%% %%projectsNamei[%%x]%%/*.class org/apache/commons/cli/*.class

	call cd ../../../	
)

cd FileGenerator/src
javac org/apache/commons/cli/*.java filegenerator/*.java
jar -cfe filesout.jar filegenerator.FileGenerator filegenerator/*.class org/apache/commons/cli/*.class

echo ------------FIN--------------
echo Se han creado los ejecutables ".jar" y ".exe" en Executables/.
pause
exit