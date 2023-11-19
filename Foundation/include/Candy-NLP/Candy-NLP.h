
#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <regex>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

struct TextData {
    int id;
    int word_cnt;
};

struct frequency {
    int id;
    map<string, int> freq_dict;
};

struct term_frequency {
    int id;
    double tf_score;
    string key;
};

struct inverse_frequency {
    int id;
    double idf_score;
    string key;
};

struct tfidf {
    int id;
    double tfidf_score;
    string key;
};

struct SentenceData {
    int id;
    double score;
};

struct Sentence {
    int id;
    string sentence;
};


vector<string> cn_tokenizer(const string& text);

unordered_map<string, int> cn_token_counter(const vector<string>& token_vector);

vector<string> cleanText(string document);

vector<Sentence> Sentence_dict(string document);

int cnt_words(const string& sent);

vector<TextData> cnt_i_sent(const vector<string>& sentences);

vector<frequency> freq_data(const vector<string>& sentences);

vector<term_frequency> calc_TF(vector<TextData> txt_data, vector<frequency> freq_Data);

vector<inverse_frequency> calc_IDF(vector<TextData> txt_list, vector<frequency> freq_list);

vector<tfidf> calc_TFIDF(vector<term_frequency> tf_scores, vector<inverse_frequency> idf_scores);

vector<SentenceData> sent_scores(const vector<tfidf>& tfidf_scores, const vector<TextData>& text_data);

string summariser(vector<SentenceData> sent_data, vector<Sentence> sentences_dict);
