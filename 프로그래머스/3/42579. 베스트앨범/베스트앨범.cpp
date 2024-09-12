#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool cmpPlays(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

bool cmpGenres(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genrePlays;
    map<string, vector<pair<int, int>>> songList;
    
    for (int i = 0; i < genres.size(); i++) {
        genrePlays[genres[i]] += plays[i];
        songList[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    vector<pair<string, int>> sortedGenres(genrePlays.begin(), genrePlays.end());
    sort(sortedGenres.begin(), sortedGenres.end(), cmpGenres);
    
    for (auto genre : sortedGenres) {
        string genreName = genre.first;

        vector<pair<int, int>> songs = songList[genreName];
        sort(songs.begin(), songs.end(), cmpPlays);

        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }
    
    
    return answer;
}