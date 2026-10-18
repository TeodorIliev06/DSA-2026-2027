class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> frequency(256);

        for (char& ch : s) {
            frequency[ch].first++;
            frequency[ch].second = ch;
        }

        sort(frequency.begin(), frequency.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        string output;
        output.reserve(s.size());
        for (auto [count, ch] : frequency) {
            if (count == 0) {
                break;
            }

            output.append(count, ch);
        }

        return output;
    }
};
