/**
 * Bee
 * 
 */

class Bee {

    public:

        // * Constructors

        Bee();

        // * Destructor

        ~Bee();

        // * Accessors
        
        int get_bee_health();
        int get_bee_armor() const;
        bool isAlive() const;

        int get_bee_position() const;
        bool hasAttacked() const;

        // * Mutators

        void set_bee_positon(int index);
        bool move();                    // Try to move bee
        void refresh_bee();             // Reset the attacked flag
        
        bool damage(int damage);        // ! taking an int for fire ant

    private:

        int health;
        int armor;
        bool alive;

        int position;
        bool attacked;

        // * Helpers


};