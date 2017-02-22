LINK_TARGET = Ptx.exe

OBJS =	\
	Line_info.o \
	Ptx.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

all: $(LINK_TARGET)
	echo All done

clean:
	rm -f $(REBUILDABLES)
	echo Clean done

$(LINK_TARGET): $(OBJS)
	g++ -g -o $@ $^

# Pattern rule
%.o : %.h %.cpp
	g++ -c $^
%.o : %.cpp
	g++ -g -o $@ -c $<

# Dependency Rules indicate that if any file to the right of the colon changes,
# the target to the left of the colon should be considered out-of-date.
Ptx.o: Line_info.h
Line_info.o : Line_info.h
