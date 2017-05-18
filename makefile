P3.out : Project3.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o CodeGenerator.o
	g++ -std=c++11 -g -o P3.out Project3.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o  CodeGenerator.o

Project3.o : Project3.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -std=c++11 -g -c Project3.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -std=c++11 -g -c SetLimits.cpp

LexicalAnalyzer.o : LexicalAnalyzer.save
	cp LexicalAnalyzer.save LexicalAnalyzer.o

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h LexicalAnalyzer.h CodeGenerator.h
	g++ -std=c++11 -g -c SyntacticalAnalyzer.cpp

CodeGenerator.o: CodeGenerator.cpp CodeGenerator.h
	g++ -std=c++11 -g -c CodeGenerator.cpp

clean : 
	rm *.o P3.out *.gch *.lst *.dbg *.p2 *.p1 *# *~ a.out
run:
	./P3.out t.ss
	g++ t.cpp
	./a.out
t:
	cp Project3.cpp LexicalAnalyzer.h LexicalAnalyzer.save makefile test
	cp SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp CodeGenerator.h CodeGenerator.cpp test
	cp SetLimits.cpp SetLimits.c SetLimits.h test
	make -C test/

submit : Project3.cpp LexicalAnalyzer.h LexicalAnalyzer.save SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp  makefile README.txt # TODO: make sure this works RuleMonitor.cpp RuleMonitor.h
	rm -rf TeamMP3
	mkdir TeamMP3
	cp Project3.cpp TeamMP3
	cp LexicalAnalyzer.h TeamMP3
	cp LexicalAnalyzer.save TeamMP3
	cp SyntacticalAnalyzer.h TeamMP3
	cp SyntacticalAnalyzer.cpp TeamMP3
	cp CodeGenerator.h TeamMP3
	cp CodeGenerator.cpp TeamMP3
	cp makefile TeamMP3
	cp README.txt TeamMP3
	tar cfvz TeamMP3.tgz TeamMP3
	cp TeamMP3.tgz ~tiawatts/cs460drop
