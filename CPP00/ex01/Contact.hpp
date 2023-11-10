

#include <string>
class Contact
{
    
    public:
        void   set_first_name(std::string first_name);
        void   set_last_name(std::string last_name);
        void   set_nickname(std::string nickname);
        void   set_number(std::string numbero);
        void   set_darkest_secret(std::string darkest_secret);

        std::string get_first_name(void);
        std::string get_last_name(void);
        std::string get_nickname(void);
        std::string get_number(void);
        std::string get_darkest_secret(void);
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string number;
        std::string darkest_secret;
};