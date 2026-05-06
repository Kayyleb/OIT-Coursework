// Name: Kayleb Cook
// Programming Assignment: Lab 2: Transport More Manager Functions
#include "Transport.h"


Transport::Transport()
{
	std::cout << "Transport Default Constrctor" << std::endl;
    passengers[0] = Passenger(133, "David", "Lynch");
    passengers[1] = Passenger(186, "Frank", "Herbert");
    passengers[2] = Passenger(101, "Francesca", "Annis");
    passengers[3] = Passenger(187, "Leonardo", "Cimino");
    passengers[4] = Passenger(162, "Brad", "Dourif");
    passengers[5] = Passenger(96, "Jose", "Ferrer");
    passengers[6] = Passenger(49, "Linda", "Hunt");
    passengers[7] = Passenger(140, "Freddie", "Jones");
    passengers[8] = Passenger(46, "Richard", "Jordan");
    passengers[9] = Passenger(89, "Kyle", "MacLachlan");
    passengers[10] = Passenger(118, "Virginia", "Madsen");
    passengers[11] = Passenger(152, "Silvana", "Mangano");
    passengers[12] = Passenger(194, "Everett", "McGill");
    passengers[13] = Passenger(2, "Kenneth", "McMillan");
    passengers[14] = Passenger(77, "Jack", "Nance");
    passengers[15] = Passenger(74, "Sian", "Phillips");
    passengers[16] = Passenger(50, "Jurgen", "Prochnow");
    passengers[17] = Passenger(3, "Paul", "Smith");
    passengers[18] = Passenger(5, "Patrick", "Stewart");
    passengers[19] = Passenger(180, "Dean", "Stockwell");
    passengers[20] = Passenger(151, "Max", "Sydow");
    passengers[21] = Passenger(1, "Alicia", "Witt");
    passengers[22] = Passenger(86, "Sean", "Young");
    passengers[23] = Passenger(42, "Danny", "Corkill");
    passengers[24] = Passenger(35, "Honorato", "Magaloni");
    passengers[25] = Passenger(17, "Judd", "Omen");
    passengers[26] = Passenger(168, "Molly", "Wryn");
    passengers[27] = Passenger(72, "Angelica", "Aragon");
    passengers[28] = Passenger(85, "Miguel", "Cane");
    passengers[29] = Passenger(48, "Eduardo", "Cassab");
    passengers[30] = Passenger(61, "Thomas", "Ebert");
    passengers[31] = Passenger(172, "Humberto", "Elizondo");
    passengers[32] = Passenger(71, "Ricardo", "Hill");
    passengers[33] = Passenger(117, "Juan", "Jaramillo");
    passengers[34] = Passenger(148, "Ernesto", "Laguardia");
    passengers[35] = Passenger(114, "James", "Mathers");
    passengers[36] = Passenger(26, "Ramon", "Menendez");
    passengers[37] = Passenger(51, "Ana", "Murguia");
    passengers[38] = Passenger(178, "Ruben", "Márquez");
    passengers[39] = Passenger(30, "William", "Phipps");
    passengers[40] = Passenger(122, "Scott", "Price");
    passengers[41] = Passenger(8, "Claudia", "Ramirez");
    passengers[42] = Passenger(185, "Julieta", "Rosen");
    passengers[43] = Passenger(10, "John", "Sabol");
    passengers[44] = Passenger(95, "Margarita", "Sanz");
    passengers[45] = Passenger(141, "Jacqueline", "Voltaire");
    passengers[46] = Passenger(105, "Dino", "Laurentiis");
    passengers[47] = Passenger(159, "Raffaella", "Laurentiis");
    passengers[48] = Passenger(13, "Jose", "Rodero");
}

Transport::Transport(const Transport& other)
{
    std::cout << "Transport Copy Constructor" << std::endl;
    for (int e = 0; e < 49; e++) {
        passengers[e] = other.passengers[e];
    }
}

Transport& Transport::operator=(const Transport& other)
{
    std::cout << "Transport Copy Assignment" << std::endl;
    if (this != &other) {
        for (int e = 0; e < 49; ++e) {
            passengers[e] = other.passengers[e];
        }
    }
    return *this;
}

Transport::~Transport()
{
    std::cout << "Transport Destructor" << std::endl;
}

void Transport::getNextpassenger()
{
}

void Transport::passengerArrival()
{
}

void Transport::musicalChairs()
{
}
