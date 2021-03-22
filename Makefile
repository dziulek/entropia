LIBS= -lsfml-graphics -lsfml-window -lsfml-system
HEADERS=constants.hpp _vector.hpp enthropy.hpp particle.hpp plot.hpp renderer.hpp symulation.hpp
FILES=_vector.cpp enthropy.cpp particle.cpp plot.cpp renderer.cpp symulation.cpp

Enthropy: $(FILES) $(HEADERS)
	g++ -o Enthropy $(FILES) $(LIBS) -I.
