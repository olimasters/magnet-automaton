#include <iterator>
#include <vector>
#include <random>

class Magnet
{
    public:
        Magnet(int width, int height);
            // Magnet is initialised randomly
        bool update(int i, int j);
            // Updates (i,j), if possible.  Returns true iff update occurred.
        bool isStable(void);

    private:
        std::vector<std::vector<int>> spins;
        bool updatePending(int i, int j);
            // Whether or not (i,j) is due an update.
};
