#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
using namespace std;
class Movie {
    int movieId;
    string title, language;
    int duration;
public:
    Movie(int id, string t, string l, int d)
        : movieId(id), title(t), language(l), duration(d) {}
    void displayDetails() const {
        cout << "\nMovie: " << title
             << "\nLanguage: " << language
             << "\nDuration: " << duration << " minutes\n";
    }
    string getTitle() const {
        return title;
    }
};
#endif