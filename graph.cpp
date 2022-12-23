#include "graph.h"
#include "person.h"
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <stack>

//default Graph constructor
Graph::Graph() {
    this->m = new unordered_map<string, Person>;
    this->adjList = new unordered_map<string, set<string>>;
}

//copy constructor
Graph::Graph(const Graph& g) {
    this->m = g.m;
    this->adjList = g.adjList;
}

//Graph destructor
Graph::~Graph() {
    delete this->m;
    delete this->adjList;
}

//assignemnt operator
void Graph::operator=(const Graph& g) {
    this->m = g.m;
    this->adjList = g.adjList;
}

//accessor for number of vertices in graph
int Graph::V() {
    return this->adjList->size();
}

//accessor for number of edges in graph
int Graph::E() {
    int numEdges{};

    for (auto iter = this->adjList->begin(); iter != this->adjList->end(); ++iter) {
        numEdges += iter->second.size();
    }

    return numEdges;
}

//inserts persons from one film into graph and makes connections between each person
void Graph::insert(vector<pair<string, Person::Occupation>> crew, string title) {
    for (pair<string, Person::Occupation> person : crew)
    {
            set<string> s;
            this->adjList->insert(make_pair(person.first, s));
            Person p = Person(person.first, person.second);
            this->m->insert(make_pair(person.first, p));
            this->m->at(person.first).addFilm(title);

        for (pair<string, Person::Occupation> person2 : crew)
        {
            if (person.first != person2.first)
            {
                this->adjList->at(person.first).insert(person2.first);
            }
        }
    }
}

//finds whether a path between two persons exists in graph
bool Graph::pathExistsBFS(string& from, string& to) {
    queue<string> q;
    set<string> visited;

    visited.insert(from);
    q.push(from);

    while (!q.empty()) {
        string p = q.front();
        q.pop();

        if (p == to) {
            return true;
        }

        set<string> neighbors = this->adjList->at(p);

        for (string i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                q.push(i);
            }
        }
    }

    return false;
}

//finds the shortest path between two persons
//returns the persons in this path as a vector
vector<Person> Graph::BFS(string& from, string& to) {
    queue<string> q;
    set<string> visited;
    vector<Person> path;

    visited.insert(from);
    q.push(from);

    unordered_map<string, int> distance;
    unordered_map<string, string> prev;

    distance[from] = INT_MAX;
    prev[from] = "";


    while (!q.empty()) {
        string p = q.front();
        q.pop();

        if (p == to) {
            break;
        }

        set<string> neighbors = this->adjList->at(p);

        for (string i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                q.push(i);
                distance[i] = distance[p] + 1;
                prev[i] = p;
            }
        }
    }

    string s = to;
    path.push_back(m->at(s));
    
    while (prev[s] != "") {
        path.push_back(m->at(prev[s]));
        s = prev[s];
    }

    return path;
}

//determines whether a path exists in graph between two persons
bool Graph::DFS(string& from, string& to) {
    stack<string> stk;
    set<string> visited;

    visited.insert(from);
    stk.push(from);

    int verticesTraversed = 0;

    while (!stk.empty()) {
        string p = stk.top();
        stk.pop();

        if (p == to) {
            return true;
        }

        set<string> neighbors = this->adjList->at(p);

        for (string i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                stk.push(i);
            }
        }
    }

    return false;
}