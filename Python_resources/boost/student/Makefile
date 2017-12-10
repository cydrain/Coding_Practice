example.so: student.o student2py.o
	g++ student2py.o -o example.so -shared -fPIC -I/Users/caiyd/anaconda2/include/python2.7 -I/usr/local/include -L/Users/caiyd/anaconda2/lib/python2.7 -L/usr/local/lib -llibboost_python
student.o:
	g++ -c student.cpp -o student.o
student2py.o: student.o
	g++ -c student2py.cpp -o student2py.o -fPIC -I/Users/caiyd/anaconda2/include/python2.7 -I/usr/local/include

clean:
	rm -rf student.o student2py.o example.so
