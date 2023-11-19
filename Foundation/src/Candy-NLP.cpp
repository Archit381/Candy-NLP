#include "Candy-NLP.h"


bool isSpecialChar(char ch) {
    static string special_characters = "!@#$%^&*()_+{}[]:<>,.?~\\|";
    return (isspace(ch) || special_characters.find(ch) != string::npos);
}

vector<string> cn_tokenizer(const string& text) {
    vector<string> token_vector;
    string temp_word;

    for (char ch : text) {
        if (isSpecialChar(ch)) {
            if (!temp_word.empty()) {
                token_vector.push_back(temp_word);
                temp_word.clear();
            }
            if (ch != ' ') {
                token_vector.push_back(string(1, ch));
            }
        }
        else {
            temp_word += ch;
        }
    }

    if (!temp_word.empty()) {
        token_vector.push_back(temp_word);
    }

    return token_vector;
}

unordered_map<string,int> cn_token_counter(const vector<string>& token_vector) {
    unordered_map<string, int> token_map;

    for (string token : token_vector) {
        token_map[token]++;
    }

    return token_map;
}


vector<string> cleanText(string document) {
    
    vector<string> article;
    
    string sentence;

    for (char c : document) {
        if (c == '.') {
            
            article.push_back(sentence);
            sentence = "";

        }
        else {
            sentence = sentence + string(1, c);
        }
    }

    vector<string> sentences;

    for (const string& sentence : article) {
        string cleanedSentence = regex_replace(sentence, regex("[^a-zA-Z]"), " ");
        cleanedSentence = regex_replace(cleanedSentence, regex("\\s+"), " ");
        sentences.push_back(cleanedSentence);

    }

    return sentences;
}

vector<Sentence> Sentence_dict(string document) {

    vector<string> article;

    string sentence;

    for (char c : document) {
        if (c == '.') {

            article.push_back(sentence);
            sentence = "";

        }
        else {
            sentence = sentence + string(1, c);
        }
    }

    vector<Sentence> sentences;

    int id = 0;
    for (const string& sentence : article) {
        id++;
        string cleanedSentence = regex_replace(sentence, regex("[^a-zA-Z]"), " ");
        cleanedSentence = regex_replace(cleanedSentence, regex("\\s+"), " ");

        Sentence temp = { id,cleanedSentence };
        sentences.push_back(temp);

    }

    return sentences;

}


int cnt_words(const string& sent) {
    vector<string> words = cn_tokenizer(sent);
    return words.size();
}


vector<TextData> cnt_i_sent(const vector<string>& sentences) {
    vector<TextData> txt_data;
    int id = 0;

    for (const string& sent : sentences) {
        id++;
        int wordCount = cnt_words(sent);
        TextData temp = { id, wordCount };
        txt_data.push_back(temp);
    }

    return txt_data;
}



vector<frequency> freq_data(const vector<string>& sentences) {
    int id = 0;

    vector<frequency> freq_list;

    for (const string& sent : sentences) {
        id++;

        map<string, int> freq_dict;
        
        vector<string> words = cn_tokenizer(sent);

        for (string word : words) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (freq_dict.find(word) != freq_dict.end()) {
                freq_dict[word]++;
            }
            else {
                freq_dict[word] = 1;
            }
        }

        frequency temp = { id, freq_dict };

        freq_list.push_back(temp);
    }

    return freq_list;
}

vector<term_frequency> calc_TF(vector<TextData> txt_list, vector<frequency> freq_list) {
    vector<term_frequency> tf_scores;

    for (const frequency& data : freq_list) {

        int ID = data.id;

        for (const auto& pair : data.freq_dict) {
           
            double score = static_cast<double>(pair.second) / txt_list[ID - 1].word_cnt;
            
            term_frequency temp = { data.id,score, pair.first };
            tf_scores.push_back(temp);
        }

    }
    return tf_scores;
}


vector<inverse_frequency> calc_IDF(vector<TextData> txt_list, vector<frequency> freq_list) {
    vector<inverse_frequency> idf_scores;
    int cnt = 0;

    for (const frequency& item : freq_list) {
        cnt++;
        for (const auto& pair : item.freq_dict) {
            int val = 0;
            

            for (const frequency& k : freq_list) {
                if (k.freq_dict.find(pair.first)!=k.freq_dict.end()) {
                    val++;
                }
            }

            double result = log(static_cast<double>(txt_list.size()) / (val + 1));
            inverse_frequency temp = { cnt,result,pair.first };
            idf_scores.push_back(temp);
        }

    }
    return idf_scores;
}


vector<tfidf> calc_TFIDF(vector<term_frequency> tf_scores, vector<inverse_frequency> idf_scores) {
    vector<tfidf> tfidf_scores;

    for (const inverse_frequency& data : idf_scores) {
        for (const term_frequency& pair : tf_scores) {
            if (data.key == pair.key and data.id == pair.id) {
                tfidf temp = { data.id,data.idf_score * pair.tf_score,data.key };

                tfidf_scores.push_back(temp);
            }
        }
    }
    return tfidf_scores;
}
    
vector<SentenceData> sent_scores(const vector<tfidf>& tfidf_scores, const vector<TextData>& text_data) {
    vector<SentenceData> sent_data;

    for (const TextData& txt : text_data) {
        double score = 0;  

        for (const tfidf& t_dict : tfidf_scores) {
            if (txt.id == t_dict.id) {
                score += t_dict.tfidf_score;
            }
        }

        SentenceData temp = { txt.id, score };
        sent_data.push_back(temp);
    }

    return sent_data;

}

string summariser(vector<SentenceData> sent_data, vector<Sentence> sentences_dict) {
    double cnt = 0;
    vector<string> summary;

    for (const SentenceData& item : sent_data) {
        cnt = cnt + item.score;
    }

    double avg = cnt / sent_data.size();

    for (const SentenceData& data : sent_data) {
        if (data.score >= (avg * 0.9)) {
            for (const Sentence& sentence : sentences_dict) {
                if (data.id == sentence.id) {
                    summary.push_back(sentence.sentence);
                    break;
               }
            }
        }
    }

    string joined_summary;

    for (const string& str : summary) {
        joined_summary += str;

        if (&str != &summary.back()) {
            joined_summary += ". ";
        }
    }

    return joined_summary;
}







































