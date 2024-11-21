all: pe_data.x

pe_data.x: pe_data.cc
	g++ -o pe_data.x pe_data.cc

clean:
	rm *.x