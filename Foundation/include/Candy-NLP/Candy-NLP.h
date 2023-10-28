
#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> cn_tokenizer(const string& text);
unordered_map<string, int> cn_token_counter(const vector<string>& token_vector);
vector<string> cn_stop_word_remove(const string& text);

