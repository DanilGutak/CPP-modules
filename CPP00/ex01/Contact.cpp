
#include "Contact.hpp"

void   Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}
void Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}
void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}
void Contact::set_number(std::string numbero)
{
    number = numbero;
}
void Contact::set_darkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}
std::string Contact::get_first_name(void)
{
    return first_name;
}
std::string Contact::get_last_name(void)
{
    return last_name;
}
std::string Contact::get_nickname(void)
{
    return nickname;
}
std::string Contact::get_number(void)
{
    return number;
}
std::string Contact::get_darkest_secret(void)
{
    return darkest_secret;
}