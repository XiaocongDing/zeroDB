sqlparse: sqlparse.l sqlparse.ypp
	flex -o scanner.cpp sqlparse.l
	bison -t sqlparse.ypp
	g++ sqlparse.tab.cpp -o sqlparse