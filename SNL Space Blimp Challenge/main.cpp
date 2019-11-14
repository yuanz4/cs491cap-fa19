#include <bits/stdc++.h>

using namespace std;

typedef vector<double> vi;

vector<string> split_string(string);
const double error = 0.1;


int main()
{
    string detections_per_frameNum_frames_temp;
    getline(cin, detections_per_frameNum_frames_temp);

    vector<string> detections_per_frameNum_frames = split_string(detections_per_frameNum_frames_temp);

    int detections_per_frame = stoi(detections_per_frameNum_frames[0]);

    int num_frames = stoi(detections_per_frameNum_frames[1]);

    vector<vector<float>> detection_components(num_frames);
    for (int i = 0; i < num_frames; i++) {
        detection_components[i].resize(2 * detections_per_frame);

        for (int j = 0; j < 2 * detections_per_frame; j++) {
            cin >> detection_components[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vi> ret(detections_per_frame, vi(num_frames, 0));
    for (int i = 0; i < detections_per_frame; i++) {
    	double firstX = detection_components[0][2*i];
    	double firstY = detection_components[0][2*i+1];
    	ret[i][0] = ;
    	for (int j = 0; j < detections_per_frame; j++) {
    		double secondX = detection_components[1][2*j];
    		double secondY = detection_components[1][2*j+1];
    		double speedX = secondX - firstX;
    		double speedY = secondY - firstY;
    		double prevX = secondX;
    		double prevY = secondY;
    		for (int k = 2; k < num_frames; k++) {
    			for (int l = 0; l < detections_per_frame; l++) {
    				double curX = detection_components[k][2*l];
    				double curY = detection_components[k][2*l+1];
    				if (abs(curX-preX)/curX < error && abs(curY-preY)/curY < error) {

    				}
    			}
    		}
    	}
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    
    return splits;
}
