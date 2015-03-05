OPT:
	g++ resolution.cpp -lrt -o res
	g++ us.cpp us2.cpp -O3 -o us
	g++ ns.cpp ns2.cpp -lrt -O3 -o ns
