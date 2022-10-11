CXX=g++
CPPFLAGS_ICPC=-std=gnu++17 -O2
CPPFLAGS=$(CPPFLAGS_ICPC) -fsanitize=address -pedantic  -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wcast-qual -Wunreachable-code
LDFLAGS_ICPC=-g -static-libgcc -static-libstdc++
LDFLAGS=$(LDFLAGS_ICPC)


%: %.cpp
	touch input
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o "run" '$(@F).cpp'

