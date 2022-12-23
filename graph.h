#pragma once
#include "person.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

class Graph
{
    //containers
    unordered_map<string, Person>* m;
    unordered_map<string, set<string>>* adjList;

public:
    //function prototypes
    //big three
    Graph();
    Graph(const Graph& g);
    ~Graph();
    void operator=(const Graph& g);

    //accessors
    int V(); //returns num vertices
    int E(); //returns num edges

    void insert(vector<pair<string, Person::Occupation>> crew, string title);
    bool pathExistsBFS(string& from, string& to); // returns if path exists
    vector<Person> BFS(string& from, string& to); // returns path
    bool DFS(string& from, string& to); //returns shortest DFS path
};