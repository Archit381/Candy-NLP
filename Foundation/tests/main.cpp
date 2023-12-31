﻿#include "Candy-NLP.h"

int main() {
	string input_1 = "There are many variations they'll of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.";
	string input_2 = "Contrary to popular belief, Lorem Ipsum is not simply random text.It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old.Richard McClintock, a Latin professor at Hampden - Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source.Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of 'de Finibus Bonorum et Malorum' (The Extremes of Good and Evil) by Cicero, written in 45 BC.This book is a treatise on the theory of ethics, very popular during the Renaissance.The first line of Lorem Ipsum, 'Lorem ipsum dolor sit amet..', comes from a line in section 1.10.32.There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable.If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text.All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet.It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable.The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non - characteristic words etc.";
	string input_3 = "Report on ClassificaƟon Analysis' 'Main ObjecƟve The main objecƟve of this analysis is to build a classificaƟon model for predicƟng the 'ClassificaƟon' of individuals based on their health - related aƩributes.The primary focus is on predicƟon, and the benefits of this analysis include enabling early idenƟficaƟon of health classificaƟons, which could aid in targeted intervenƟons or treatment plans.' 'Data DescripƟon The dataset used for this analysis is sourced from 'dataR2.xlsx' and contains healthrelated aƩributes of 116 individuals.The dataset consists of the following columns : Age, BMI, Glucose, Insulin, HOMA, LepƟn, AdiponecƟn, ResisƟn, MCP.1, and ClassificaƟon.The 'ClassificaƟon' column indicates whether an individual belongs to Class 1 or Class 2, which could represent different health condiƟons.' 'Data ExploraƟon and Cleaning 1. The data was loaded into a Pandas DataFrame. 2. A preliminary exploraƟon showed that there were no missing values in the dataset. 3. Feature selecƟon was performed using the Chi - Square test, and columns with significant p - values were retained. 4. The 'ClassificaƟon' column was modified to have binary values(0 and 1) instead of 1 and 2, for classificaƟon purposes. 5. The dataset was split into training and tesƟng sets.' 'Classifier Models Three different classifier models were trained and evaluated : 1. Decision Tree Classifier(Default) : The iniƟal Decision Tree classifier showed moderate performance with an accuracy of approximately 66.67 % .It was trained with default hyperparameters. 2. Decision Tree Classifier(Entropy Criterion) : Another Decision Tree classifier was trained using the entropy criterion, resulƟng in similar performance with an accuracy of approximately 66.67 % .The log loss was also calculated for this model, yielding a value of 12.01. 3. Grid Search with Decision Tree Classifier : A grid search was performed to find the best hyperparameters for a Decision Tree classifier.The best model had a max depth of 10, max features of 'sqrt,' and min samples split of 8. This model achieved an accuracy of 62.5 % .' 'RecommendaƟon Among the three classifier models, the Decision Tree Classifier with the entropy criterion and the grid search - tuned Decision Tree Classifier both had similar performance in terms of accuracy(66.67 %).However, considering the goal of the analysis, which is to predict health classificaƟons, the model's explainability is crucial. Therefore, I recommend using the Decision Tree Classifier with the entropy criterion. It provides a balance between accuracy and interpretability.' 'Key Findings and Insights' 'Glucose, Insulin, HOMA, ResisƟn, and MCP.1 were idenƟfied as important features for classificaƟon based on the Chi-Square test.' 'The Decision Tree models indicate that these features play a significant role in predicƟng health classificaƟons.' 'The classificaƟon model can idenƟfy individuals at risk of different health condiƟons based on these aƩributes.' 'Next Steps' 'Further data collecƟon: Consider gathering addiƟonal data, such as lifestyle factors, medical history, and geneƟc informaƟon, to improve the accuracy of health classificaƟon.' 'Feature engineering: Explore creaƟng new features or interacƟons between exisƟng features to enhance model performance.' 'Model interpretaƟon: InvesƟgate the decision rules of the Decision Tree classifier to gain insights into the factors influencing health classificaƟons.' 'Ensemble methods: Experiment with ensemble models like Random Forest or Gradient BoosƟng to potenƟally improve predicƟon accuracy.' 'In conclusion, this analysis provides a foundaƟon for predicƟng health classificaƟons based on healthrelated aƩributes. The Decision Tree Classifier with the entropy criterion is recommended for its balance between accuracy and explainability. Further refinements and addiƟonal data may lead to more accurate and acƟonable predicƟons.";

	string story_1 = "Once in a quaint village, there lived a young girl named Lily who had an extraordinary gift—she could make plants grow with her touch. Her hands had the magic to bring life to withering flowers and barren soil. However, Lily was shy and kept her gift a secret. One day, a severe drought struck the village, and the crops withered away. Desperation filled the air. In a bold move, Lily decided to reveal her gift. She touched the parched fields, and within moments, vibrant green sprouts emerged. The villagers were awe-struck, and from that day on, Lily's touch brought hope and prosperity to her village.";
	string story_2 = "Once upon a time in a quaint village, a curious cat named Whiskers discovered a mysterious, ancient book hidden beneath a dusty attic floorboard. The book contained magical spells and secrets about a hidden treasure. With newfound excitement, Whiskers embarked on a thrilling adventure. Guided by the book's cryptic clues, he journeyed through dark forests, crossed treacherous rivers, and faced cunning challenges. Along the way, he formed an unlikely alliance with a wise owl named Hoot. Together, they unraveled the enigma, and at last, they found the hidden chest filled with dazzling gems and radiant dreams. They returned to the village as heroes, their bond forever unbreakable.";

	vector<string> tokens = cn_tokenizer(input_1);

	// TOKENIZATION TEST:

	for (string token : tokens) {
		cout << token << "-";
	}
	cout << endl;

	cout << tokens.size() << endl;

	unordered_map<string, int> token_map = cn_token_counter(tokens);
	
	//TOKEN_COUNT TEST:

	for (const auto& pair : token_map) {
		cout << "key: " << pair.first << ", Value: " << pair.second << endl;
	}


	vector<string> sentences = cleanText(story_1);

	for (string sentence: sentences) {
		cout << sentence << endl;
	}

	vector<Sentence> sentences_dict = Sentence_dict(story_1);
	
	for (const Sentence& item : sentences_dict) {
		cout << item.id <<". " <<item.sentence << endl;
	}


	vector<TextData> txt_data = cnt_i_sent(sentences);

	for (const TextData& data : txt_data) {
		cout << "Sentence " << data.id << " has " << data.word_cnt << " words." << endl;
	}


	vector<frequency> freq_Data = freq_data(sentences);

	for (const frequency& data : freq_Data) {
		cout << "Sentence no: " << data.id << endl;
		for (const auto& pair : data.freq_dict) {
			cout << pair.first << ':' << pair.second << endl;
		}
	}

	vector<term_frequency> tf_scores = calc_TF(txt_data,freq_Data);

	for (const term_frequency& data : tf_scores) {
		cout << data.id << " " << data.key << " " << data.tf_score << endl;
	}

	vector<inverse_frequency> idf_scores = calc_IDF(txt_data, freq_Data);

	for (const inverse_frequency& data : idf_scores) {
		cout << data.id << " " << data.key << " " << data.idf_score << endl;
	}

	vector<tfidf> tfidf_scores = calc_TFIDF(tf_scores,idf_scores);

	for (const tfidf& data : tfidf_scores) {
		cout << data.id << " " << data.key << " " << data.tfidf_score << endl;
	}

	vector<SentenceData> sent_data = sent_scores(tfidf_scores, txt_data);

	for (const SentenceData& data : sent_data) {
		cout << data.id << " " << data.score << " " << endl;

	}
	
	string summary = summariser(sent_data, sentences_dict);

	cout << summary << endl;


	
	// ------------------------------BENCHMARKING SECTION---------------------------------------------------------------------------------------



	const int num_iterations = 10000;

	chrono::steady_clock::time_point start_time = chrono::steady_clock::now();

	// FUNCTION BENCHMARK
	
	for (int i = 0; i < num_iterations; ++i) {
		string summary = summariser(sent_data, sentences_dict);
	}
	

	chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
	chrono::microseconds elapsed_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

	cout << "Average time per iteration: " << elapsed_time.count() / num_iterations << " microseconds" << endl;

	return 0;
}