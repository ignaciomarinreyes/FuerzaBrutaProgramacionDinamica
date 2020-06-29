@echo off

echo Este script calculara los tiempos de ejecucion de los algoritmos.

echo -------INICIO---------

cd Executables
mkdir times

echo RESULTADOS_MEMOIZATION > times/resultadoM.txt
echo RESULTADOS_TABULATION > times/resultadoT.txt
echo RESULTADOS_BACKTRACKING_R > times/resultadoPBTR.txt
echo RESULTADOS_BRUTEFORCE_R > times/resultadoPBFR.txt
echo RESULTADOS_BACKTRACKING_IT > times/resultadoPBTI.txt	
echo RESULTADOS_BRUTEFORCE_IT > times/resultadoPBFI.txt

set /A jump=2
set /A min=4
set /A max=30


for /l %%x in (%min%, %jump%, %max%) do (
	cd ../FileGenerator/src
	call java -jar filesout.jar -n %%x -s -max 10
	

	cd ../../PYTHON
	echo Tiempo PYTHON >> ../Executables/times/resultadoM.txt
	python PartitionProblemMemoization.py -f ../fichVect.txt -dt >> ../Executables/times/resultadoM.txt
	
	cd ../Executables
	echo Tiempo JAVA >> times/resultadoM.txt
	java -jar pm.jar -f ../fichVect.txt -dt >> times/resultadoM.txt

	echo Tiempo C++ >> times/resultadoM.txt
	pm.exe -f ../fichVect.txt -t >> times/resultadoM.txt
	echo. >> times/resultadoM.txt


	cd ../PYTHON	
	echo Tiempo PYTHON >> ../Executables/times/resultadoPBFR.txt
	python PartitionProblemBruteForceRecursive.py -f ../fichVect.txt -dt >> ../Executables/times/resultadoPBFR.txt

	cd ../Executables
	echo Tiempo JAVA >> times/resultadoPBFR.txt
	java -jar pbfR.jar -f ../fichVect.txt -dt >> times/resultadoPBFR.txt

	echo Tiempo C++ >> times/resultadoPBFR.txt
	pbfR.exe -f ../fichVect.txt -t >> times/resultadoPBFR.txt
	echo. >> times/resultadoPBFR.txt

	cd ../PYTHON
	echo Tiempo PYTHON >> ../Executables/times/resultadoT.txt
	python PartitionProblemTabulation.py -f ../fichVect.txt -dt >> ../Executables/times/resultadoT.txt
	
	cd ../Executables
	echo Tiempo JAVA >> times/resultadoT.txt
	java -jar pt.jar -f ../fichVect.txt -dt >> times/resultadoT.txt

	echo Tiempo C++ >> times/resultadoT.txt
	pt.exe -f ../fichVect.txt -t >> times/resultadoT.txt
	echo. >> times/resultadoT.txt


	cd ../PYTHON	
	echo Tiempo PYTHON >> ../Executables/times/resultadoPBTR.txt
	python PartitionProblemBackTrackingRecursive.py -f ../fichVect.txt -dt >> ../Executables/times/resultadoPBTR.txt

	cd ../Executables
	echo Tiempo JAVA >> times/resultadoPBTR.txt
	java -jar pbtR.jar -f ../fichVect.txt -dt >> times/resultadoPBTR.txt

	echo Tiempo C++ >> times/resultadoPBTR.txt
	pbtR.exe -f ../fichVect.txt -t >> times/resultadoPBTR.txt
	echo. >> times/resultadoPBTR.txt


	cd ../PYTHON/PartitionProblemBackTrackingIterator
	echo Tiempo PYTHON >> ../../Executables/times/resultadoPBTI.txt
	python PartitionProblemBackTrackingIterator.py -f ../../fichVect.txt -dt >> ../../Executables/times/resultadoPBTI.txt

	cd ../../Executables
	echo Tiempo JAVA >> times/resultadoPBTI.txt
	java -jar pbtI.jar -f ../fichVect.txt -dt >> times/resultadoPBTI.txt

	echo Tiempo C++ >> times/resultadoPBTI.txt
	pbtI.exe -f ../fichVect.txt -t >> times/resultadoPBTI.txt
	echo. >> times/resultadoPBTI.txt


	cd ../PYTHON/PartitionProblemBruteForceIterator
	echo Tiempo PYTHON >> ../../Executables/times/resultadoPBFI.txt
	python PartitionProblemBruteForceIterator.py -f ../../fichVect.txt -dt >> ../../Executables/times/resultadoPBFI.txt
	
	cd ../../Executables
	echo Tiempo JAVA >> times/resultadoPBFI.txt
	java -jar pbfI.jar -f ../fichVect.txt -dt >> times/resultadoPBFI.txt
	
	echo Tiempo C++ >> times/resultadoPBFI.txt
	pbfI.exe -f ../fichVect.txt -t >> times/resultadoPBFI.txt
	echo. >> times/resultadoPBFI.txt
)

echo ------FIN--------
echo Se han creado ficheros con los tiempos en times/.

pause
exit