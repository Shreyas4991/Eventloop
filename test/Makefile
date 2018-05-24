
testqueue:
	cd ./testqueue && make test
	
testevent:
	cd ./testevent && make

clean:
	find . -name *\.o -delete
	find . -name *\.gch -delete
	cd ./testqueue && make clean
	cd ./testevent && make clean

.PHONY: testqueue testevent