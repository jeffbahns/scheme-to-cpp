P3.out : Project3.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o CodeGenerator.o
	g++ -g -o P3.out Project3.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o 

Project3.o : Project3.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -g -c Project3.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

LexicalAnalyzer.o : LexicalAnalyzer.save
	cp LexicalAnalyzer.save LexicalAnalyzer.o

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h LexicalAnalyzer.h CodeGenerator.h
	g++ -g -c SyntacticalAnalyzer.cpp

CodeGenerator.o: CodeGenerator.cpp CodeGenerator.h
	g++ -g -c CodeGenerator.cpp

clean : 
	rm *.o P3.out *.gch *.lst *.dbg *.p2 *.p1 *# *~

submit : Project3.cpp LexicalAnalyzer.h LexicalAnalyzer.save SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp RuleMonitor.cpp RuleMonitor.h makefile README.txt # TODO: make sure this works
	rm -rf TeamMP3
	mkdir TeamMP3
	cp Project3.cpp TeamMP3
	cp LexicalAnalyzer.h TeamMP3
	cp LexicalAnalyzer.save TeamMP3
	cp SyntacticalAnalyzer.h TeamMP3
	cp SyntacticalAnalyzer.cpp TeamMP3
	cp makefile TeamMP3
	cp README.txt TeamMP3
	tar cfvz TeamMP3.tgz TeamMP3
	cp TeamMP3.tgz ~tiawatts/cs460drop
