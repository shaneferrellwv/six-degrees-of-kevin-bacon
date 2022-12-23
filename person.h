#pragma once
#include "graph.h"
#include <set>
#include <string>

using namespace std;

class Person
{
    //member variables
    string name;
    set<string> films;
    int occupation;

public:
    //accessors and mutators
    enum Occupation { ACTOR, DIRECTOR, PRODUCER };
    Person();
    Person(string& name, Occupation occupation);
    void addFilm(string& film);
    set<string> getFilms() const;
    void setFilms(set<string>& films);
    string getName() const;
    void setName(string& name);
};