#include "graph.h"
#include "person.h"

//default constructor
Person::Person() {
    this->name = "Kevin Bacon";
    this->films = {};
    this->occupation = Person::ACTOR;
}

//copy constructor
Person::Person(string& name, Occupation occupation) {
    this->name = name;
    this->occupation = occupation;
}

//adds film to set of films that person is inolved in
void Person::addFilm(string& film) {
    this->films.insert(film);
}

//film list accessor
set<string> Person::getFilms() const {
    return this->films;
}

//film list mutator
void Person::setFilms(set<string>& films) {
    this->films = films;
}

//name accessor
string Person::getName() const {
    return this->name;
}

//name mutator
void Person::setName(string& name) {
    this->name = name;
}