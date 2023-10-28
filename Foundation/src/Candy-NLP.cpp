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

vector<string> cn_stop_word_remove(const string& text) {
    unordered_set<string> stop_words = { "indeed", "they", "in", "fifty", "'re", "herein", "make", "third", "itself",
                                  "thence", "many", "whereafter", "then", "forty", "does", "along", "between",
                                  "whereby", "he", "still", "above", "someone", "'re", "out", "not", "she", "'s",
                                  "anything", "first", "anyone", "five", "latterly", "several", "front", "bottom",
                                  "wherever", "'re", "sometimes", "show", "go", "have", "anyhow", "with", "to", "as",
                                  "amount", "further", "anyway", "next", "always", "are", "these", "again", "from",
                                  "became", "hers", "may", "last", "whenever", "herself", "regarding", "'ve", "more",
                                  "any", "formerly", "its", "whole", "after", "beforehand", "our", "'ll", "'ve", "mostly",
                                  "his", "nobody", "everything", "whoever", "a", "except", "whither", "also", "seem", "'m",
                                  "never", "am", "but", "few", "now", "eleven", "us", "seems", "you", "beside", "under", "been",
                                  "had", "afterwards", "behind", "even", "take", "'d", "through", "nine", "we", "and",
                                  "before", "since", "yet", "her", "yourself", "how", "former", "some", "thru", "four", "ours",
                                  "n't", "nevertheless", "could", "at", "very", "should", "none", "once", "whence", "on", "serious",
                                  "else", "keep", "empty", "all", "rather", "somewhere", "n't", "their", "used", "against", "'m", "either",
                                  "by", "ever", "due", "moreover", "be", "well", "why", "elsewhere", "too", "which", "whom", "put", "re", "within",
                                  "into", "enough", "often", "throughout", "did", "everywhere", "if", "made", "will", "only",
                                  "yours", "please", "'ve", "than", "thereupon", "here", "such", "during", "full", "myself",
                                  "back", "my", "because", "was", "no", "ca", "every", "n't", "call", "cannot", "that", "so",
                                  "side", "nor", "hereby", "ourselves", "wherein", "whatever", "see", "who", "'ll", "done",
                                  "whereupon", "another", "besides", "name", "fifteen", "has", "various", "'s", "something",
                                  "nowhere", "twelve", "must", "onto", "become", "twenty", "somehow", "an", "latter", "him",
                                  "for", "over", "using", "the", "themselves", "other", "sixty", "unless", "one", "therefore",
                                  "hereupon", "together", "least", "might", "otherwise", "those", "when", "most", "upon", "toward",
                                  "each", "were", "amongst", "yourselves", "therein", "eight", "move", "becoming", "own", "already", "down",
                                  "hundred", "same", "himself", "really", "doing", "whose", "ten", "towards", "however", "seeming", "everyone",
                                  "of", "alone", "beyond", "via", "perhaps", "'ll", "less", "your", "across", "sometime", "i", "give", "or", "neither",
                                  "nothing", "though", "up", "hence", "without", "although", "off", "until", "much", "hereafter", "where", "thereafter",
                                  "noone", "becomes", "me", "thereby", "two", "top", "around", "namely", "would", "do", "'d", "this", "among", "them",
                                  "below", "whereas", "it", "mine", "thus", "about", "'d", "is", "what", "while", "'m", "part", "quite", "just", "can",
                                  "both", "say", "there", "per", "whether", "others", "almost", "'s", "meanwhile", "three", "being", "six", "seemed", "anywhere", "get"};

    vector<string> token_vector = cn_tokenizer(text);
    vector<string> filtered_vector;
    
    for (const string& word : token_vector) {
        for (const auto& element : stop_words) {
            
        }
    }

    return filtered_vector;
}












